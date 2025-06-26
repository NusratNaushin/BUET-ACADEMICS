#include <chrono>
#include <fstream>
#include <iostream>
#include <pthread.h>
#include <random>
#include <unistd.h>
#include <vector>
#include <semaphore.h>

#define SLEEP_MULTIPLIER 1000

pthread_mutex_t mutex;
sem_t LogBook;
int rc = 0;
sem_t intelligent_mutex;

sem_t typewritingstations[4];
int number_of_operatives;
int unit_size;
int document_recreation_relative_time;
int logbook_entry_relative_time;
int intelligence_staff_members = 2;

// Mutex lock for output to file for avoiding interleaving
pthread_mutex_t output_lock;

std::vector<int> unit_completion_count;
std::vector<bool> unit_recreation_complete;

int total_units;
int completed_operations = 0; // For logbook tracking
bool simulation_done = false;

// Timing functions
auto start_time = std::chrono::high_resolution_clock::now();

long long get_time()
{
  auto end_time = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
      end_time - start_time);
  return duration.count();
}

// Function to generate a Poisson-distributed random number
int get_random_number()
{
  static std::random_device rd;
  static std::mt19937 generator(rd());
  
  // Smaller lambda for more reasonable delays
  double lambda = 5.0;
  std::poisson_distribution<int> poissonDist(lambda);
  return poissonDist(generator);
}

enum operative_state
{
  DOCUMENT_RECREATION,
  WAITING_AT_THE_TS
};

class Operative
{
public:
  int operative_id;
  operative_state state;
  int writing_time;
  int unit_id;
  int unit_leader;

  Operative(int id) : operative_id(id), writing_time(document_recreation_relative_time)
  {
    unit_id = (id - 1) / unit_size + 1;
    unit_leader = unit_id * unit_size;
  }

  bool isLeader()
  {
    return operative_id == unit_leader;
  }
};

void write_output(std::string output)
{
  pthread_mutex_lock(&output_lock);
  std::cout << output;
  pthread_mutex_unlock(&output_lock);
}

std::vector<Operative> operatives;

void *writerUnitLeader(void *arg)
{
  Operative *operative = (Operative *)arg;
  
  // Wait for exclusive access to logbook
  sem_wait(&LogBook);
  
  int unit_id = operative->unit_id;
  
  // Logbook entry
  usleep(logbook_entry_relative_time * SLEEP_MULTIPLIER);
  
  pthread_mutex_lock(&mutex);
  completed_operations++;
  pthread_mutex_unlock(&mutex);
  
  write_output("Unit " + std::to_string(unit_id) +
               " has completed intelligence distribution at time " + 
               std::to_string(get_time()) + "\n");
  
  sem_post(&LogBook);
  
  return NULL;
}

void *document_recreation(Operative *operative, int station_idx)
{
  operative->state = DOCUMENT_RECREATION;
  
  usleep(operative->writing_time * SLEEP_MULTIPLIER);
  write_output("Operative " + std::to_string(operative->operative_id) +
               " has completed document recreation at time " + 
               std::to_string(get_time()) + "\n");
  
  sem_post(&typewritingstations[station_idx]);
  
  // Update unit completion count
  pthread_mutex_lock(&mutex);
  unit_completion_count[operative->unit_id]++;
  
  // Check if all unit members have completed
  if (unit_completion_count[operative->unit_id] == unit_size && 
      !unit_recreation_complete[operative->unit_id]) {
    unit_recreation_complete[operative->unit_id] = true;
    write_output("Unit " + std::to_string(operative->unit_id) +
                 " has completed document recreation phase at time " + 
                 std::to_string(get_time()) + "\n");
  }
  pthread_mutex_unlock(&mutex);
  
  // If leader, wait for all unit members then go to logbook
  if (operative->isLeader()) {
    // Wait for all unit members to complete
    while (true) {
      pthread_mutex_lock(&mutex);
      if (unit_completion_count[operative->unit_id] == unit_size) {
        pthread_mutex_unlock(&mutex);
        break;
      }
      pthread_mutex_unlock(&mutex);
      usleep(1000); // Wait 10ms before checking again
    }
    
    pthread_t unit_leader_thread;
    pthread_create(&unit_leader_thread, NULL, writerUnitLeader, operative);
    pthread_join(unit_leader_thread, NULL);
  }
  
  // Check if simulation is done
  pthread_mutex_lock(&mutex);
  if (completed_operations == total_units) {
    simulation_done = true;
  }
  pthread_mutex_unlock(&mutex);
  
  return NULL;
}

void *station_arrival(void *arg)
{
  Operative *operative = (Operative *)arg;
  
  int delay = get_random_number();
  usleep(delay * SLEEP_MULTIPLIER);
  
  // Fixed station assignment formula
  int station_index = (operative->operative_id - 1) % 4;
  
  write_output("Operative " + std::to_string(operative->operative_id) +
               " has arrived at typewriting station at time " +
               std::to_string(get_time()) + "\n");
  
  sem_wait(&typewritingstations[station_index]);
  operative->state = WAITING_AT_THE_TS;
  
  document_recreation(operative, station_index);
  return NULL;
}


void *readerIntelligentStaff(void *arg)
{
  int staff_id = *(int*)arg;
  
  while (!simulation_done) {
    // Random delay between readings
    int delay = get_random_number() + 1;
    usleep(delay * SLEEP_MULTIPLIER);
    
    if (simulation_done) break;
    
    // Reader entry
    sem_wait(&intelligent_mutex);
    rc++;
    if (rc == 1) {
      sem_wait(&LogBook);
    }
    sem_post(&intelligent_mutex);
    
    // Read logbook
    pthread_mutex_lock(&mutex);
    int ops = completed_operations;
    pthread_mutex_unlock(&mutex);
    
    write_output("Intelligence Staff " + std::to_string(staff_id) +
                 " began reviewing logbook at time " + std::to_string(get_time()) + 
                 ". Operations completed = " + std::to_string(ops) + "\n");
    
    // Simulate reading time
    usleep((500 + get_random_number() % 1000) * SLEEP_MULTIPLIER);
    
    // Reader exit
    sem_wait(&intelligent_mutex);
    rc--;
    if (rc == 0) {
      sem_post(&LogBook);
    }
    sem_post(&intelligent_mutex);
    
    // Break if all operations completed
    if (ops >= total_units) {
      break;
    }
  }
  return NULL;
}

void initialize()
{
  for (int i = 0; i < 4; i++) {
    sem_init(&typewritingstations[i], 0, 1);
  }
  
  sem_init(&LogBook, 0, 1);
  sem_init(&intelligent_mutex, 0, 1);
  pthread_mutex_init(&mutex, NULL);
  
  for (int i = 1; i <= number_of_operatives; i++) {
    operatives.emplace_back(Operative{i});
  }
  
  total_units = (number_of_operatives + unit_size - 1) / unit_size;
  unit_completion_count.resize(total_units + 1, 0);
  unit_recreation_complete.resize(total_units + 1, false);
  
  pthread_mutex_init(&output_lock, NULL);
  start_time = std::chrono::high_resolution_clock::now();
}

int main(int argc, char *argv[])
{
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << std::endl;
    return 1;
  }
  
  std::ifstream inputFile(argv[1]);
  std::ofstream outputFile(argv[2]);
  
  if (!inputFile.is_open() || !outputFile.is_open()) {
    std::cerr << "Error opening files!" << std::endl;
    return 1;
  }
  
  std::streambuf *cinBuffer = std::cin.rdbuf();
  std::streambuf *coutBuffer = std::cout.rdbuf();
  std::cin.rdbuf(inputFile.rdbuf());
  std::cout.rdbuf(outputFile.rdbuf());
  
  std::cin >> number_of_operatives >> unit_size;
  std::cin >> document_recreation_relative_time >> logbook_entry_relative_time;
  
  initialize();
  
  pthread_t operatives_threads[number_of_operatives];
  pthread_t intelligent_staff_threads[intelligence_staff_members];
  int staff_ids[2] = {1, 2};
  
  // Create intelligence staff threads
  for (int i = 0; i < intelligence_staff_members; i++) {
    pthread_create(&intelligent_staff_threads[i], NULL, readerIntelligentStaff, &staff_ids[i]);
  }
  
  // Create operative threads with random delays
  for (int i = 0; i < number_of_operatives; i++) {
    pthread_create(&operatives_threads[i], NULL, station_arrival, &operatives[i]);
    usleep(100000); // Small delay between thread creation
  }
  
  // Wait for all operative threads
  for (int i = 0; i < number_of_operatives; i++) {
    pthread_join(operatives_threads[i], NULL);
  }
  
  // Wait a bit for staff threads to finish
  sleep(2);
  simulation_done = true;
  
  // Clean up
  for (int i = 0; i < 4; i++) {
    sem_destroy(&typewritingstations[i]);
  }
  sem_destroy(&LogBook);
  sem_destroy(&intelligent_mutex);
  pthread_mutex_destroy(&mutex);
  pthread_mutex_destroy(&output_lock);
  
  std::cin.rdbuf(cinBuffer);
  std::cout.rdbuf(coutBuffer);
  
  return 0;
}
#include <chrono>
#include <fstream>
#include <iostream>
#include <pthread.h>
#include <random>
#include <unistd.h>
#include <vector>
#include <semaphore.h>

#define DOCUMENT_RECREATION_TIME 10
#define SLEEP_MULTIPLIER 1000

pthread_mutex_t mutex ;
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
std::vector<bool> leader_goes_to_IntelliHUB;

int total_units;
int completed_operations = 0;
bool all_logs_done = false;
// Timing functions
auto start_time = std::chrono::high_resolution_clock::now();

/**
 * Get the elapsed time in milliseconds since the start of the simulation.
 * @return The elapsed time in milliseconds.
 */
long long get_time()
{
  auto end_time = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
      end_time - start_time);
  long long elapsed_time_ms = duration.count();
  return elapsed_time_ms;
}

// Function to generate a Poisson-distributed random number
int get_random_number()
{
  std::random_device rd;
  std::mt19937 generator(rd());

  // Lambda value for the Poisson distribution
  double lambda = 10000.234;
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
std::vector<Operative> operatives;

void write_output(std::string output)
{
  pthread_mutex_lock(&output_lock);
  std::cout << output;
  pthread_mutex_unlock(&output_lock);
}

void *writerUnitLeader(void *arg)
{

  Operative *operative = (Operative *)arg;
  sem_wait(&LogBook);
  int unit_id = operative->unit_id;
    usleep(logbook_entry_relative_time * SLEEP_MULTIPLIER);

  pthread_mutex_lock(&mutex);
    completed_operations++;
  pthread_mutex_unlock(&mutex);

  
  write_output("Unit leader of unit " + std::to_string(unit_id) +
               " has completed intelligence distribution at time " + std::to_string(get_time()) + " ms\n");
  sem_post(&LogBook);

  return NULL;
}

void *document_recreation(Operative *operative, int station_idx)
{

  operative->state = DOCUMENT_RECREATION;

  usleep(operative->writing_time * SLEEP_MULTIPLIER);
  write_output("Operative " + std::to_string(operative->operative_id) +
               " has completed document recreation at time " + std::to_string(get_time()) + " ms\n");

  sem_post(&typewritingstations[station_idx]);
pthread_mutex_lock(&mutex);
  unit_completion_count[operative->unit_id]++;

  if(unit_completion_count[operative->unit_id] == unit_size && !leader_goes_to_IntelliHUB[operative->unit_id])
  {
    leader_goes_to_IntelliHUB[operative->unit_id] = true;
    write_output("Unit " + std::to_string(operative->unit_id) +
                 " has completed document recreation phase at time " + 
                 std::to_string(get_time()) + "\n");
  }

  pthread_mutex_unlock(&mutex);
  
  if (operative->isLeader())
  {
    while (true) {
      pthread_mutex_lock(&mutex);
      if (unit_completion_count[operative->unit_id] == unit_size ) {
        pthread_mutex_unlock(&mutex);
        break;
      }
      pthread_mutex_unlock(&mutex);
      usleep(2 * SLEEP_MULTIPLIER); 
    }

    pthread_t unit_leader_thread;
    pthread_create(&unit_leader_thread, NULL, writerUnitLeader, operative);
    pthread_join(unit_leader_thread, NULL);
  }
    pthread_mutex_lock(&mutex);

   if(completed_operations == total_units){

      all_logs_done = true;
   }
   pthread_mutex_unlock(&mutex);

  
  return NULL;
}
void *station_arrival(void *arg)
{

  Operative *operative = (Operative *)arg;

  int delay = get_random_number() % 5;

  usleep(delay * SLEEP_MULTIPLIER);
  int station_index = (operative->operative_id-1) % 4;
  write_output("Operative " + std::to_string(operative->operative_id) +
               " has arrived at typewriting station TS-" + std::to_string(station_index + 1) + " at time " +
               std::to_string(get_time()) + " ms\n");
  sem_wait(&typewritingstations[station_index]);
  operative->state = WAITING_AT_THE_TS;


  document_recreation(operative, station_index);
  return NULL;
}
void *readerIntelligentStaff(void *arg)
{

  // std::cout << "abcd" << std::endl;
  int staff_id =  *(int*)arg;
  // std::cout<<"baaler all log"<<all_logs_done<<std::endl;
  while (true)
  {

    // std::cout << "efgh" << std::endl;
    //int delay = get_random_number()+1;
    usleep(2*SLEEP_MULTIPLIER);
    pthread_mutex_lock(&mutex);
    int ops = completed_operations;
    pthread_mutex_unlock(&mutex);


    sem_wait(&intelligent_mutex);
    rc=rc+1;

    if(rc==1){

      sem_wait(&LogBook);

    }
    sem_post(&intelligent_mutex);


    
    write_output("Intelligence Staff " + std::to_string(staff_id) +
                 " began reviewing logbook at time " + std::to_string(get_time()) + 
                 ". Operations completed = " + std::to_string(ops) + "\n");
    
    usleep(2*SLEEP_MULTIPLIER);

    sem_wait(&intelligent_mutex);
    rc=rc-1;
    if(rc==0){
      sem_post(&LogBook);

    }
    sem_post(&intelligent_mutex);


  }
  return NULL;
}



void initialize()
{


  for (int i = 0; i < 4; i++)
  {
    sem_init(&typewritingstations[i], 0, 1);
  }

  sem_init(&LogBook, 0, 1);
  sem_init(&intelligent_mutex, 0, 1);
  pthread_mutex_init(&mutex, NULL);
  for (int i = 1; i <= number_of_operatives; i++)
  {
    operatives.emplace_back(Operative{i});
  }


    total_units = (number_of_operatives + unit_size - 1) / unit_size;
  unit_completion_count.resize(total_units + 1, 0);
  leader_goes_to_IntelliHUB.resize(total_units + 1, false);

  // Initialize mutex lock
  pthread_mutex_init(&output_lock, NULL);

  start_time = std::chrono::high_resolution_clock::now(); // Reset start time
}

int main(int argc, char *argv[])
{

  std::ifstream inputFile(argv[1]);
  std::streambuf *cinBuffer = std::cin.rdbuf(); // Save original std::cin buffer
  std::cin.rdbuf(inputFile.rdbuf());            // Redirect std::cin to input file

  std::ofstream outputFile(argv[2]);
  std::streambuf *coutBuffer = std::cout.rdbuf(); // Save original cout buffer
  std::cout.rdbuf(outputFile.rdbuf());            // Redirect cout to output file

  std::cin >> number_of_operatives >> unit_size;
  std::cin >> document_recreation_relative_time >> logbook_entry_relative_time;
  initialize();

  pthread_t operatives_threads[number_of_operatives];
  pthread_t intelligent_staff_threads[intelligence_staff_members];
  int staff_ids[2] = {1, 2};

  // std::cout<<"help"<<std::endl;

  for (int i = 0; i < intelligence_staff_members; i++)
  {

    pthread_create(&intelligent_staff_threads[i], NULL, readerIntelligentStaff,&staff_ids[i]);
  }

    // std::cout<<"help pls"<<std::endl;

  int remaining_operatives = number_of_operatives;
  std::vector<bool> started(number_of_operatives, false);

  while (remaining_operatives)
  {
    int randomOperative = get_random_number() % number_of_operatives;
    if (!started[randomOperative])
    {
      started[randomOperative] = true;
      pthread_create(&operatives_threads[randomOperative], NULL, station_arrival,
                     &operatives[randomOperative]);
      remaining_operatives--;
      usleep(1000); // sleep for 1 ms
      if (get_time() >
          7000)
      { // if more than 7 seconds is passed, initialize the rest
        break;
      }
    }
  }

  for (int i = 0; i < number_of_operatives; i++) {
      if (started[i]) {
          pthread_join(operatives_threads[i], NULL);
      }
  }



  all_logs_done = true;



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
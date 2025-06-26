#include <chrono>
#include <fstream>
#include <iostream>
#include <pthread.h>
#include <random>
#include <unistd.h>
#include <vector>
#include<semaphore.h>

#define DOCUMENT_RECREATION_TIME 10
#define SLEEP_MULTIPLIER 1000


sem_t typewritingstations[4];
int number_of_operatives ;
int unit_size;
int document_recreation_relative_time;
int logbook_entry_relative_time;
int intelligence_staff_member = 2;
// Mutex lock for output to file for avoiding interleaving
pthread_mutex_t output_lock;

// Timing functions
auto start_time = std::chrono::high_resolution_clock::now();

/**
 * Get the elapsed time in milliseconds since the start of the simulation.
 * @return The elapsed time in milliseconds.
 */
long long get_time() {
  auto end_time = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
      end_time - start_time);
  long long elapsed_time_ms = duration.count();
  return elapsed_time_ms;
}

// Function to generate a Poisson-distributed random number
int get_random_number() {
  std::random_device rd;
  std::mt19937 generator(rd());

  // Lambda value for the Poisson distribution
  double lambda = 10000.234;
  std::poisson_distribution<int> poissonDist(lambda);
  return poissonDist(generator);
}

enum operative_state {DOCUMENT_RECREATION , WAITING_AT_THE_TS};
class Operative {

    public :
    int operative_id ;
    operative_state state;
    int writing_time;
    int unit_id;
    int unit_leader;

    Operative(int id) : operative_id(id), writing_time(document_recreation_relative_time) {}

};

void write_output(std::string output) {
  pthread_mutex_lock(&output_lock);
  std::cout << output;
  pthread_mutex_unlock(&output_lock);
}

std::vector<Operative> operatives;

void *document_recreation(Operative *operative,int station_idx){

    operative->state = DOCUMENT_RECREATION;

    usleep(operative->writing_time * SLEEP_MULTIPLIER); 
    write_output("Operative " + std::to_string(operative->operative_id) +
               " has completed document recreation at time " + std::to_string(get_time()) + " ms\n");

    sem_post(&typewritingstations[station_idx]);
    return NULL;

}
void *station_arrival(void *arg){

    Operative *operative = (Operative *)arg;
    int station_index = operative->operative_id % 4;

    sem_wait(&typewritingstations[station_index]);
    operative->state = WAITING_AT_THE_TS;

    write_output("Operative " + std::to_string(operative->operative_id) +
               " has arrived at typewriting station TS-" + std::to_string(station_index+1)+ " at time " +
               std::to_string(get_time()) + " ms\n");

    document_recreation(operative, station_index);
    return NULL;
}



void initialize() {

    for (int i = 0; i < 4; i++) {
    sem_init(&typewritingstations[i], 0, 1);
  }

  for (int i = 1; i <= number_of_operatives; i++) {
    operatives.emplace_back(Operative{i});
  }
  
  // Initialize mutex lock
  pthread_mutex_init(&output_lock, NULL);

  start_time = std::chrono::high_resolution_clock::now(); // Reset start time
}

int main(int argc, char *argv[]){


  std::ifstream inputFile(argv[1]);
    std::streambuf *cinBuffer = std::cin.rdbuf(); // Save original std::cin buffer
    std::cin.rdbuf(inputFile.rdbuf()); // Redirect std::cin to input file

    std::ofstream outputFile(argv[2]);
    std::streambuf *coutBuffer = std::cout.rdbuf(); // Save original cout buffer
    std::cout.rdbuf(outputFile.rdbuf()); // Redirect cout to output file

    std::cin >> number_of_operatives >> unit_size;
    std::cin >> document_recreation_relative_time >> logbook_entry_relative_time;
        pthread_t operatives_threads[number_of_operatives];
    initialize();

    int remaining_operatives = number_of_operatives;
    std::vector<bool> started(number_of_operatives, false);

    while(remaining_operatives){
        int randomOperative = get_random_number() % number_of_operatives;
        if(!started[randomOperative]){
            started[randomOperative] = true;
            pthread_create(&operatives_threads[randomOperative], NULL, station_arrival,
                     &operatives[randomOperative]);
            remaining_operatives--;
            usleep(1000); // sleep for 1 ms
            if (get_time() >
                7000) { // if more than 7 seconds is passed, initialize the rest
                break;
            }
        }
    }

      for (int i = 0; i < number_of_operatives; i++) {
        if (!started[i]) {
          pthread_create(&operatives_threads[i], NULL, station_arrival,
                         &operatives[i]);
        }
      }

  
      for (int i = 0; i < number_of_operatives; i++) {
        pthread_join(operatives_threads[i], NULL);
    }


      std::cin.rdbuf(cinBuffer);
  std::cout.rdbuf(coutBuffer);

    
  }
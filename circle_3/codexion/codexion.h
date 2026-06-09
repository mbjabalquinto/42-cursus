#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

typedef struct s_coder t_coder; //fordward declaration.
// General structure
typedef struct s_data
{
    int number_of_coders;
    size_t time_to_burnout;
    size_t time_to_compile;
    size_t time_to_debug;
    size_t time_to_refactor;
    int number_of_compiles_required;
    int dongle_cooldown;
    int is_edf;  // fifo = 0 | edf = 1
    size_t global_start_time;
    size_t current_time;
    t_coder *coders;
    pthread_mutex_t *mutexes;
    pthread_mutex_t log_mutex;
    pthread_mutex_t flag_end;
    pthread_mutex_t queue_mutex;
    int simulation_end;
    t_priority_queue *queue;
}t_data;

// Programmer structure
typedef struct s_coder
{
    int id;
    int priority_value;
    pthread_t thread_id;
    int burnout;
    int compile_count;
    pthread_mutex_t *left_dongle;
    pthread_mutex_t *right_dongle;
    struct s_data *data;
    size_t last_compile_time;
}t_coder;

// Node to insert into the queue
typedef struct s_heap_node
{
    t_coder *coder;
    size_t priority; // Timestamp in FIFO, deadline in EDF.
}t_heap_node;

// The queue's structure
typedef struct s_priority_queue
{
    t_heap_node *array;
    int size; // How much coders are there on the queue right now.
}t_priority_queue;


int create_coders(t_data *args);
int free_mem(int i, pthread_mutex_t *mutexes, t_coder *coders);
int start_simulation(t_data *args);
int get_current_time();
void *coder_routine(void *arg);
void ft_usleep(size_t time_to_check, t_data *data);
int get_start_time(t_data *args);
int init_queue(t_data *args);

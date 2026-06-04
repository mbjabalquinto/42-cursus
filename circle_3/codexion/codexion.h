#include <pthread.h>

// General structure
typedef struct s_data
{
    int number_of_coders;
    int time_to_burnout;
    int time_to_compile;
    int time_to_debug;
    int time_to_refactor;
    int number_of_compiles_required;
    int dongle_cooldown;
    int is_edf;  // fifo = 0 | edf = 1
    int global_start_time;
    t_coder *coders;
    pthread_mutex_t *mutexes;
    pthread_mutex_t *log_mutex;
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
    struct s_data *data
}t_coder;

int create_coders(t_data *args);
int free_mem(int i, pthread_mutex_t *mutexes, t_coder *coders);

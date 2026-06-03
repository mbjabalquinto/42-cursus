typedef struct
{
    int number_of_coders;
    int time_to_burnout;
    int time_to_compile;
    int time_to_debug;
    int time_to_refactor;
    int number_of_compiles_required;
    int dongle_cooldown;
    char scheduler;
}arguments;

typedef struct
{
    int number;
    int priority_value;
    int pthread_t;
    int burnout;
    int compile_success;
    void *left_dongle;
    void *right_dongle;
}Min_Heap;

void    codexion(arguments *args);

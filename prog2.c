#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

    /* Change this variable to change number of increments that should happen */
#define SIZE 10000

struct this{
int x;
pthread_mutex_t lock;
}my_struct;


void inc_num(void){
    pthread_mutex_lock(&my_struct.lock);
    my_struct.x ++;
    pthread_mutex_unlock(&my_struct.lock);
    pthread_exit(NULL);
}

void inc_num_no(void){
    my_struct.x ++;
    pthread_exit(NULL);
}


pthread_t id[SIZE];

int main(){
    pthread_mutex_init(&my_struct.lock, NULL);

    void* (*func)(void*);
    func = inc_num;

    for(int c = 0; c < SIZE; c++){
        pthread_create(&(id[c]), NULL, func, NULL);
    }

    /*
       we must sleep for some time to allow all threads to execute and finish so
       we can see the results of the operations. NOTE: DONT change the printf format 
       testing script depend on it for extracting output to analyse.
    */
    sleep(1);   
    printf("[+] After finishing incrementing %d times x WITH locking is:    %d \n", SIZE, my_struct.x);

        /* Reset x */
    my_struct.x = 0;
    func = inc_num_no;
    for(int c = 0; c < SIZE; c++){
        pthread_create(&(id[c]), NULL, func, NULL);
    }
        
    sleep(1);
    printf("[+] After finishing incrementing %d times x WITHOUT locking is: %d \n", SIZE, my_struct.x);
}
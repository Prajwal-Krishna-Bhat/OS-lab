#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#define Num_Philosopher 5
#define Num_Chopsticks 5

void dine(int n);
pthread_t
philosopher[Num_Chopsticks];
pthread_mutex_t
chopstick[Num_Chopsticks];
int main(){
    int i,status_message;
    void *msg;
    for(i=1;i<=Num_Chopsticks;i++){
        status_message=pthread_mutex_init(&chopstick[i],NULL);
        if(status_message==-1){
            printf("\nMutex initialization failed");
            exit(1);
        }
    }
    for(i=1;i<=Num_Philosopher;i++){
        status_message=pthread_create(&philosopher[i],NULL,(void*)dine,(int*) i);
        if(status_message!=0){
            printf("\n Thread creation error\n");
            exit(1);
        }
    }
    for(i=1;i<=Num_Philosopher;i++){
        status_message=pthread_join(philosopher[i],&msg);
        if(status_message!=0){
            printf("\n Thread join failed\n");
            exit(1);
        }
    }
    for(i=1;i<=Num_Chopsticks;i++){
        status_message=pthread_mutex_destroy(&chopstick[i]);
        if(status_message!=0){
            printf("\n Mutex Destroyed\n");
            exit(1);
        }
    }
    return 0;
}
void dine(int n){
    printf("\nPhilosopher %d is thinking",n);
    pthread_mutex_lock(&chopstick[n]);
    pthread_mutex_lock(&chopstick[(n+1)%Num_Chopsticks]);
    printf("\nPhilosopher %d is eating",n);
    sleep(3);
    pthread_mutex_unlock(&chopstick[n]);
    pthread_mutex_unlock(&chopstick[(n+1)%Num_Chopsticks]);
    printf("\nPhilosopher %d finished eating",n);
}
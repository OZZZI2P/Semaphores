// C program to demonstrate working of Semaphores
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void* thread(void* arg)
{
	//wait
	sem_wait(&mutex);
	if (semaphore > 0)
{
    	//critical section
    printf("\nEntered..\n");
    sleep(3);
semaphore = semaphore - 1;
sem_post(&mutex);
}
else
{
    	//signal
	printf("\nJust Exiting...\n");
	sem_post(&mutex);
}
	
}

int main()
{
	sem_init(&mutex, 0, 3);
	pthread_t t1,t2;
	pthread_create(&t1,NULL,thread,NULL);
	sleep(2);
	pthread_create(&t2,NULL,thread,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	sem_destroy(&mutex);
	return 0;
}

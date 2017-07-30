/*....................................................
* Author: Sanyam Arya
* ersanyamarya@gmail.com
* https://www.facebook.com/er.sanyam.arya
* https://www.linkedin.com/in/sanyam-arya-077ab638/
......................................................*/

/*
* Program to show use of semaphores
* remove semaphores and see the output of the program
* the initial and final value of 'value' will not be same
* as the threads are executing at random and can access 
* the same variable at the same time.
* Semaphore locks the critical section and it can be used
* by only one thread at a perticular time
*/
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/syscall.h>
#include<semaphore.h>
#define MAX 5000

sem_t s1, s2; //Variables for semaphores
int value = 1000; // Global varraible to be altered in different threads
void* efun1(void* pv) { //function of the 1st thread
	int i;
	sem_wait(&s1); //Semaphore 1 is waiting to be unlocked
	for (i = 1; i <= MAX; i++) {
		value++; // critical section 
		printf("--A-----%d\t value = %d\n", i, value);
		usleep(100);
	}
	sem_post(&s2); // Semaphore 2 is locked
}
void* efun2(void* pv) {
	int i;
	sem_wait(&s2);//Semaphore 2 is waiting to be unlocked
	for (i = 1; i <= MAX; i++) {
		value--; //critical section
		printf("--B-----%d\t value = %d\n", i, value);
		usleep(100);
	}
	sem_post(&s1); //Semaphore 1 is locked
}
int main() {
	pthread_t pt1, pt2; // variables for threads
	sem_init(&s1, 0, 0); // initializing semaphores
	sem_init(&s2, 0, 1);
	printf("Value befoure -- %d\n", value);
	pthread_create(&pt1, NULL, efun1, NULL);//creating threads
	pthread_create(&pt2, NULL, efun2, NULL);
	pthread_join(pt1, NULL);//closing threads
	pthread_join(pt2, NULL);
	printf("Value after   -- %d\n", value);
	sem_destroy(&s1); //distroying Semaphores
	sem_destroy(&s2);
	return 0;
}

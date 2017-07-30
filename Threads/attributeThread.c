/*....................................................
* Author: Sanyam Arya
* ersanyamarya@gmail.com
* https://www.facebook.com/er.sanyam.arya
* https://www.linkedin.com/in/sanyam-arya-077ab638/
......................................................*/
#define MAX 20
#define  _GNU_SOURCE
#define CPU_IN_USE 2
#include <pthread.h>
#include <wait.h>
#include <syscall.h>
#include <sys/resource.h>
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void * efun(void*pv) {
	int tid = syscall(SYS_gettid);

	for (int i = 0; i < MAX; i++) {
		printf(
				"Welcome to the thread .. pid is %d and ppid is %d.. \n i is: %d\n",
				getpid(), getppid(), i);
		printf("\nTid is %d\n", tid);
		sleep(1);
	}
}
int main() {
	pid_t ret = 0; //return value for the thread creation
	void *status; // status of the thread (void pointer)
	pthread_t thread1;
	pthread_attr_t attributes; // attributes of the thread
	pthread_attr_init(&attributes); // initialising the attributes
	pthread_attr_setschedpolicy(&attributes, SCHED_FIFO); // Setting policy for scheduller
	struct sched_param p1;
	p1.sched_priority = 50; // setting priority
	pthread_attr_setschedparam(&attributes, &p1); // schedule setting
	cpu_set_t mask;
	CPU_ZERO(&mask); // masking mask with 0s
	CPU_SET(CPU_IN_USE, &mask); // selecting the core to be used
	pthread_attr_setaffinity_np(&attributes, sizeof(mask), &mask); // setting affinity for CPU
	pthread_attr_setinheritsched(&attributes, PTHREAD_EXPLICIT_SCHED); //function sets the  inherit-scheduler attribute  of  the  thread attributes
	ret = pthread_create(&thread1, &attributes, efun, NULL);
	if (ret)
		fprintf(stderr, "Pthread_Create Failed .. %s\n", strerror(ret));
	pthread_join(thread1, &status);
	return 0;
}

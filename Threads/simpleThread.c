/*....................................................
* Author: Sanyam Arya
* ersanyamarya@gmail.com
* https://www.facebook.com/er.sanyam.arya
* https://www.linkedin.com/in/sanyam-arya-077ab638/
......................................................*/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <syscall.h>
#define MAX 5
void * efun1(void *arg) {
	int tid = syscall(SYS_gettid);
	for (int i = 0; i < MAX; i++) {
		printf("\n** Thread 1 id is %d ** --i is %d-- \n", tid, i);
		sleep(1);
	}
}
void * efun2(void *arg) {
	int tid = syscall(SYS_gettid);
	for (int i = 0; i < MAX; i++) {
		printf("\n** Thread 2 id is %d ** --i is %d-- \n", tid, i);
		sleep(2);
	}
}
int main() {
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, efun1, NULL);
	pthread_create(&thread2, NULL, efun2, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return 0;
}

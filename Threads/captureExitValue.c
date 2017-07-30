/*....................................................
* Author: Sanyam Arya
* ersanyamarya@gmail.com
* https://www.facebook.com/er.sanyam.arya
* https://www.linkedin.com/in/sanyam-arya-077ab638/
......................................................*/
#include<stdio.h>
#include<pthread.h>
#include <unistd.h>
#include<wait.h>
#include<syscall.h>
#define MAX 10

void * efun1(void*pv) {
	int tid = syscall(SYS_gettid);

	for (int i = 1; i < MAX; i++) {
		printf("\nTid is %d\n", tid);
		printf("\nA-- i is %d\n", i);
		sleep(1);
	}
	pthread_exit((void*) 10);

}
void * efun2(void*pv) {
	int tid = syscall(SYS_gettid);

	for (int i = 1; i < MAX; i++) {
		printf("\nTid is %d\n", tid);
		printf("\nB-- i is %d\n", i);
		sleep(1);
	}
	pthread_exit((void*) 20);
}
int main() {

	pthread_t thread1, thread2;
	void *statusThread1, *statusThread2;
	pthread_create(&thread1, NULL, efun1, NULL);
	pthread_create(&thread2, NULL, efun2, NULL);
	pthread_join(thread1, &statusThread1);
	pthread_join(thread2, &statusThread2);

	printf("\nStatus of 1 .... %d \t Status of 2 .... %d\n",
			(int) statusThread1, (int) statusThread2);

	return 0;
}

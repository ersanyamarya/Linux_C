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
void * efun(void *pv) {
	char *ps = pv;
	int tid = syscall(SYS_gettid);
	for (int i = 0; i < MAX; i++) {
		printf("\n** Thread id: %d ** --i is %d-- \nand ps is :\n", tid, i);
		puts(ps);
		sleep(1);
	}
}
int main() {
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, efun, "thread1");
	pthread_create(&thread2, NULL, efun, "thread2");
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return 0;
}

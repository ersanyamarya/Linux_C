/*....................................................
* Author: Sanyam Arya
* ersanyamarya@gmail.com
* https://www.facebook.com/er.sanyam.arya
* https://www.linkedin.com/in/sanyam-arya-077ab638/
......................................................*/
#include<stdio.h>
#include<pthread.h>
#include<wait.h>
#include<syscall.h>
#define MAX 10

void * serviceFunction(void*pv) {
	int tid = syscall(SYS_gettid);
	int id = (int) pv;
	printf("Service ID: %d Tid: %d\n", id, tid);
}

int main() {
	int i, n, k;
	printf("\nEnter the no of threads\n");
	scanf("%d", &n);
	pthread_t ptarr[n];
	for (i = 0; i < n; i++) {
		k = 100 + i;
		pthread_create(&ptarr[i], NULL, serviceFunction, (void*) k);
	}
	for (i = 0; i < n; i++) {
		pthread_join(&ptarr[i], NULL);
	}
	return 0;
}

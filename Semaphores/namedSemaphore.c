/*....................................................
* Author: Sanyam Arya
* ersanyamarya@gmail.com
* https://www.facebook.com/er.sanyam.arya
* https://www.linkedin.com/in/sanyam-arya-077ab638/
......................................................*/
#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include<pthread.h>
#include<sys/syscall.h>
#include <sys/wait.h>
#include<semaphore.h>
#define MAX 5000
int main()
{
	pid_t ret;
	int i, status;
	sem_t *semaphoreOne;
	semaphoreOne = sem_open("semanew",O_CREAT,0666,0);
	ret = fork();
	if(ret == 0){
		sem_wait(semaphoreOne);
		for(i=1;i<=MAX;i++){
			printf("Child-----%d\n",i);
			usleep(100);
		}
		//sem_post(semaphoreOne);
	} else{
		//sem_wait(semaphoreOne);
		for(i=1;i<=MAX;i++){
			printf("Parent----%d\n",i);
			usleep(100);
		}
		sem_post(semaphoreOne);
		waitpid(-1,&status,0);
		sem_destroy(semaphoreOne);
	}

return 0;
}

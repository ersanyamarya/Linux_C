/*....................................................
* Author: Sanyam Arya
* ersanyamarya@gmail.com
* https://www.facebook.com/er.sanyam.arya
* https://www.linkedin.com/in/sanyam-arya-077ab638/
......................................................*/
#include <sys/resource.h>
#include <stdio.h>
#include <sched.h>
#include <sys/wait.h>
#include <stdlib.h>
int main() {
	pid_t pid = getpid();
	int k = 0;
		setpriority(PRIO_PROCESS,pid,9 );s
	 while (1)
	 printf("Welcome.... pid is:%d", pid);
	struct sched_param p1;
	p1.sched_priority = 10;
	k = sched_setscheduler(pid, SCHED_FIFO, &p1);
	if (k < 0) {
		perror("SCHED_SETSCHEDULER");
		exit(1);
	}
	while (1)
		printf("Welcome.... pid is:%d\n", pid);
		sleep(1);
}

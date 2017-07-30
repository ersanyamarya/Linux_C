/*....................................................
* Author: Sanyam Arya
* ersanyamarya@gmail.com
* https://www.facebook.com/er.sanyam.arya
* https://www.linkedin.com/in/sanyam-arya-077ab638/
......................................................*/
#define  _GNU_SOURCE
#define CPU_IN_USE 2
#include <sys/resource.h>
#include <stdio.h>
#include <sched.h>
#include <sys/wait.h>
#include <stdlib.h>
int main() {
	pid_t pid = getpid(),ppid = getppid();
	cpu_set_t mask;
	CPU_ZERO(&mask);
	CPU_SET(CPU_IN_USE, &mask);
	sched_setaffinity(pid, sizeof(mask), &mask);
	while (1)
		printf("Welcome.... pid is: %d and ppid is %d\n", pid, ppid);

}

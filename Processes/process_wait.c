/*....................................................
* Author: Sanyam Arya
* ersanyamarya@gmail.com
* https://www.facebook.com/er.sanyam.arya
* https://www.linkedin.com/in/sanyam-arya-077ab638/
......................................................*/
#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>
#define MAX 50
int main() {
	pid_t ret;
	int status;
	ret = fork();
	if (ret < 0) {
		perror("fork");
	}
	if (ret == 0) {
		for (int i = 0; i < MAX; i++) {
			printf(
					"\nI am the child process, my pid is %d, and my ppid is %d and idex is %d",
					getpid(), getppid(), i);
			//sleep(1);
		}
	}
	if (ret > 0) {
		waitpid(-1, &status, 0);
		for (int i = 0; i < MAX; i++) {
			printf(
					"\nI am the parent process my pid is %d and return value is %d and index is %d",
					getpid(), ret, i);
			//sleep(1);

		}

	}

	return 0;
}

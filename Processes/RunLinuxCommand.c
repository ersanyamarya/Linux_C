/*....................................................
* Author: Sanyam Arya
* ersanyamarya@gmail.com
* https://www.facebook.com/er.sanyam.arya
* https://www.linkedin.com/in/sanyam-arya-077ab638/
......................................................*/
#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>
#define MAX 8
int main() {
	pid_t ret/*....................................................
* Author: Sanyam Arya
* ersanyamarya@gmail.com
* https://www.facebook.com/er.sanyam.arya
* https://www.linkedin.com/in/sanyam-arya-077ab638/
......................................................*/
;
	int status, checkExecl;
	ret = fork();
	if (ret < 0) {
		perror("fork");
	}
	if (ret == 0) {
		checkExecl = execl("/usr/bin/cal", "cal", "2020", NULL);
		if (checkExecl < 0) {
			perror("execl");
		}
	}
	if (ret > 0) {
		waitpid(-1, &status, 0);
	}

	return 0;
}

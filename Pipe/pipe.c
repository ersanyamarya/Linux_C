// Linux in C
/*....................................................
* Author: Sanyam Arya
* ersanyamarya@gmail.com
* https://www.facebook.com/er.sanyam.arya
* https://www.linkedin.com/in/sanyam-arya-077ab638/
......................................................*/
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define _GNU_SOURCE

int main()
    {
        int pipefd[2];
        pid_t ret;
        char buf[5];
        char *writeBuff="Sanyam is awesome";
        if (pipe(pipefd) == -1) {
            perror("pipe");
        }
        ret = fork();
        if (ret == -1) {
            perror("fork");
        }
        if (ret == 0) {
            close(pipefd[1]);
            while (read(pipefd[0], &buf, 1) > 0)
                write(STDOUT_FILENO, &buf, 1);
            write(STDOUT_FILENO, "\n", 1);
            close(pipefd[0]);

        } else {
            close(pipefd[0]);
            write(pipefd[1], writeBuff, strlen(writeBuff));
            close(pipefd[1]);]
            waitpid(-1, &status, 0);
        }
    }

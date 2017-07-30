/*....................................................
* Author: Sanyam Arya
* ersanyamarya@gmail.com
* https://www.facebook.com/er.sanyam.arya
* https://www.linkedin.com/in/sanyam-arya-077ab638/
......................................................*/
#include <stdio.h>
#include <mqueue.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
int main(){
  mqd_t mqd;
  mqd = mq_open("/mymq",O_CREAT | O_WRONLY,0600, NULL);
  if (mqd == (mqd_t) -1){
    perror("open");
  }

  char *msg = "Hello Sanyam";
  if (mq_send(mqd,msg,strlen(msg),0)==-1){
    perror("send");
  }
  mq_close(mqd);
}

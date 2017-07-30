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
  char msg[8192];
  int prio;
  mqd = mq_open("/mymq",O_RDONLY);
  if (mqd == (mqd_t) -1){
    perror("open");
  }
  if (mq_receive(mqd,msg,8192,&prio)==-1){
    perror("receive");
  }
  puts(msg);
  mq_close(mqd);
}

/*....................................................
* Author: Sanyam Arya
* ersanyamarya@gmail.com
* https://www.facebook.com/er.sanyam.arya
* https://www.linkedin.com/in/sanyam-arya-077ab638/
......................................................*/
#include<stdio.h>
#include <signal.h>
void handler_for_init(int signo) {
	printf("\nyou cant interrupt me\n");
}
void handler_for_quit(int signo) {
	printf("\nyou cant quit me\n");
}
void handler_for_tstp(int signo) {
	printf("\nyou cant Suspend me\n");
}
void handler_for_term(int signo) {
	printf("\nyou cant terminate me\n");
}
int main() {

	printf("\nWelcome... pid=%d\n", getpid());
	signal(SIGINT, handler_for_init);
	signal(SIGQUIT, handler_for_quit);
	signal(SIGTERM, handler_for_term);
	signal(SIGTSTP, handler_for_tstp);
	while (1) {
		pause();
	}
	return 0;

}

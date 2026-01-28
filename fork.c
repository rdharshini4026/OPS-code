#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    fork();
    if(fork() == 0){
	    printf("\nBAD\n");
    }
    printf("nHELLO\n");

    return 0;
}

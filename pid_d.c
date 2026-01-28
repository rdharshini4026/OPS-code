#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid, ppid;

    pid = getpid();
    printf("Current process ID: %d\n", pid);

    ppid = getppid();
    printf("Parent process ID: %d\n", ppid);

    return 0;
}

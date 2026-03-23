
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int fd[2];
    char msg[] = "Hello IPC";
    char buffer[20];

    // create pipe
    if(pipe(fd) == -1) {
        printf("Pipe failed\n");
        return 1;
    }

    int pid = fork();

    if(pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if(pid == 0) {
        // Child process
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
    } else {
        // Parent process
        write(fd[1], msg, sizeof(msg));
    }

    return 0;
}

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    pid_t pid;

    pid = fork();

    if (pid < 0) fprintf(stderr, "Failed to create child process.\n");

    if (pid == 0) {

        int value;

        switch (argc) {
            case 1:
                printf("CHILD: No program providade. Exiting child.\n");
                break;
            default:
                value = execvp(argv[1], argv + 1);
                break;
        }

        if (value < 0)
 	        printf("Failed to execute external program.\n");
    } else {
        wait(NULL);
        printf("PARENT: Exiting from parent process...\n");
    }

    return 0;
}

//fork, exec, wait
#include <iostream>
#include <unistd.h>
#include <string.h>
using namespace std;

int main() {
    int pipefd[2];
    char buffer[50];
    char msg[] = "Hello from Child through Pipe!";

    if (pipe(pipefd) == -1) {
        cout << "Pipe failed!" << endl;
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) {
        // Child process: write message
        close(pipefd[0]); // close read end
        write(pipefd[1], msg, strlen(msg) + 1);
        close(pipefd[1]);
    }
    else {
        // Parent process: read message
        close(pipefd[1]); // close write end
        read(pipefd[0], buffer, sizeof(buffer));
        cout << "Parent received: " << buffer << endl;
        close(pipefd[0]);
    }

    return 0;
}
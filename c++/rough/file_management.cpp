#include <iostream>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

int main() {
    int fd;
    char buffer[50];
    char msg[] = "Operating System Lab - File Management";

    // create and write into file
    fd = open("sample.txt", O_CREAT | O_WRONLY, 0777);
    write(fd, msg, sizeof(msg));
    close(fd);

    // read from file
    fd = open("sample.txt", O_RDONLY);
    read(fd, buffer, sizeof(msg));
    cout << "File contains: " << buffer << endl;
    close(fd);

    return 0;
}
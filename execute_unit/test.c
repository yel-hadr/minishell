#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int file = open("file.txt", O_RDWR | O_CREAT | O_APPEND, 0777);
    //int file2 = dup(file);
    dup2(file, 1);
	int fd[2];
	int prev_pipe;
	if (pipe(fd) < 0)	
		printf("error\n");
	dprintf(fd[1], "zaba123456789");
	prev_pipe = fd[0];
	char buf[1024];
	read(fd[0], buf, 15);
	dprintf(1, "%s", buf);

    //write(1, "zab\n", 4);
	close(fd[0]);
	close(fd[1]);
    close(file);  // Close duplicated file descriptor	
    //close(file);   // Close original file descriptor

    return 0;
}

#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h>
#include <unistd.h>

int main(){


	char * c2s_fifo = "/tmp/client_to_server_fifo";
	char * s2c_fifo = "/tmp/server_to_client_fifo";

	mkfifo(c2s_fifo, 0666);
	mkfifo(s2c_fifo, 0666);

	printf("---- CLIENT ----\nType a message and press Enter to send it to server\n\n");

	if(fork()){
		// Parent Process
		// Used for reading from pipe (s2c)

		char buf[1000];
		
		int fd1 = open(s2c_fifo, O_RDONLY); 
		
		while(1){
	        if( read( fd1, buf, 1000 ) > 0 )
            	printf("MESSAGE FROM SERVER: %s", buf);

	    }
	    close(fd1);
	}

	else{
		// Child Process
		// Used for writing to pipe (c2s)
		
		int fd2 = open(c2s_fifo, O_WRONLY); 
		
		while(1){
			char buf[1000];
			fgets(buf, 1000, stdin);
			if(strcmp(buf, "exit\n") == 0){
				printf("Closing client-to-server pipe...\nYou can no longer send messages from client to server\n");
				break;
			}
	        write(fd2, buf, strlen(buf)+1);
	    }
	    close(fd2);
	}

}
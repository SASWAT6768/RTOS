#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <errno.h>

#include <pulse/simple.h>
#include <pulse/error.h>
#include <pulse/gccmacro.h>
void  INThandler(int sig)
{
     char  c;

     signal(sig,SIG_IGN);
     printf("Do you want to quit? [y/n] ");
     c = getchar();
     if (c == 'y' || c == 'Y')
          exit(0);
     else
          signal(SIGINT, INThandler);
     getchar(); // Get new line character
}

   
static ssize_t loop_write(int fd, const void*data, size_t size) {
    ssize_t ret = 0;

    while (size > 0) {
        ssize_t r;

        if ((r = write(fd, data, size)) < 0)
            return r;

        if (r == 0)
            break;

        ret += r;
        data = (const uint8_t*) data + r;
        size -= (size_t) r;
    }

    return ret;
}
/*clock_gettime(CLOCK_MONOTONIC, &finish);
elapsed = (finish.tv_sec - start.tv_sec);
elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000.0;
printf("fun() took %f seconds to execute \n",elapsed);*/

int main(int argc, char *argv[])
{
	struct sockaddr_in their_addr;
	//clock_t start, end;
        int my_sock;
	int their_sock;
	int their_addr_size;
	int portno;
	 //double cpu_time_used;
        //pthread_t sendt,recvt;
	char msg[700];
	char username[100];
	char user1[600];
	char ip[INET_ADDRSTRLEN];
	int len;
   /* The sample type to use */
    static const pa_sample_spec ss = {
        .format = PA_SAMPLE_S16LE,
        .rate = 44100,
        .channels = 2
    };
    pa_simple *s = NULL;
    int ret = 1;
    int error;        
if (!(s = pa_simple_new(NULL, argv[0], PA_STREAM_RECORD, NULL, "record", &ss, NULL, NULL, &error))) {
        fprintf(stderr, __FILE__": pa_simple_new() failed: %s\n", pa_strerror(error));
       
        pa_simple_free(s);

    return ret;
    }

signal(SIGINT, INThandler);
	if(argc < 4) {
		printf("less arguments");
		exit(1);
	}
	portno = atoi(argv[3]);
	strcpy(username,argv[1]);
	int opt;
	my_sock = socket(AF_INET,SOCK_STREAM,0);
	setsockopt(my_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&opt, sizeof(opt));
	memset(their_addr.sin_zero,'\0',sizeof(their_addr.sin_zero));
	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(portno);
	inet_pton(AF_INET, argv[2], &their_addr.sin_addr);
	
        if(connect(my_sock,(struct sockaddr *)&their_addr,sizeof(their_addr)) < 0) {
		perror("connection not esatablished");
		exit(1);
	}
	inet_ntop(AF_INET, (struct sockaddr *)&their_addr, ip, INET_ADDRSTRLEN);
	printf("connected to %s, start chatting\n",ip);
//printf("%s\n",their_addr);

//start = clock();	
//ios_base::sync_with_stdio(false);
        //pthread_create(&recvt,NULL,loop_write,&my_sock);
		
for (;;) {
        uint8_t buf[700];	
if (pa_simple_read(s, buf, 700, &error) < 0) {
            fprintf(stderr, __FILE__": pa_simple_read() failed: %s\n", pa_strerror(error));
              pa_simple_free(s);

    return ret;
    } 
if (loop_write(STDOUT_FILENO, buf, sizeof(buf)) != sizeof(buf)) {
            fprintf(stderr, __FILE__": write() failed: %s\n", strerror(errno));
           pa_simple_free(s);

    return ret;
        }
    }      
ret=0;







/*while( > 0) {
		strcpy(user1,username);
		strcat(user1,":");
		strcat(user1,msg);
		len = write(my_sock,user1,strlen(user1));
		if(len < 0) {
			perror("message not sent");
			exit(1);
		}
		memset(msg,'\0',sizeof(msg));
		memset(user1,'\0',sizeof(user1));
	}*/
	//pthread_join(recvt,NULL);
//end = clock();
//cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

//printf("fun() took %f seconds to execute \n",cpu_time_used);
close(my_sock);


return 0;
}

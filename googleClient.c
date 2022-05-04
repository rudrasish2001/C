
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 80
   
int main()
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *message;
    char reply[2048];
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
   
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr=inet_addr("142.250.192.196");
    
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
puts ("connected");

message="GET / HTTP/1.1\r\n\r\n";
    if((send(sock , message , strlen(message),0 ))<0)
	{ 
printf("\nsend failed \n");
return -1;
	}
    printf("\nrequest message sent\n");
if((recv(sock , reply , 2048 , 0 ))<0)
	{ 
printf("\nReceive failed \n");
return -1;
	}
puts("\nReceived data\n");
puts (reply);
    return 0;
}

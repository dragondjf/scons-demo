#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 30

void error_handling(char *message);
void read_childproc(int sig);

int main(int argc, char const *argv[])
{
    int serv_sock;
    int clnt_sock;
    char message[BUF_SIZE];
    int str_len=0, state=0, i=0;
    pid_t pid;

    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_addr_size;


    if (argc !=2)
    {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    struct sigaction act;
    act.sa_handler = read_childproc;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    state = sigaction(SIGCHLD, &act, 0);

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1)
    {
        error_handling("socket() error");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1)
    {
        error_handling("bind() error");
    }

    if(listen(serv_sock, 5) == -1)
    {
        error_handling("listen() error");
    }

    

    while(1)
    {
        clnt_addr_size = sizeof(clnt_addr);
        clnt_sock = accept(serv_sock, (struct sockaddr*) &clnt_addr, &clnt_addr_size);

        if ( clnt_sock == -1)
        {
            continue;
        }
        else
        {
            printf("connect client %d\n", ++i );
        }

        pid = fork();
        if (pid == -1)
        {
            close(clnt_sock);
            continue;
        }
        if (pid == 0)
        {
            close(serv_sock);
            while((str_len = read(clnt_sock, message, BUF_SIZE)) != 0){
                write(clnt_sock, message, str_len);
            }
            close(clnt_sock);
            puts("client disconnected");
            return 0;
        }
        else{
            close(clnt_sock);
        }
    }

    close(serv_sock);

    return 0;
}


void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

void read_childproc(int sig)
{
    int status;
    pid_t pid = waitpid(-1, &status, WNOHANG);
    if (WIFEXITED(status))
    {
        printf("Remove proc id %d\n", pid);
        printf("Child send: %d \n", WIFEXITED(status));
    }
}
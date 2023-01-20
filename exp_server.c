#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <pthread.h>

//  ------------------------------------------------------------------------------------------------------------------------------------------

/* Misc constants */
#define MAXLINE 8192 /* Max text line length */
#define LISTENQ 1024 /* Second argument to listen() */

int open_listenfd(char *port)
{
    struct addrinfo hints, *listp, *p;
    int listenfd, optval = 1;
    char host[MAXLINE], service[MAXLINE];
    int flags;

    /* Get a list of potential server addresses */
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_socktype = SOCK_STREAM;             /* Accept connections */
    hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG; /* ... on any IP address AI_PASSIVE - used on server for TCP passive connection, AI_ADDRCONFIG - to use both IPv4 and IPv6 addresses */
    hints.ai_flags |= AI_NUMERICSERV;            /* ... using port number instead of service name*/
    getaddrinfo(NULL, port, &hints, &listp);

    /* Walk the list for one that we can bind to */
    for (p = listp; p; p = p->ai_next)
    {
        /* Create a socket descriptor */
        if ((listenfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0)
            continue; /* Socket failed, try the next */

        /* Eliminates "Address already in use" error from bind */
        setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, // line:netp:csapp:setsockopt
                   (const void *)&optval, sizeof(int));

        flags = NI_NUMERICHOST | NI_NUMERICSERV; /* Display address string instead of domain name and port number instead of service name */
        getnameinfo(p->ai_addr, p->ai_addrlen, host, MAXLINE, service, MAXLINE, flags);
        printf("host:%s, service:%s\n", host, service);

        /* Bind the descriptor to the address */
        if (bind(listenfd, p->ai_addr, p->ai_addrlen) == 0)
            break;       /* Success */
        close(listenfd); /* Bind failed, try the next */
    }

    /* Clean up */
    freeaddrinfo(listp);
    if (!p) /* No address worked */
        return -1;

    /* Make it a listening socket ready to accept connection requests */
    if (listen(listenfd, LISTENQ) < 0)
    {
        close(listenfd);
        return -1;
    }
    return listenfd;
}

//  ------------------------------------------------------------------------------------------------------------------------------------------

static int unum = 0;
void echo(int connfd)
{
    char fname[256];
    sprintf(fname, "../database/user_details/user_%d_detail.txt", unum);
    FILE *fp2;
    size_t n;
    char buf[MAXLINE];
    n = read(connfd, buf, MAXLINE);
    buf[n] = '\0';
    printf("Message received by server: %s\n", buf);
    FILE *fp = fopen(fname, "a+");
    fputs(buf, fp);
    fclose(fp);
    n = read(connfd, buf, MAXLINE);
    buf[n] = '\0';
    printf("Message received by server: %s\n", buf);
    fp = fopen(fname, "a+");
    fputs(buf, fp);
    fclose(fp);
    sprintf(fname, "../database/progress_report/user_%d_progress.txt", unum);
    while ((n = read(connfd, buf, MAXLINE)) != 0)
    {
        buf[n] = '\0';
        printf("Message received by server: %s\n", buf);
        fp2 = fopen(fname, "a+");
        fputs(buf, fp2);
        fclose(fp2);
    }
}

int listenfd;
socklen_t clientlen;
struct sockaddr_storage clientaddr; /* Enough room for any addr */
char client_hostname[MAXLINE], client_port[MAXLINE];

void *clients(void *arg)
{
    int *disp = (int *)arg;
    getnameinfo((struct sockaddr *)&clientaddr, clientlen,
                client_hostname, MAXLINE, client_port, MAXLINE, 0);
    printf("Connected to (%s, %s)\n", client_hostname, client_port);
    printf("New client connected\n");
    echo(*disp);
    printf("Client disconnected\n");
    close(*disp);
    pthread_exit(NULL);
}

//  ------------------------------------------------------------------------------------------------------------------------------------------

int main(int argc, char **argv)
{
    listenfd = open_listenfd(argv[1]);
    while (1)
    {
        pthread_t threadID;
        printf("Waiting for a new Client to connect\n");
        clientlen = sizeof(struct sockaddr_storage); /* Important! */
        int connfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clientlen);
        pthread_create(&threadID, NULL, clients, (void *)&connfd);
        unum++;
    }
    exit(0);
}


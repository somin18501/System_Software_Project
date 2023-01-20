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

#define MAXLINE 8192 /* Max text line length */

int open_clientfd(char *hostname, char *port)
{
    int clientfd;
    struct addrinfo hints, *listp, *p;
    char host[MAXLINE], service[MAXLINE];
    int flags;

    /* Get a list of potential server addresses */
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_socktype = SOCK_STREAM; /* Open a connection */
    hints.ai_flags = AI_NUMERICSERV; /* ... using a numeric port arg. */
    hints.ai_flags |= AI_ADDRCONFIG; /* Recommended for connections where we get IPv4 or IPv6 addresses */
    getaddrinfo(hostname, port, &hints, &listp);

    /* Walk the list for one that we can successfully connect to */
    for (p = listp; p; p = p->ai_next)
    {
        /* Create a socket descriptor */
        if ((clientfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0)
            continue; /* Socket failed, try the next */

        flags = NI_NUMERICHOST | NI_NUMERICSERV; /* Display address string instead of domain name and port number instead of service name */
        getnameinfo(p->ai_addr, p->ai_addrlen, host, MAXLINE, service, MAXLINE, flags);
        printf("Host:%s, Service:%s\n", host, service);

        /* Connect to the server */
        if (connect(clientfd, p->ai_addr, p->ai_addrlen) != -1)
        {
            printf("Connected to server %s at port %s\n", host, service);
            break; /* Success */
        }
        close(clientfd); /* Connect failed, try another */ // line:netp:openclientfd:closefd
    }

    /* Clean up */
    freeaddrinfo(listp);
    if (!p) /* All connects failed */
        return -1;
    else /* The last connect succeeded */
        return clientfd;
}

int clientfd;

//  ------------------------------------------------------------------------------------------------------------------------------------------

#define READ 0
#define WRITE 1

int number_of_days;
char c = 'N';
int per_day = 20;
int fd[2];
char *answers[] = {"The task is not done\n", "The task is done\n"};

void alarm_name_hanlder1()
{
    printf("\nThe number of days is set to 21 days\n");
    exit(21);
}

void setdefault()
{
    printf("Today's task is not completed\n");
    char tp[1];
    tp[0] = c;
    write(fd[WRITE], tp, 2);
    exit(78);
}

void rem2()
{
    signal(SIGALRM, setdefault);
    alarm(per_day / 4);
    printf(" This is the last reminder to complete the task!\n");
    system("echo '\007'");
    printf("\nEnter y/Y if you finished your today's task:");
}

void rem1()
{
    signal(SIGALRM, rem2);
    alarm(per_day / 4);
    printf(" This is a reminder to complete the task!\n");
    system("echo '\007'");
    printf("\nEnter y/Y if you finished your today's task:");
}

void *take_input()
{
    scanf("%c", &c);
    getchar();
    char tp[1];
    tp[0] = c;
    write(fd[WRITE], tp, 2);
    if (c == 'y' || c == 'Y')
        exit(89);
    else
    {
        printf("Today's task is not completed\n");
        exit(78);
    }
}

void *write_file(void *arg)
{
    int *th = (int *)arg;
    char message[1]; /* Parent process' message buffer */
    read(fd[READ], message, 2);             /* Receive */
    char s[256];
    strcpy(s, "Day ");
    char num[4];
    num[0] = (*th / 10 + 48);
    num[1] = (*th % 10 + 48);
    num[2] = ':';
    strcat(s, num);
    if (message[0] == 'Y' || message[0] == 'y')
    {
        strcat(s, answers[1]);
        printf("- %s\n", s);
        write(clientfd, s, strlen(s));
    }
    else
    {
        strcat(s, answers[0]);
        printf("- %s\n", s);
        write(clientfd, s, strlen(s));
    }
}

//  ------------------------------------------------------------------------------------------------------------------------------------------

int main(int argc, char **argv)
{
    // int clientfd;
    char *host, *port;
    host = argv[1];
    port = argv[2];
    clientfd = open_clientfd(host, port);

    char name[256];
    printf("Enter your name here: ");
    fgets(name, 256, stdin);
    write(clientfd, name, strlen(name));

    int p = fork();
    if (p == 0)
    {
        signal(SIGALRM, alarm_name_hanlder1);
        alarm(5);
        printf("Enter the number of days you want to track your habit.\n");
        printf("If you don't give input within 5 seconds, it will be set to a default value of 21 days:");
        scanf("%d", &number_of_days);
        exit(number_of_days);
    }
    else
    {
        int status;
        wait(&status);
        number_of_days = WEXITSTATUS(status);
    }

    char num[3];
    num[0] = (number_of_days / 10 + 48);
    num[1] = (number_of_days % 10 + 48);
    char buf[256] = "Number of days for tracking the habit: ";
    strcat(buf, num);
    write(clientfd, buf, strlen(buf));

    pipe(fd); /* Create  an unnamed pipe */

    int i, rset = 1;
    int warn = number_of_days / 7;
    for (i = 1; i <= number_of_days; i++)
    {
        int p1 = fork();
        if (p1 == 0)
        { // child process
            c = 'N';
            pthread_t threadID;
            signal(SIGALRM, rem1);
            printf("\n Day %d", i);
            printf("\nEnter y/Y if you finished your today's task:");
            alarm(per_day / 4);
            pthread_create(&threadID, NULL, take_input, NULL);
            pthread_join(threadID, NULL);
        }
        else
        { // parent process
            int status;
            wait(&status);

            pthread_t threadID2;
            pthread_create(&threadID2, NULL, write_file, (void *)&i);
            pthread_join(threadID2, NULL);

            if (WEXITSTATUS(status) == 89)
            {
                printf("Today's task is successfully completed!\n");
            }
            else
            {
                if (warn)
                {
                    warn--;
                    printf("You have %d more days remaining to skip\n", warn);
                }
                else
                {
                    printf("Your streak for the task has been reset to 0 days!\n");
                    i = 0;
                    rset++;
                    warn = number_of_days / 7;
                }
            }
        }
    }
    char end[256];
    char st[1];
    char num2[3];
    num2[0] = (rset / 10 + 48);
    num2[1] = (rset % 10 + 48);
    st[0] = '\0';
    strcpy(end, "The task got completed in ");
    strcat(end, num2);
    strcat(end, " attempt(s).");
    write(clientfd, end, strlen(end));
    write(clientfd, st, strlen(st));
    close(clientfd);
    exit(0);
}


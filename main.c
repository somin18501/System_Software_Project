#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <pthread.h>

#define READ 0
#define WRITE 1

int number_of_days;
char c = 'N';
int per_day = 20;
int fd[2];
FILE *fp2;
char* answers[] = {" Not Done\n", " Done\n"};

void alarm_name_hanlder1()
{
    printf("\nThe number of days is set to 21 days\n");
    exit(21);
}

void setdefault()
{
    printf("today's task is not completed\n");
    char tp[1];
    tp[0]=c;
    // close(fd[READ]);
    printf("written by alarm %c\n",c); // just for checking
    write(fd[WRITE], tp, 2); 
    // close(fd[WRITE]); /* Close used end */
    exit(78);
}

void rem2()
{
    signal(SIGALRM, setdefault);
    alarm(per_day / 4);
    printf("This is second reminder!!!\n");
    system("echo '\007'");
    printf("Press Y if you completed your task :\n");
}

void rem1()
{
    signal(SIGALRM, rem2);
    alarm(per_day / 4);
    printf("This is first reminder!!!\n");
    system("echo '\007'");
    printf("Press Y if you completed your task :\n");
}

void *take_input()
{
    scanf("%c", &c);
    getchar();
    char tp[1];
    tp[0]=c;
    // close(fd[READ]); 
    printf("written by thread %c\n",c); // just for checking
    write(fd[WRITE], tp, 2); 
    // close(fd[WRITE]); 
    if (c == 'y' || c == 'Y')
        exit(89);
    else
    {
        printf("today's Task not completed\n");
        exit(78);
    }
}

void *write_file(void *arg)
{
    int *th = (int *)arg;
    char message[1];   /* Parent process' message buffer */
    // close(fd[WRITE]);  
    read( fd[READ], message, 2 ); /* Receive */
    printf("read by thread %s\n",message);  // just for checking
    // close(fd[READ]);  
    char s[256];
    strcpy(s,"Day ");
    char num[4];
    num[0]=(*th/10+48);
    num[1]=(*th%10+48);
    num[2]=':';
    strcat(s,num);
    if(message[0]=='Y' || message[0]=='y'){
        strcat(s,answers[1]);
        printf("-%s\n",s);
        fputs(s,fp2);
    }
    else{
        strcat(s,answers[0]);
        printf("%s\n",s);
        fputs(s,fp2);
    }
    fclose(fp2);
}

int main()
{
    char name[256];
    printf("Enter Your name: ");
    fgets(name, 256, stdin);
    FILE *fp=fopen("user_detail.txt","a+");
    fputs(name,fp);
    fclose(fp);

    int p = fork();
    if (p == 0)
    {
        signal(SIGALRM, alarm_name_hanlder1);
        alarm(3);
        printf("Enter the number of days within 3 seconds: ");
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
    num[0]=(number_of_days/10+48);
    num[1]=(number_of_days%10+48);
    char buf[256]="Number of days of deadline is: ";
    strcat(buf,num);
    fp=fopen("user_detail.txt","a+");
    fputs(buf,fp);
    fclose(fp);
    
	pipe(fd);  /* Create  an unnamed pipe */

    int i,rset=1;
    int warn = number_of_days / 7;
    for (i = 1; i <= number_of_days; i++)
    {
        int p1 = fork();
        if (p1 == 0)
        { // child process
            c = 'N';
            pthread_t threadID;
            signal(SIGALRM, rem1);
            printf("\nToday is day %d of your deadline\n", i);
            printf("Press Y if you completed your task :\n");
            alarm(per_day / 4);
            pthread_create(&threadID, NULL, take_input, NULL);
            pthread_join(threadID, NULL);
        }
        else
        { // parent process
            int status;
            wait(&status);

            fp2=fopen("user_progress.txt","a+");
            pthread_t threadID2;
            pthread_create(&threadID2, NULL, write_file, (void *) &i);
            pthread_join(threadID2, NULL);

            if (WEXITSTATUS(status) == 89)
            {
                printf("today's Task completed\n");
            }
            else
            {
                if (warn)
                {
                    warn--;
                    printf("You can still skip %d days\n",warn);
                }
                else
                {
                    printf("Your Task has been reset\n");
                    remove("user_progress.txt");
                    i=0;
                    rset++;
                    warn = number_of_days / 7;
                }
            }
        }
    }
    char end[256];
    strcpy(end,"The task is completed in");
    fp2=fopen("user_progress.txt","a+");
    fprintf(fp2,"%s %d attemps",end,rset);
    fclose(fp2);
    return 0;
}
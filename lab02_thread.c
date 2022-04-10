#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

/*thread function definition*/
void *threadFunction(void *args)
{
    pthread_t tid = pthread_self();
    printf("This is from inside the thread =%d\n", tid);
    // sleep(10);
}

int main(int argc, char *argv[])
{

    pthread_t tid;
    int ret;
    //Soutrik Das
    /*creating thread*/
    pthread_create(&tid, NULL, &threadFunction, NULL);
    printf("Main Function : Thread created\n");
    pthread_join(tid, NULL);
    printf("Main Function: Thread finished executing\n");

    return (0);
}
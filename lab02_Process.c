#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
   printf("Current id = %d\n", (int)getpid());

   pid_t p1 = fork();
   pid_t p2 = fork();

   if (p1 < 0 || p2 < 0)
   {
      fprintf(stderr, "Error in forking");
      return 1;
   }
   else if (p1 > 0)
   {
      if (p2 != 0)
      {
         printf("Inside Parent Process\n");
         printf("ID= %d\n", (int)getpid());
      }
      else if (p2 == 0)
      {
         printf("Child of Parent process from second fork\n");
         printf("Process id of child 2 is %d\n", (int)getpid());
         printf("Process id of parent of child 2 is %d\n", (int)getppid());
      }
   }
   else if (p1 == 0)
   {
      if (p2 != 0)
      {
         printf("This is child 1 born from first fork off main parent\n");
         printf("Process id of child 1 is %d\n", (int)getpid());
         printf("Process id of parent of child 1 is %d\n", (int)getppid());
      }
      else
      {
         printf("This is child process 3 born from second fork off child 1\n");
         printf("Process id of child 3 is %d\n", (int)getpid());
         printf("Process id of parent of child 3 is %d\n", (int)getppid());
      }
   }
   else
   {
      wait(NULL);
      printf("Child processes terminated.");
   }
}

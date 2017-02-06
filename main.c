/*
linux shell-simulator using fork
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

/*char** parseit(char* command){


}
*/
void forker(char *command[])
{
  pid_t pid = fork();

  if(pid < 0)
  {
    //error
    printf("\nAn error occurred, child not created.");
    exit(EXIT_FAILURE);
  }
  else if(pid==0){
    //child, execute a system call
    execvp(*command, command);
    printf("\nerror: unknown command\n");
    exit(EXIT_FAILURE);
  }
  else if(pid>0)
  {
    //parent, wait for child process
    int returnStatus;
    waitpid(pid, &returnStatus, 0);
  }
}

int main()
{
  char command[100];
  char* argv[20];

  while(strcmp(command, "exit") != 0 && strcmp(command, "quit") != 0)
  {
    int counter = 0;
    printf("\n\nREADY:> ");
    fgets(command,100,stdin);
    command[strlen(command)-1] = '\0'; //Remove trailing "\n" assoc. with fgets

    argv[counter] = strtok(command, " ");

    while(argv[counter] != NULL)
    {
        argv[++counter] = strtok(NULL, " ");
    }

    /* TEST OUTPUT
    for(int i = 0; i<counter; ++i)
      printf("argv: %s\n", argv[i]);
    printf("command: %s\n", command);*/

    forker(argv);
  }

  return 0;
}

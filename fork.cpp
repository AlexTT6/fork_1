#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc,  char** argv)
{
 for(int i = 1; i<argc; i++ )
{
   std::string program  = argv[i];
   pid_t pid = fork();
   if (pid < 0)
   {
    std::cout << "error";
    return 1;
   }
   if (pid == 0)
   {
     std::cout<< "child"<<std::endl;
     execlp(program.c_str(), program.c_str(), NULL);
   }
   else
   {
     wait(NULL);

   }
}
}

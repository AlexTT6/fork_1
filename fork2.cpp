#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv) {

    if (argc < 2) {
    std::cout << "error" << std::endl;
    return 1;
  }
      pid_t pid = fork();
      if (pid < 0)
      {
          std::cout << "Error" << std::endl;
          return 1;
      }
      if (pid == 0) {  
          std::cout << "*argv + 1 = " << *argv + 1;
          execvp(argv[1], argv + 1);

      }
      else {
          int status;
          waitpid(pid, &status, 0);
          std::cout << "* Program Finished *" << std::endl;
      }
  }


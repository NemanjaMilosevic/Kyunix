#include "string.h"
#include "stdio.h"
#include "common.h"
#include "kmalloc.h"
#include "sh.h"
#include "fb.h"


#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define LSH_RL_BUFSIZE 1024
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
//#define LSH_TOK_DELIM " "

int bufsize = LSH_RL_BUFSIZE;
int position = 0;
int c;

extern void halt(void);
/*
  Function Declarations for builtin shell commands:
 */
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_clear(char **args);
int lsh_shutdown(char **args);
int lsh_echo(char **args);

/*
  List of builtin commands, followed by their corresponding functions.
 */

char *builtin_str[] = {
  "cd",
  "help",
  "shutdown",
  "clear",
  "echo"
};

int (*builtin_func[]) (char **) = {
  &lsh_cd,
  &lsh_help,
  &lsh_shutdown,
  &lsh_clear,
  &lsh_echo
};

int lsh_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

/*
  Builtin function implementations.
*/
int lsh_cd(char **args)
{
UNUSED_ARGUMENT(args);
printf("called cd");
/*NOT IMPLEMENTED
  if (args[1] == NULL) {
    printf("lsh: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("lsh");
    }
  }*/
  return 1;
}
int lsh_shutdown(char **args){
    UNUSED_ARGUMENT(args);
    printf("It is now safe to turn off your computer");
    __asm__ __volatile__("hlt");
    return 0;
}
int lsh_echo(char **args){

    for (char* c = *++args; c; c=*++args) {
    printf("%s ",c);
    }

    return 0;
}
int lsh_clear(char **args){UNUSED_ARGUMENT(args);
 fb_clear();

return 0;
}
int lsh_help(char **args)
{
  UNUSED_ARGUMENT(args);
  int i;
  printf("ESH v0.01\n");
  printf("Simple input/parse commands shell.\n");
  printf("The following are built in:\n");

  for (i = 0; i < lsh_num_builtins(); i++) {
    printf("  %s\n", builtin_str[i]);
  }

  printf("Use the man command for information on other programs.");
  return 1;
}

int lsh_launch(char **args);
int lsh_execute(char **args)
{
  int i;

  if (args[0] == NULL) {
    // An empty command was entered.
    return 1;
  }

  for (i = 0; i < lsh_num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }
  printf("%s: command not found",args[0]);
  return lsh_launch(args);
}


int lsh_launch(char **args)
{
  UNUSED_ARGUMENT(args);
//NOT IMPLEMENTED
/*
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
      perror("lsh");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Error forking
    perror("lsh");
  } else {
    // Parent process
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
*/
  return 1;
}

char **lsh_split_line(char *line)
{
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = kmalloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    printf("lsh: allocation error\n");
    return NULL;
    //return(int*)(EXIT_FAILURE);
  }

  token = strtok(line, LSH_TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += LSH_TOK_BUFSIZE;
      //tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        printf("lsh: allocation error\n");
        return NULL;//return(int)(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, LSH_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}



void prompt(){
printf("kyunix>");
}
int parse(char *buffer){
   int status;
   char **args;
 
   args=lsh_split_line(buffer);

   status=lsh_execute(args);


   return status;
}
int main(void)
{




	// char ch=' ';
         //syscall(SYS_read, 1 &ch, 1); 
          
         //syscall(SYS_write, 1,ch, 1);
        // syscall(SYS_read, 3, &ch, 1); 
/*
    int i = 0, j = 0;
    if (syscall(SYS_fork)) {
        while (1) {
            syscall(SYS_write, 1, "parent\n", 7);
            while (j++ < 1000000) {} 
            j = 0;

            if (i++ >= 10) {
                char *msg = "parent doing nothing\n";
                syscall(SYS_write, 1, msg, strlen(msg));
                syscall(SYS_wait);
                syscall(SYS_write, 1, "done waiting\n", 13);

                while (1) {
                }
            }
        }
    } else {
        while (1) {
            syscall(SYS_write, 1, "child\n", 6);
            while (j++ < 1000000) {} 
            j = 0;

            if (i++ >= 7) {
                syscall(SYS_write, 1, "child exiting\n", 14);
                return 0;
            }
        }
    }
*/
    return 0;
}

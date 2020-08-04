#include <iostream>
#include <sstream>
#include <sys/types.h>
#include <string.h>

using namespace std;
int main2()
{
     char  line[1024];  
	 string input;	/* the input line                 */
     char  *argv[64];  
     const char *argc; 
	 char * test;/* the command line argument      */
     
     while (1) {                   /* repeat until done ....         */
          cout << "$ ";
          getline (cin, input);
		  argc = input.c_str();
		  //char str = argc;
		  //test = strtok(str, " ");
		  int i = 0;
		  while(argc != '\0'){
			  argv[i] = const_cast<char*>(argc);
			  argc++;
			  i++;
		  }
          //parse(line, argv);       /*   parse the line               */
          if (strcmp(argv[0], "exit") == 0)  /* is it an "exit"?     */
            return 0;
			  //   exit(0);            /*   exit if it is                */
    //      execute(argv);           /* otherwise, execute the command */
     }
}
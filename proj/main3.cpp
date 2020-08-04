#include <iostream>
#include <string>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sstream>

using namespace std;

int main(){
	const int MAX_COMMAND_SIZE = 500;
	string input;
	string exiting = "exit";
	string word;
	char inputBuffer[MAX_COMMAND_SIZE];
	char *argv[MAX_COMMAND_SIZE];
	pid_t pid;
	int processStatus;
	
	while(1){
		cout << "$ ";
		std::getline(std::cin, input);
		cout << "\n";
		stringstream ss(input);
		while(ss >> word){
			index++;
			args.push_back(word);
			if(word == ">" || word == "<" || word == "|" || word == "&"){
				character = word[0];
				charIndex = index;
				fileIndex = index;
				fileIndex++;
				isValid = true;
			}
		}
		for(std::size_t i = 0; i != args.size() _2; ++i){
			argv[i] = &args[i][0];
		}
		//
		if(argv[0] == exiting){
			exit(0);
		}
		if((pid = fork()) < 0){
			cout << "Forking process failed\n";
			exit(1);
		}
		else if(pid == 0){
			if(execvp(*argv, argv) < 0){
				cout << "Execution failed\n";
				exit(1);
			}
		}
		else{
			waitpid(pid, &processStatus, 0);
		}
	}
}
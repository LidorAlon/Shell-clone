#include <stdio.h>
#include <Windows.h>
#include <string.h>

int cd(char* path)
{


}

int main() {
	char input[256];

	while (1) { // shell loop

		char* argv[10]; // array of strings to hold command and arguments
		int argc = 0; // argument counter

		printf("Shell >");
		fgets(input, sizeof(input), stdin); // read user input


		// parsing
		char* command = strtok(input, " "); // this basically gets the first word of the input (the command)
		char* arg = strtok(NULL, " "); // this gets the second word of the input (the argument)
		
		argv[argc] = command;
		argc++;
		argv[argc] = arg;         // fill argv with the command and the argument
		argc++;

		
		if(strcmp(argv[0], "cd") == 0)
		{

			printf("directory: %s\n", argv[1]);
			
			cd(argv[1]);


	}



	return 0;
}

#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <shlobj.h>


void help()
{

	printf("Available commands: \n");
	printf("mkdir <name> - create new directory\n");
	printf("ls - shows all the files in the current directory\n");
	printf("cd <path> - change directory\n");

}
void mkdir(char* name)
{
	CreateDirectoryA(name, NULL);
}

void ls()
{
	HANDLE hfindfile;
	WIN32_FIND_DATAA data;
	hfindfile = FindFirstFileA("*", &data);
	printf("Files in current directory:\n");
	while(FindNextFileA(hfindfile,&data))
	{
		printf("%s\n", data.cFileName);
	}
	FindClose(hfindfile);
}
int cd(char* path)
{
	return SetCurrentDirectoryA(path);


}

int main() {
	char input[256];
	char home[MAX_PATH];
	char path[256];

	SHGetFolderPathA(      // basically makes it so that the shell starts in the user's home directory instead of hardcoding it
		NULL,
		CSIDL_PROFILE,
		NULL,
		0,
		home
	);

	SetCurrentDirectoryA(home);
		
	while (1) { // shell loop

		char* argv[10]; // array of strings to hold command and arguments
		int argc = 0; // argument counter
		GetCurrentDirectoryA(256, path); // get current directory
		printf("%s Shell >",path);

		fgets(input, sizeof(input), stdin); // read user input
		input[strcspn(input, "\n")] = '\0';


		// parsing
		char* command = strtok(input, " "); // this basically gets the first word of the input (the command)
		char* arg = strtok(NULL, " "); // this gets the second word of the input (the argument)

		argv[argc] = command;
		argc++;
		argv[argc] = arg;         // fill argv with the command and the argument
		argc++;

		 // this whole block of code is about the cd command

		if (strcmp(argv[0], "cd") == 0)
		{

			printf("directory: %s\n", argv[1]);
			if(cd(argv[1]) == 0)
			{
				printf("Error changing directory\n");
			}
			else
			{
				printf("Directory changed to: %s\n", argv[1]);
			}
			


		}
		if (strcmp(argv[0], "help") == 0)
		{
			help();
		}

		// ls command
		if(strcmp(argv[0], "ls") == 0)
		{
			ls();
		}
		if (strcmp(argv[0], "mkdir") == 0)
		{
			mkdir(argv[1]);

		}

		// 
	}


	return 0;
}

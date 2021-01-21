#include <unistd.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

static char input[100];

static int getInput() {
	return fgets(input, sizeof(input), stdin) != NULL;
}

static int parseAndExecute() {
	char *password = strtok(input, " \n");
	if (password != NULL) {
		if (strcmp(password, "quit") == 0) {
			return 0;
		}
		if (strcmp(password, "read") == 0) {
			openFile();
		}
		else {
			printf("You entered: '%s'\n", password);
		}
	}
	if (password == NULL) {
		printf("You entered nothing...\n");
	}
	return 1;
}

int openFile() {
	char header[9];
	int bufferSize = sizeof(header)-1;
	char headerContents[8];
    FILE *fp; // declaration of file pointer
    char con[1000]; // variable to read the content
    fp = fopen("file.tin","r");// opening of file
    if (!fp) {
		return 1;
	};
	fread(header, bufferSize, 1, fp);
	header[8] = 0;
	printf(header);
	printf("\n");
    while (fgets(con,1000, fp)!=NULL)// reading file content
    printf("%s",con);
	printf("\n");
    fclose(fp); // closing file
    return 1;
}

int main() {
	printf("welcome!\n");
	while (getInput() && parseAndExecute());
	return 0;
}

	
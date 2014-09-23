#include <stdio.h>

int main() {
	FILE *newfile;

	newfile = fopen("data.txt", "r"); //fopen takes the file pointer as input, "r" means we want to read 							from the file
	for(int i = 0; i<5; i++){
		char c;
		c = fgetc(newfile); //fgetc() take the file pointer as input, output would be the char that 			newfile points to. newfile will then point to the next char.
		printf("%c", c); //print the char from data.txt on your screen	
	}
	
	fclose(newfile);
	return 0;
}

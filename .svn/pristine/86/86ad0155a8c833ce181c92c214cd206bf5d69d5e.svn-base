/* Sample code for Problem 4 */
#include <stdio.h>

void checkWord(int* w, int* s, int* m, char c[]);

int main()
{
    int wcount = 0;
    int scount = 0;
    int maxlen = 0; 
    FILE *infile;
    char candidate[80];

    infile = fopen("story.txt","r");
    if(infile == NULL)
    {
        printf("Error: File not found\n");
        return -1;
    }

    while (fscanf(infile,"%80s", candidate) == 1) 
    {
        checkWord(&wcount, &scount, &maxlen, candidate);
    }
    fclose(infile);

    printf("Statistics:\n"); 
    printf("\tLong word count: %d\n", wcount); 
    printf("\tSmall word count: %d\n", scount);
    printf("\tLength of longest word: %d\n", maxlen);

    return 0;
}

void checkWord(int* w, int* s, int* m, char c[])
{
 /*running out of time - every time I call checkWord, it resets x to 0, so it will only count
   the first word. Contemplated making a helper function to save the index, but ran out of time. 
   Also, the count is doing weird stuff for some reason, always getting 112. Perhaps I should've 
   implemented getchar() some how? */
    int count = 0;
    int temp = 0;
    int x = 0;

    	while(c[x]!= ' ') {
       		count++;
       		x++;
   	}
  	printf("count = %d\n", count);
	if(count >= 4) {
      		*w = *w+1;
    	}
   	
	else if(count < 4) {
       		*s = *s+1;
    	}
    	
	if(count > temp) {
         	temp = count;
    	}
    	printf("count = %d\n", count);
   *m = temp;
}


















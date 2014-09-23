#include<stdio.h>
#define N 128
int reverse(char in[], char out[]);

int main() {
    char input[N];
    //char inputStrings[N];
    //char output[N];
    int length;
    // prompt user to enter string, get user's input
    printf("Input a string: ");
    gets(input);
    /*for(int x=0; x<128; x++)
    {
	if(!input[x]){
	    break;
	}
        length++;
    }*/

    printf("Your string was: ");
    puts(input);


   /*for(int j = 0; j < length; j++) {
        printf("%c",input[j]);
    }*/
    
    for (int i = 0; i < N; i++) {
        input[i] = getchar(); 
        
        if (input[i] == '?' || input[i] == '.' || input[i] == '!' || input[i] == '\n' || 
            input[i] == ' ') {
            //length = i;
        }
    }  

    printf("Your string was: %s\n",input);
    // call reverse function
    // output returned string
    return 0;

}



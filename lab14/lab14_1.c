/*
 * This code should read a line and print out the alphanumeric and space
 * characters only. However, it does not behave as specified. Fix the code.
 * There are no syntax errors. Look for logic errors.
 */
#include <stdio.h>

int main()
{
    int echo = 0;
    //scanf("%s", &echo);
    while ((echo = getchar()) != '\n')
        //scanf("%c", &echo);
        putchar(echo);
        /*if ((echo > 'a' || echo < 'z') && (echo > 'A' || echo < 'Z'))
            putchar(echo); */
        if (echo == '.' || echo == '?' || echo == '!' || echo == ':' || echo == ';'){
            printf(" ");
        }
  
        
    return 0;
}

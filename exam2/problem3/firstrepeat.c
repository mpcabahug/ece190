/* Sample code for Problem 3 */
#include <stdio.h>

int firstRepeat(int* input, int size);

int main()
{
    int n = 5;
    int myArray[5] = {1, 2, 3, 4, 4};
    int fRepeat;
    fRepeat = firstRepeat(myArray, n);
    printf("First Repeating integer : %d\n", fRepeat);
    return 0;
}

int firstRepeat(int* input, int size)
{
    int *ptr = input;
    int *ptr2 = ptr++;
    int i = 0;
    int repeat = -1;
    while(i < size) {
        
        if(*ptr  == *ptr2) {
            repeat = *ptr;
	    break;
        }
        i++;
        ptr++;
        ptr2++;
    } 
    
    return repeat;  
}

#include <stdio.h>
#define N 10

struct maxima {
    int max;
    int min;
};
void setMinMax(int input[], struct maxima *ptr);

int main() {
    int List[N] = {4,5,10,19,-43,-3,19,33,34,2};
    struct maxima max_min_vals; //instantiate 

    setMinMax(List, &max_min_vals);
    int minInList = max_min_vals.min;
    int maxInList = max_min_vals.max; 
    printf("Min %d Max %d \n", minInList, maxInList);

}

/* want to modify the struct so we have to pass by pointer */
void setMinMax(int input[], struct maxima *ptr) {
        int temp = 0;
        int temp2 = 0;
       
        //find max
        for (int q = 0; q < N; q++)
        {
            if(input[q] >temp)
            temp = input[q];
        }  
        ptr->max = temp;
        
        //find min    
        for (int p = 0; p < N; p++)
        {
            if(input[p] < temp2)
            temp2 = input[p];
        } 
        ptr->min = temp2;
}

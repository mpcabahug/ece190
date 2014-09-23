#include<stdio.h>
#define NUM 3

int main()
{
    int array_u [NUM];
    int array_v [NUM];
    int array_result [NUM];
    /*input array_u*/
    printf("Input array_u\n");
    for(int i =0; i <NUM; i++) 
    {
        int tmp;
        int num = i +1;
        printf("array_u %d input: ",num);
        scanf("%d", &tmp);
        array_u[i] = tmp;
    }

    printf("Input array_v\n");
    for(int j =0; j <NUM; j++) 
    {
        int tmp1;
        int num = j +1;
        printf("array_v %d input: ",num);
        scanf("%d", &tmp1);
        array_v[j] = tmp1;
    }

    /*compute array result*/
    array_result[0]  = (array_u[1] * array_v[2]) - (array_v[1] * array_u[2]);
    int ar2 = (array_u[0] * array_v[2]) - (array_v[0] * array_u[2]);
    array_result[1] = ar2 * -1;
    array_result[2] = (array_u[0] * array_v[1]) - (array_v[0] * array_u[1]);
    printf("%d %d %d\n", array_result[0], array_result[1], array_result[2]);
} 

/* 
    Name: Michelle Cabahug
    NetID: cabahug2
    Lab Section: AD9 (11am)
*/

#include <stdio.h>

int main() {
    float A;
    float B;
    float C;
    float a;
    float b;
    float N;
    float left_sum = 0;
    float right_sum = 0;
    float middle_sum = 0;
    float avg_sum = 0;
	
    // Intro
    printf("\nRiemann Sum Calculator:\n");
    printf("    Approximate the integration of\n");
    printf("    a polynomial Ax^2+Bx+C\n");
    printf("    over a<=x<=b with N rectangles!\n\n");
    // Inputs
    printf("Input A: ");
    scanf("%f", &A);
    printf("Input B: ");
    scanf("%f", &B);
    printf("Input C: ");
    scanf("%f", &C);
    printf("Input a: ");
    scanf("%f", &a);
GETB:   printf("Input b: ");
        scanf("%f", &b);
            if (b <= a)
            {
                 printf("    Please ensure b>a\n");
                 goto GETB;
            }
GETN:   printf("Input N: ");
	scanf("%f", &N);
            if (N < 1 || N == 0 ) 
            {
                printf("    Please ensure N>0\n");
                goto GETN;			
            }
    //commented out function calls
    //left_sum =  riemann( a,  b,  N,  A,  B,  C,  'L');
    //right_sum = riemann( a,  b,  N,  A,  B,  C,  'R');
    //middle_sum = riemann( a,  b,  N,  A,  B,  C, 'M');
    //avg_sum = (left_sum + right_sum + middle_sum) / 3;

    printf("\nResults:\n");
    printf("    left method sum = %f\n",left_sum);
    printf("    right method sum = %f\n",right_sum);
    printf("    middle method sum = %f\n",middle_sum);
    printf("    average sum = %f\n", avg_sum);
    printf("\n");
	
    return 0;

}

/*
    Name: Michelle Cabahug
    NetID: cabahug2
    Lab Section: AD9 (11am)
*/

#include <stdio.h>

float polynomial(float A, float B, float C, float x) {
/*
    This method evaluates and returns 
    A*x^2 + B*x + C 
*/
    float a_val = A*x*x;
    float b_val = B*x;
    float poly = a_val + b_val + C;
    return poly;
}

float riemann(float a, float b, int N, float A, float B, float C, char method){
/*
    This method returns the riemann sum of a polynomial. 
    The parameter 'method' determines what type of riemann 
    sum to calculate: left, right, or middle.

*/

    float result = 0;
    float dx = b-a;
    dx = dx / N;    //delta X = (b-a)/N

    if(method == 'L') //calculating left riemann sum
    {  
        for(int n =0; n < N; n ++) 
        {
            float ndx = n*dx;
            float a_plus_ndx = a + ndx;
            float poly_L = polynomial(A,B,C,a_plus_ndx);
            result += poly_L;
        }
        result = result * dx;
    }

    else if(method == 'R')  //calculating right riemann sum
    {
        for(int n =1; n <= N; n ++) 
        {
            float ndx = n*dx;
            float a_plus_ndx = a + ndx;
            float poly_R = polynomial(A,B,C,a_plus_ndx) ; 
            result += poly_R;
        }
        result = result * dx;
    }

    else if(method == 'M')  //calculating middle riemann sum
    {
        for(int n =1; n <= N; n ++) 
        {
            float k = (n - 0.5);
            k = k * dx;
            float ck = a + k;
            float poly_M = polynomial(A,B,C,ck)*dx; 
            result += poly_M;
        }
    }

   return result; //end of riemann function
}

int main() {
    float A;
    float B;
    float C;
    float a;
    float b;
    float N;
    float left_sum;
    float right_sum;
    float middle_sum;
    float avg_sum;
	
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

    left_sum =  riemann( a,  b,  N,  A,  B,  C,  'L');
    right_sum = riemann( a,  b,  N,  A,  B,  C,  'R');
    middle_sum = riemann( a,  b,  N,  A,  B,  C, 'M');
    avg_sum = (left_sum + right_sum + middle_sum) / 3;

    printf("\nResults:\n");
    printf("    left method sum = %f\n",left_sum);
    printf("    right method sum = %f\n",right_sum);
    printf("    middle method sum = %f\n",middle_sum);
    printf("    average sum = %f\n", avg_sum);
    printf("\n");
	
    return 0;

}

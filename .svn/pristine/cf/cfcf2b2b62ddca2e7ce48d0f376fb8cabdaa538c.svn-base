/* Sample code for Problem 2 */
#include <stdio.h>

typedef struct rawFloat
{
    unsigned char negative;
    unsigned int exponent;
    unsigned int fractional;
} rawFloat;

double mult(rawFloat alpha, rawFloat beta)
{
    char asign = alpha.negative;
    int aexp = alpha.exponent;
    int afract = alpha.fractional;   

    char bsign = beta.negative;
    int bexp = beta.exponent;
    int bfract = beta.fractional;

    double mult = afract*bfract;
    mult = mult * asign * bsign;
    int newExp = aexp + bexp;
    newExp = 2 ^ newExp;
    mult = mult * newExp;
    return mult;
}

int main()
{
    double m = 0;
    rawFloat alpha = {1, 23, 450};
    rawFloat beta = {1, 23, 450};
    m = mult(alpha,beta);
    
    return 0;
}

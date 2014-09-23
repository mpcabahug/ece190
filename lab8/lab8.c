#include <stdio.h>
#include <math.h>

int dist(float x1, float x2, float y1, float y2);
int main()
{
    float x1_in, y1_in, x2_in, y2_in;
    float distance;

    printf("Enter the x value for point 1: ");
    scanf("%f",&x1_in);
    printf("Enter the y value for point 1: ");
    scanf("%f",&y1_in);
    printf("Enter the x value for point 2: ");
    scanf("%f",&x2_in);
    printf("Enter the y value for point 2: ");
    scanf("%f",&y2_in);

    distance = dist(x1_in,x2_in,y1_in,y2_in);

    printf("Euclidean distance = %f\n",distance);

    return 0;
}

int dist(float x1, float x2, float y1, float y2)
{
	float result;
	float xd;
	float yd;

	xd = (x2-x1);
	xd = xd*xd;
	yd = (y2-y2);
	yd = yd*yd;

	result = sqrt(xd + yd);
	
	return result;

}

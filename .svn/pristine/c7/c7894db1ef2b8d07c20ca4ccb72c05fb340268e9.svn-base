#include "paths.h"
#include <math.h>
int Calc(int x_coord,int y_coord);
int count_shortest_paths(int start_x, int start_y, int end_x, int end_y)
 
/*! Given starting point (start_x, start_y) and ending coordinates
 
(end_x, end_y) on a 2D grid of city blocks, determine the number of
 
 shortest paths from the start to the end.
 
*/
 
{
    int count=0;
    
    if(((start_x+start_y)&1)!=((end_x+end_y)&1)){
        start_y++;
        count++;
    }
    return count+Calc(end_x-start_x,end_y-start_y);
 
}
int Calc(int x_coord,int y_coord) {
    if(x_coord < 0) {
        x_coord = x_coord *-1;
    }

    if(y_coord < 0) {
        y_coord = y_coord *-1;
    }
    
    if(x_coord >= y_coord){ 
        return x_coord;
    }
    
    int z=(x_coord+y_coord)/2;
    int q = x_coord -z;
    if(q < 0) {
        q = q *-1;
    }
    
    return z+q;
}

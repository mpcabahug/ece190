/*
 Name: Michelle Cabahug
 NetID: cabahug2
 Lab Section: AD9
*/

#include <stdio.h>
#include <stdlib.h>

// define the size of the matrix array
#define NUM_V 10
#define NUM_E 9

// functions and global variables
int graph[NUM_V][NUM_V];                      // This is the adjacency matrix you need to fill in.
int graph_reading (const char* filename);
void graph_print();
int pathlength(const int origin,const int destination, int list[]);


// read in Graph and Generate the adjacency matrix in Memory, return 1 if the file doesn't exist//
int graph_reading (const char* filename)
{
/* Reads in a file. Checks that "h" is a header. Write the graph array accordingly.*/
    FILE* file_Reading;
    int a,b,prev_A, prev_B, num_Nodes, num_Edges;
    file_Reading = fopen(filename, "r");
    
    if(!file_Reading)
    {
        return 1;
    }
        
    if(!(fgetc(file_Reading)) == 'h')
    { 
        printf("Invalid file type.");
            return 1;
    }
    
    fscanf(file_Reading, "%d %d", &num_Nodes,&num_Edges);
    
    while(1) 
    {
            
        fscanf(file_Reading, "%d %d", &a,&b);
            
        if(prev_A == a && prev_B == b){ break;}
        graph[a-1][b-1] = 1;
        graph[b-1][a-1] = 1;
        prev_A = a;
        prev_B = b;
    }
   
    return 0;
}


// print adjacency matrix on the screen
  void graph_print()
{
    /*using two for loops to iterate through and print each index of the graph matrix*/
    for(int index_A = 0; index_A < NUM_V; index_A++)
    {
        for(int index_B = 0; index_B < NUM_V; index_B++)
        {
            printf("%d", graph[index_A][index_B]);
        }
        printf("\n");
    }
    return;
}


// find the shortest path length
int pathlength(const int origin,const int destination, int list[])
{ 
/* int pathlength is a recursive function that finds the shortest path length on the graph, while keeping
   track of verticies we have already visited in an array, list[].
*/
    int current_Index = 0;
    int shortest_Length = 100000;
    int length = 100000;
    int x_In_D = 0;
    while(list[current_Index]) //fill list but don't overwrite, find/use next free index
    {
        current_Index++;
    }
    
    list[current_Index] = origin;

    for(int x=0; x<NUM_V; x++)
    {
	x_In_D = 0;
        if(graph[origin][x])
        {
            if(x == destination)
            {
                return 1; // if destination is an option, return 1
            }    
            for(int d = 0; d < current_Index; d++) // loop through and check which new paths are available
            {
                if(list[d] != x)
                {
                        continue;
                }
                else{
                    x_In_D = 1; //if x is in d then don't do a call using that x
                    break;
                }
            }
            if(!x_In_D)
            {
                length = 1+pathlength(x,destination,list); // call length function recursively
                if(pathlength(x,destination,list) == 0)
                {
                    //do nothing
                }
                else if(length < shortest_Length) //use shortest length
                {
                    shortest_Length = length;
                }
            }

            
        }
        
    }
    if(shortest_Length == 100000){
        return 0;
    }
    return shortest_Length;
}

// main function: display the right messages. Please refer to MP5 requirement
 int main(int argc, const char **argv) { 
/* If only 1 argument in main i.e. user tries to run ./mp5, the program ends and asks the user to include
   a file name.
   If the file name doesn't exist, we print an error and end the program. 
   If the file does exist, we call the functions.
*/

    int origin; 
    int dest; 
    int plength; 
    if(argc == 1) { 
        printf("Please enter: ./mp5 <inputFile>\n");
        return 0; 
    }
    
    int read_Graph = graph_reading(argv[1]);
    if(read_Graph == 1 && argc > 1) { 
        printf("The file doesn't exist!\n");
        return 0;
    }

    if(read_Graph != 1 && argc > 1) { printf("Input graph is loaded!\n"); }

    graph_print(); 
    printf("Please input the origin.\n"); 
    scanf("%d",&origin); 
    printf("Please input the destination.\n"); 
    scanf("%d",&dest);

    int *hello = malloc(NUM_V*sizeof(int)); 
    plength = pathlength(origin,dest,hello); 
    if(plength == 0) { 
        printf("%d and %d are separated forever!\n", origin,dest); 
    } 
    else { 
        printf("%d needs %d steps to get to %d.\n", origin,plength,dest); } 
        return 0; 
    }
  

     

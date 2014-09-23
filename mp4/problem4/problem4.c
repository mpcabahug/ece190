#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10 /* Maximum size */
int stack[MAX_SIZE]; /* Global array of size MAX_SIZE */
int top; /* Index of top of the stack */
void push(int item); /* Function to push an item onto the stack */
int pop(); /* Function to pop an item from the stack */
void display(); /* Function to display the items in stack */

int main()
{
    top = -1;
    int choice, item;
    while(1)
    {
        choice = 0;
        printf("------------------------------------\n");
        printf("Options\n");
        printf("1)Push\n");
        printf("2)Pop\n");
        printf("3)Display\n");
        printf("4)Exit\n");
        printf("------------------------------------\n");
        printf("Enter an option: ");
        
        if(scanf("%d", &choice) == 0) {
        printf("\nInvalid input. Aborting...\n");
        exit(-1);
        }

    switch(choice) {
        case 1: printf("Enter the item to push: ");
        scanf("%d", &item);
        push(item);
        break;
        case 2: item = pop();
        printf("Popped %d\n", item);
        break;
        case 3: display();
        break;
        case 4: exit(0);
        default:printf("Invalid choice. Try again\n");
    }
}
return 0;
}

void push(int item) {
    if (top == (MAX_SIZE - 1))
    {
        printf("STACK OVERFLOW");
    }
    top = top +1;
    stack[top] = item;
    return;
}

int pop() {
    if (top == -1)
    {
        printf("STACK UNDERFLOW");
    }
    
    int retval = stack[top]; 
    top = top -1;
    return retval;
}

void display(){
    for(int i = 0; i < top+1; i++) {
        printf("[%d]",stack[i]);
    }
    return;
}



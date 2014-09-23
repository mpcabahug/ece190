#include<stdio.h>
int Tribon (int input);


int main() {
    int n;
    int result;
    printf("input n: ");
    scanf("%d", &n);
    result = Tribon(n); 
    printf("%d th Tribonacci is %d\n", n, result);
}


int Tribon(int input) {
    int result = 0;

    //base cases
    if (input == 0){
        return  0;
    }

    else if (input == 1){
        return 1;
    }

    else if (input == 2){
        return 1;
    }

    result += Tribon(input-1) + Tribon(input -2) + Tribon(input -3);
    return result;
}


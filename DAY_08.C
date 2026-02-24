//Problem: Given integers a and b, compute a^b using recursion without using pow() function.
#include <stdio.h>

// Recursive function to calculate a^b
long long int power(int a, int b)
{
    if(b == 0)
        return 1;           // Base case
    
    return a * power(a, b - 1);   // Recursive case
}

int main()
{
    int a, b;
    
    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);
    
    long long int result = power(a, b);
    
    printf("%lld\n", result);
    
    return 0;
}

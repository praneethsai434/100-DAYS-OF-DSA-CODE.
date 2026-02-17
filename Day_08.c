//Problem 8: Given integers a and b, compute a^b using recursion without using pow() function.
#include <stdio.h>
long long int power(int a, int b)
{
    if(b == 0)
        return 1;
    return a * power(a, b - 1);
}

int main()
{
    int a, b;
    
    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);
    
    long long int result = power(a, b);
    
    printf("%d raised to power %d is: %lld\n", a, b, result);
    
    return 0;
}

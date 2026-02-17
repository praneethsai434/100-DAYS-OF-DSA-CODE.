//Problem 9: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    
    printf("Enter a lowercase string: ");
    scanf("%s", str);
    
    int start = 0;
    int end = strlen(str) - 1;
    
    while(start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        
        start++;
        end--;
    }
    
    printf("Mirrored string: %s\n", str);
    
    return 0;
}

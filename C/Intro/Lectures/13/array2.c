#include <stdio.h>
#include <string.h>

int main()
{
    char fullName[3] [20];

    printf("Please enter your first, then middle, then last name: ");
    
    for(int g = 0; g < 3; g++)
    {
        gets(fullName[g]);
    }
    
    printf("Your full name is: ");
    
    for(int x = 0; x < 3; x++)
    {
        printf("%s ", fullName[x]);
    }
    return 0;
}

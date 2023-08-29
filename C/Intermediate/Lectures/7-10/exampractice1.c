#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool value1 = true;
    bool value2 = false;

    printf("value1 is %d\nvalue2 is %d\n", value1, value2);
    // value1 will output 1 and value2 will output 0

    int num1 = 9, num2 = 9;
    bool check = num1 < num2;

    printf("check is %d\n", check);
    // should output 1 since num1 is greater than num2

    if(!check)
    {
        printf("num2 is not less than num1\n");
    }
    else if(check)
    {
        printf("num1 is larger than num2\n");
    }

    return 0;
}
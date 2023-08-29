#include <stdio.h>

int heartbeat(int);
int main()
{
    int age, max;
    printf("Please enter your age: ");
    scanf("%d", &age);

    max = heartbeat(age);
    printf("Your maximum heartbeat is: %d", max);

    return 0;
}

int heartbeat(age)
{
    return 220-age;
}

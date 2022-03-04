#include <stdio.h>
#include <stdlib.h>

int x = 0;
int fun(int n)
{
    //declaring static variable
    //static int x = 0;
    if(n > 0)
    {
        x++;
        return fun(n - 1) + x;

        //return fun(n - 1) + n;
    }
    return 0;
}
int main()
{
    int a = 5;
    printf("%d\n", fun(a));
    printf("%d\n", fun(a));
    return 0;
}

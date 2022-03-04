#include <stdio.h>
#include <stdlib.h>

void fun(int n)
{
    if(n > 0)
    {
        //tail recursion
        //printf("%d", n);
        //fun(n-1);
        //head recursion
        fun(n-1);
        printf("%d", n);

    }
}

int main()
{
    int x = 3;
    fun(x);
    return 0;
}

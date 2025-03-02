#include<stdio.h>

int add(int x,int y)
{
    int sum=x+y;
    return sum;
}

int main()
{
    int x=2,y=3;
    int sum=add(x,y);
    printf("%d",sum);
}

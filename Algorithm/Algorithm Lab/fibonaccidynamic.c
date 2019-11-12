#include<stdio.h>
int fib[1000];

int fibonacci(int n)
{
    fib[0]=fib[1]=1;
    int i;
	if (n==0 || n==1)
	{
        return 1;
	}
	for(i=2;i<=n;i++)
    {
        fib[i] = fib[i - 2] + fib[i - 1];
    }
	return fib[n];

}
int main()
{
    int res,n=8;
    res = fibonacci(n);
    printf("%d",res);
    return 0;
}

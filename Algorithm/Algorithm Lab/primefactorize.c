#include<stdio.h>
int prime[100],List[100];

int PrimeFactorize( int n )
{
    int listSize = 0,i;
    for(i = 0; prime[i] <= n;i++)
    {
        if (n % prime[i] == 0 )
        {
            while(n % prime[i] == 0 )
            {
                n /= prime[i];
                List[listSize] = prime[i];
                listSize++;
            }
        }

    }
    return listSize;
}
int main()
{
    int a,b=10;
    a = PrimeFactorize(b);
    printf("%d",a);
    return 0;
}

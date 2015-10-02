#include<iostream>
using namespace std;
long long n;
long long *a;
long long count;
long long *fib;

void f(long long index, long long current_length)
{
    if(index == n)
    {
        return;
    }

    if(a[index] == fib[current_length])
    {
        count++;
        f(index+1,current_length+1);
        f(index+1,current_length);
    }
    else
    {
        f(index+1,current_length);
    }
}

int main()
{
    count = 0;

    cin>>n;
    a = new long long[n];
    for(long long i=0;i<n;++i)
    {
        cin>>a[i];
    }

    fib = new long long[n];
    fib[0]=1;
    fib[1]=1;
    for(long long i=2;i<n;++i)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }

    f(0,0);

    cout<<count;

    return 0;
}
#include<iostream>
#include<cmath>
using namespace std;

double getDistance(double x, double y, double r, double x1, double y1)
{
    double square = (x-x1)*(x-x1) + (y-y1)*(y-y1);
    if(square>r*r)
        return 0.0;

    return sqrt(square);
}

int main()
{
    double max = 0.0;
    int x1,y1;

    double x,y,r;
    cin>>x>>y>>r;

    x1=x;
    y1=y;

    double tmp;

    for(int i=(int)(x+r+1);i>=(int)(x-r);--i)
        for(int j=(int)(y+r+1);j>=(int)(y-r);--j)
    {
        tmp = getDistance(x,y,r,i,j);
        if(tmp>max)
        {
            max = tmp;
            x1=i;
            y1=j;
        }
    }

    cout<<x1<<' '<<y1;

    return 0;
}
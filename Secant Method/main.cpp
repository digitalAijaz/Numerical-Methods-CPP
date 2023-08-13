///Root of an equation using secant method
#include <iostream>
#include<cmath>

using namespace std;

double f(double x)
{
    double a=pow(x,3)-x-11.0;
    return a;
}

double secant (double a, double b, double e)
{
    double c;

    while(1)
    {

        c= a-f(a)*((b-a)/(f(b)-f(a)));
        a=b;
        b=c;

        if (fabs(b-a)<e)
            return c;

    }
}

int main()
{
    double a,b,e,root;

    cout<<"Enter the initial guess for a: "<<endl;
    cin>>a;
    cout<<"Enter the initial guess for b: "<<endl;
    cin>>b;
    cout<<"Enter the precision value:"<<endl;
    cin>>e;

    root=secant(a,b,e);
    cout<<"Root using secant method is: "<<root<<endl;

    return 0;
}

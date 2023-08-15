#include <iostream>
#include<cmath>

using namespace std;

double f(double x)
{
    double a = 1/(1+x*x);
    return a;
}

double simpsonOneByThree(double a, double b, int n)
{
    double integral, h;
    h=(b-a)/n;
    double sum=0;
    double t;
    sum = f(a)+ f(b);

    for (int i=1; i<n; i++)
    {
        a = a+i*h;
        if (i%2==0)
            t= 2.0*f(a);
        else t= 4.0*f(a);
        sum = sum + t;
        }
    integral = (h/3.0)*sum;
    return integral;
}


int main()
{   cout.precision(4);
    double a,b, integral;
    cout << "Enter the Lower and Upper Limits for integration" << endl;
    cin>>a>>b;
    cout<<"Enter even number of subintervals\n";
    int n;
    cin>>n;
     integral = simpsonOneByThree(a,b,n);
    cout<<"Integral using Simpson Rule is: "<<integral<<endl;
    return 0;
}

///Definite Integral using Trapezoidal Rule

#include <iostream>
#include<math.h>

using namespace std;

double f(double x)
{
    double a = 1/(1+ x*x);
    return a;
}

double trapezoidal (double a, double b, int n)
{
    double integral, sum;
    sum = f(a)+f(b);
    double delta;


    delta = (b-a)/n;
    for (int i=1; i<n; i++)
    {
        //a= a+i*delta;
        sum= sum + 2.0*f(a+i*delta);
    }


    integral = sum*delta/2.0;

    return integral;
}


int main()
{
    double a,b, sum;
    cout << "Enter the Lower and Upper Limits for integration" << endl;
    cin>>a>>b;
    cout<<"Enter the number of subintervals\n";
    int n;
    cin>>n;

    sum= trapezoidal (a,b,n);

    cout<<"Integral using Trapezoidal Rule is "<<sum<<endl;

    return 0;
}

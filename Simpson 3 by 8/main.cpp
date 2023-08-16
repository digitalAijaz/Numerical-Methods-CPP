#include <iostream>
#include<cmath>

using namespace std;

double f(double x)
{
    double a = 1/(1+x*x);
    return a;
}

double simpson3By8(double a, double b, int n)
{
    double integral, h;
    h=(b-a)/n;
    double  sum =f(a)+f(b);

    for (int j=1;j<n;j++)
    { if (j%3==0)
     sum +=  2*f(a+j*h);

     else
     sum += 3*f(a+j*h);
    }
    integral = 3.0*h/8*(sum);



    return integral;
}


int main()
{
    cout.precision(4);
    double a,b, integral;
    cout << "Enter the Lower and Upper Limits for integration" << endl;
    cin>>a>>b;
    cout<<"Enter number of subintervals (must be multiple of 3)\n";
    int n;
    cin>>n;
    integral = simpson3By8(a,b,n);
    cout<<"Integral using Simpson Rule is: "<<integral<<endl;
    return 0;
}

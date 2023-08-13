//Program for finding root using Newton Raphson Method

#include <iostream>
#include<cmath>

using namespace std;

double f(double x)
{
    //double a= pow(x,3.0)-x-11.0;
    double a = 3*x + sin(x) - pow (M_E,x);
    return a;
}

double fprime (double x)
{
    double b= 3 + cos(x)- pow (M_E,x);
    return b;
}

double newtonRaphson (double a, double e)
{
    double root;
    while (1)
    {
        if (fprime(a))
        {
            root = a-f(a)/fprime(a);
            if (fabs(root-a)<e)
                return root;
            a=root;
        }
    }

}

int main()
{
    double a,e, root;
    cout << "Enter Initial guess" << endl;
    cin>>a;
    cout<<"Enter Precision\n";
    cin>>e;

    root= newtonRaphson(a,e);
    cout<<"Root Using Newton Raphson Method is "<<root<<endl;
    return 0;
}

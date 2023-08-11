//Program FOR BISECTION METHOD: TO FIND ROOT OF AN EQUATIO
#include <iostream>
#include<cmath>


using namespace std;


double f (double x)    //function for providing equation
{
    double a=pow(x,3)-x-11.0;    //write the equation whose roots are to be determined
    return a;
}

double bisection (double a, double b, double e)
{
    double c,fa,fb,fc;
    while (f(a)*f(b)>0)
    {
        cout<<"Enter the initial guess of a=";
        cin>>a;

        cout<<"Enter the initial guess of b=";
        cin>>b;
    }


    if ((f(a)*f(b))<0)
    {
        while (fabs(a-b)>=e)
        {
            c=(a+b)/2.0;
            fa=f(a);
            fb=f(b);
            fc=f(c);
            if (fc==0)
            {
            }
            if (fa*fc>0)
                a=c;
            else if (fa*fc<0)
                b=c;

        }
    }
    return c;
}

int main()
{
    // cout.precision(5);
    // cout.setf(ios::fixed);

    double a,b,e,root;
    cout<<"Enter the initial guess of a=";
    cin>>a;

    cout<<"Enter the initial guess of b=";
    cin>>b;

    cout<<"Enter the degree of Accuracy required"<<endl;
    cin>>e;

    root = bisection (a, b, e);
    cout<<"Root is "<<root<<endl;
    return 0;
}

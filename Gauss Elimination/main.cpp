#include <iostream>
#include<iomanip>

using namespace std;


int main()
{
    cout.precision(4);
    cout.setf(ios::fixed);
    int n;
    cout<<"Enter the number of equations\n";
    cin>>n;

    float a[n][n+1];
    cout<<"Enter the elements of the Augmented Matrix\n";

    for (int i=0; i<n; i++)
        for (int j=0; j<n+1; j++)
            cin>>a[i][j];




    ///Partial pivotization to make diagonal element greater than elements below it

    for (int i =0; i<n; i++)
        for (int k=i+1; k<n; k++)
            if(a[i][i]<a[k][i])   //swap rows
                for (int j=0; j<=n; j++)
                {
                    double temp = a[i][j];
                    a[i][j]= a[k][j];
                    a[k][j]= temp;
                }

    cout<<"\nThe matrix after partial pivotization is\n";
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n+1; j++)
        {
            cout<<a[i][j]<<"\t\t\t";
        }
        cout<<endl;
    }

    ///Gauss Elimination

    for (int i =0; i<n; i++)
        for (int k=i+1; k<n; k++)
        {
            double t= a[k][i]/a[i][i];
            for (int j=0; j<n+1; j++)
                a[k][j]=a[k][j]-t*a[i][j];
        }

    cout<<"The Matrix after Gauss Elimination is\n";

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n+1; j++)
           {
              cout<<a[i][j]<<"\t\t\t";
           }
        cout<<endl;
    }

    ///Back-Substitution
    float x[n], y[n];
    for (int i=0; i<n; i++)
        x[i]= a[i][n];


    int t;
    for (int i =n-1; i>=0; i--)
    {
        t=0;
        for (int j=i+1; j<n; j++)
            t = t+ a[i][j]*y[j];

        y[i]= (x[i]-t)/a[i][i];

    }

    cout<<"\nThe values of variable are as follows:\n";
    for (int i=0; i<n; i++)
        cout<<y[i]<<endl;

    return 0;

}

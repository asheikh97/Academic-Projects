#include <iostream>
#include <cmath>
using namespace std;

int sign(double);

int main()
{
    double a,b,c,discriminant,x1,x2;
    
    cout << "Enter three coefficients (a,b,c) to find roots of a qaudratic equation." << endl;
    cin >> a >> b >> c;
    discriminant = pow(b,2) - (4*a*c);
    
    if(a == 0)
        cout << "Not quadratic equation!" << endl;

    if(discriminant < 0)
        cout << "No real roots exist.";
    
    if(a != 0 && discriminant >= 0 )
    {
        x1 =  (-b - sign(b)*(sqrt(discriminant))) / (2*a);
        x2 = c / (a * x1);
        
        cout << "The two roots are " << x1 << " and " << x2 << endl;
    }

    return 0;
}

int sign(double b)
{
    return b/fabs(b);
}


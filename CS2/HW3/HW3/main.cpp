//  HW3
// Abadali Sheikh

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double power(double,int);

int main()
{
    double x, i = 1;
    double term = 1.0, old_sum = 0, new_sum = term ;
    
    do
    {
        cout << "Enter a value for"
             << " -π/2(-1.5707) ≤ X ≤ π/2(1.5707)" << endl;
        cin >> x;
    }   while(fabs(x) > (M_PI/2));
    
    while(old_sum != new_sum)
    {
        old_sum = new_sum;
        term *= (-power(x,2)) / ((i+1)*i);
        new_sum += term;
        i+=2;
    }
    
    cout << fixed << setprecision(4);
    cout << "My Cos(" << x << ") = " << new_sum << endl;
    cout << "Built-in Cos(" << x << ") = " << cos(x) << endl;
    
    return 0;
}

double power(double base, int exponent)
{
    double result = 1;
    
    for(int i = 1; i <= exponent; i++)
        result *= base;

    return result;
}

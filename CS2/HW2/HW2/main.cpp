// Abadali Sheikh
// Due date 2/13/17
// HW2

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int factorial(int);
double power(double, int);
int sqaureSum(int num);


int main()
{
    cout << endl << sqaureSum(5) << endl;
    
    
   /* long double term = 1.0, old_sum = 0, new_sum = term;
    int k = 0;
    
    cout << "'x'" << setw(14) <<"My e^x" << setw(14) << "Real e^x" << endl;
    
    for(long double i = 2; i <= 10; i+=2)
    {
        while(old_sum != new_sum)
        {
            old_sum = new_sum;
            term *= ((i)/(k+1));
            new_sum += term;
            ++k; // needs to be fixed
        }
        cout << showpoint << fixed << setprecision(4);
        cout << setw(2) << i;
        cout << setw(14) << new_sum ; // my e^x
        cout << setw(14) << exp(i) << endl; // real e^x
    } */
    
    

    return 0;
}

int sqaureSum(int num)
{
    if(num == 0)
        return 0;
    else
        return sqaureSum( num - 1 ) + (num * num);
}

int factorial(int n)
{
    int result = 1;
    
    for(int i = 2; i <= n; ++i)
        result = result*i;
    
    return result;
}

double power(double base, int exponent)
{
    double result = 1;
    
    for(int i = 1; i <= exponent; ++i)
        result *= base;
    
    return result;
}











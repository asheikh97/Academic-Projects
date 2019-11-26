// Abadali Sheikh
// HW6 due 3/9/17

#include <iostream>
#include <iomanip>

using namespace std;

unsigned int seed = int (time(0));
const int SIZE = 8;
double random(unsigned int& seed);
void fill_array(int[]);
void buble_sort(int[]);
void swap(int&, int&);
void print(int[]);

int main()
{
    int num_set[SIZE];
    fill_array(num_set);
    print(num_set);
    buble_sort(num_set);
    print(num_set);
    
    return 0;
}

double random(unsigned int &seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;
    seed  = ((MULTIPLIER *seed) + INCREMENT) % MODULUS;
    
    return double (seed)/double(MODULUS);
}

void swap(int &num1,int &num2)
{
    int temp = num2;
    num2 = num1;
    num1 = temp;
}

void buble_sort(int a[])
{
    bool sort_incomplete = true;
    
    while(sort_incomplete)
    {
        sort_incomplete = false;
        
        for(int i = 0; i < SIZE-1; i++)
            if(a[i] > a[i+1])
            {
                swap(a[i], a[i+1]);
                sort_incomplete = true;
            }
    }
}

void fill_array(int a[])
{
    for(int i = 0; i < SIZE; i++)
        a[i] = 2 + (11 *(random(seed)));
}

void print(int a[])
{
    for(int i = 0; i < SIZE; i++)
        cout << setw(3) <<  a[i];
    cout << endl;
}

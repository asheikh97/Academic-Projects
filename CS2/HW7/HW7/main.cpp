// Abadali Sheikh
// HW7 due 3/9/17

#include <iostream>
#include <iomanip>

using namespace std;
unsigned int seed = int (time(0));
double random(unsigned int& seed);

const int SIZE = 10;
void print(int[][SIZE]);
void generate_adjacency_matrix(int[][SIZE]);

int main()
{
    int adj_matirx[SIZE][SIZE];
    
    generate_adjacency_matrix(adj_matirx);
    print(adj_matirx);

    return 0;
}

double random(unsigned int &seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;
    seed  = ((MULTIPLIER*seed) + INCREMENT) % MODULUS;
    
    return double (seed)/double(MODULUS);
}

void print(int a[][SIZE])
{
    for(int row = 0; row < SIZE; row++)
    {
        for(int col = row; col < SIZE; col++)
            cout << setw(3) << a[row][col];
        cout << endl;
    }
    cout << endl; 
}

void generate_adjacency_matrix(int a[][SIZE])
{
    for(int row = 0; row < SIZE; row++)
        for(int col = row; col < SIZE; col++)
        {
            if(col == row)
                a[row][col] = 0;
            else
                a[row][col] = int(2*random(seed));
            a[col][row] = a[row][col];
        }
}

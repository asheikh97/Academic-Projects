// Abadali Sheikh
// HW #8 due 3/27/17

#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 10;

unsigned int seed = int (time(0));
double random(unsigned int& seed);

void generate_adj_matrix(int a[][SIZE][SIZE]);
void print(int,int a[][SIZE][SIZE]);
bool vertices_connect(int, int, int&, int a[][SIZE][SIZE]);
void matrix_powers(int, int a[][SIZE][SIZE]);

int main()
{
    int vert1, vert2, dim = 0;
    int adj_matirx[SIZE][SIZE][SIZE];
    bool connected;
    
    generate_adj_matrix(adj_matirx);
    cout << "The adjancey matrix is: " << endl;
    print(dim, adj_matirx);
    
    do
    {
        cout << "Enter two vertices v1 and v2:" << endl;
        cin >> vert1 >> vert2;
        
    }   while ((vert1 < 1)|| (vert1 > SIZE) || (vert2 < 1) || (vert2 > SIZE));
    
    cout << "Vertices entered are (" << vert1 << "," << vert2 << ")" << endl;
    
    connected = vertices_connect(vert1, vert2, dim ,adj_matirx);

    if(connected)
        cout << "Vertices connect with a path of legnth " << dim << '.' << endl;
    if(!connected)
        cout << "Vertices do not connect." << endl;
    
    return 0;
}

void generate_adj_matrix(int a[][SIZE][SIZE])
{
    for(int row = 0; row < SIZE; row++)
        for(int col = row; col < SIZE; col++)
        {
            if(col == row)
                a[0][row][col] = 0;
            else
                a[0][row][col] = int(2*random(seed));
            a[0][col][row] = a[0][row][col];
        }
}

void print(int plane_num, int a[][SIZE][SIZE])
{
    for(int row = 0; row < SIZE; row++)
    {
        for(int col = 0; col < SIZE; col++)
            cout << setw(3) << a[plane_num][row][col];
        cout << endl;
    }
    cout << endl;
}

void matrix_powers(int plane_num, int a[][SIZE][SIZE])
{
    for(int row = 0; row < SIZE; row++)
        for(int col = 0; col < SIZE; col++)
        {
            a[plane_num][row][col] = 0;
            for(int k = 0; k < SIZE; k++)
                a[plane_num][row][col] += a[0][row][col] * a[plane_num-1][k][col];
        }
}

bool vertices_connect(int v1, int v2, int &dimnum, int a[][SIZE][SIZE])
{
    int plane = 0;
    bool connected = false;
    
    while (!connected && plane <= SIZE)
    {
        if(a[plane][v1-1][v2-1] != 0)
        {
            dimnum = plane;
            connected = true;
        }
        else
        {
            ++plane;
            matrix_powers(plane, a);
        }
    }
    return connected;
}

double random(unsigned int &seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;
    seed  = ((MULTIPLIER*seed) + INCREMENT) % MODULUS;
    
    return double (seed)/double(MODULUS);
}



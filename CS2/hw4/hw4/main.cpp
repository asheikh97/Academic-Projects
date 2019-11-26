//Abadali Sheih
// HW4 due 3/02/17

#include <iostream>
#include <iomanip>

using namespace std;

typedef int peg;
peg source = 0, aux =1, dest = 2;
int moves = 0;
void Toh(int, peg, peg, peg);
void move_disk(peg, peg);
void write_peg(peg);


int main()
{
    int n;
    
    cout << "Enter number of disks: ";
    cin >> n;
    cout << "Move the disks as follows." << endl;
    
    Toh(n, source, aux, dest);
    cout << endl;

    return 0;
} 

void Toh(int n, peg source, peg aux, peg dest)
{
    if (n > 0)
    {
        Toh(n-1, source, dest, aux);
        move_disk(source, dest);
        Toh(n-1, aux, source, dest);
    }
}

void move_disk(peg from, peg to)
{
    cout << ++moves << ". ";
    cout << setw(3) << "Move disk from the ";
    
    write_peg(from);
    
    cout << " to the ";
    
    write_peg(to);
    
    cout << " peg." << endl;
}

void write_peg(peg p)
{
    switch (p)
    {
        case 0: cout << setw(6) << "Left";
            break;
        case 1: cout << setw(3) << "Center";
            break;
        case 2: cout << setw(6) << "Right";
            break;
    }
    
}

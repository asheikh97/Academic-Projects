// Abadali Sheikh
// HW5 due on 3/6/17.

#include <iostream>
#include <iomanip>

using namespace std;

int SIZE = 20;

void combinations(int[],int,int);
void print_array(int[], int);

int main()
{
    int sequence[SIZE];
    int r_combinations, n_terms;
    
    for(int j = 0; j < SIZE; j++)
        sequence[j] = j+1;

    cout << "Enter value for number of terms in the sequence: ";
    cin >> n_terms;
    cout << endl << "Enter number of combinations for the sequence: ";
    cin >> r_combinations;
    
    combinations(sequence, n_terms, r_combinations);
    
    return 0;
}

void print_array(int a[], int r)
{
    for(int i = 0; i < r; i++)
    {
        cout << setw(3) << a[i];
        
        if(i == r - 1)
            cout << endl;
    }
}

void combinations(int seq[], int n, int r)
{
    int i;
    print_array(seq, r);
    
    do
    {
        i = r;
        
        while (seq[i-1] == ((n - r) + i))
            i = i - 1;
        
        seq[i-1] = seq[i-1] + 1;
    
        for (int j = i + 1; j <= r; j++)
            seq[j - 1] = seq[i - 1] + j - i;
        print_array(seq, r);
        
    } while (seq[0] != n - r + i);
}


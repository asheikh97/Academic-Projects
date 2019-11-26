// Abadali Sheikh
// HW5 due on 3/6/17.

#include <iostream>
#include <iomanip>

using namespace std;
void lex_combination(int[],int[],int,int,int,int);
void print_array(int[],int n,int r);


int SIZE = 20;

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
    
    print_array(sequence, n_terms, r_combinations);
    
    return 0;
}

void print_array(int seq[], int n, int r)
{
    int data[r];
    
    lex_combination(seq, data, 0, n-1, 0, r);
}
void lex_combination(int seq[], int data[], int start, int end,
                     int index, int r)
{
    if (index == r)
    {
        cout << "{ ";
        for (int j = 0; j < r; j++)
            cout << data[j] << setw(2) ;
        cout << " }" << endl;
    }

    for (int i = start; i <= end && end-i+1 >= r-index; i++)
    {
        data[index] = seq[i];
        lex_combination(seq, data, i+1, end, index+1, r);
    }
}

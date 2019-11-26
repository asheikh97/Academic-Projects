#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> my_vector;
    int user_input;
    
    cout << "Please enter your data: " << endl;

    while(cin >> user_input)
        my_vector.push_back(user_input);
    
    for(vector<int>:: iterator itr = my_vector.begin(); itr != my_vector.end(); ++itr)
        cout << *itr << " ";
    
    cout << endl;
    cout << "Vecter size = " << my_vector.size() << endl;
}


bool odd(int n)
{
    return n % 2 == 0;
}

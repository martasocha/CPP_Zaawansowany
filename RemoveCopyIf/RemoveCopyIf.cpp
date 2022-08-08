// CPP code to demonstrate remove_copy_if()
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool IsOdd(int i) { return ((i % 2) != 0); }

// Function to remove_copy from v1 result vector is v2
void remove_copy_ifDemo(vector <int>& v1, vector<int>& v2)
{
    remove_copy_if(v1.begin(), v1.end(), v2.begin(), IsOdd);
}

// Function to print content of vector
void print(vector<int>& v)
{
    int len = v.size();
    for (int i = 0; i < len; i++)
        cout << v[i] << " ";
    cout << endl;
}

// Driver code
int main()
{
    // declare vector v1, v2
    vector <int> v1, v2(10);

    // push data in vector 
    for (int i = 10; i <= 20; i++)
        v1.push_back(i);

    cout << "elements of v1 before remove_copy: ";
    print(v1);

    remove_copy_ifDemo(v1, v2);

    cout << "elements of v1 after remove_copy: ";
    print(v1);

    cout << "After removing Odd Numbers from v1"
        " copy result in vector v2" << endl;
    print(v2);

    return 0;

}
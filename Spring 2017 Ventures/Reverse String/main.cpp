#include <iostream>
#include<string>

using namespace std;

int main()
{
    string first, second, whole;
    first = "Hello ";
    second = "World!";
    whole = first + second;
    cout << whole << endl;
    cout << first[3] << endl;
    for (int i=whole.length(); i>=0; i--)
    {
        cout << whole[i];
    }
    return 0;
}

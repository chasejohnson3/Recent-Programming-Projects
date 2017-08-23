#include <iostream>
#include <string>

using namespace std;

int main()
{
    string test = "Hello world!";
    int length = test.size();
    for (int i=0; i<14; i++)
    {
        cout << test[i] << endl;
    }
    cout << length << endl;
    return 0;
}

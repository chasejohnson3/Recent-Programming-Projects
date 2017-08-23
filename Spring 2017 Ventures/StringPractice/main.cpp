#include <iostream>
#include <string>

using namespace std;

int main()
{
    string words;
    cout << "Give me a few words, please." << endl;
    getline(cin, words);
    cout << words;
    return 0;
}

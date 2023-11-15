#include <bits/stdc++.h>
#include "RC4.h"
using namespace std;

int main()
{
    vector<int> initKey = {1, 2, 3, 6};
    vector<int> plainText = {1, 2, 2, 2};
    vector<int> encrypted = RC4Encrypt(plainText, initKey, 8);
    for (int i = 0; i < encrypted.size(); i++)
    {
        cout << encrypted[i] << ' ';
    }
    cout << endl;
    pause();
    return 0;
}

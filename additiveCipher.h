#ifndef ADDENCRYPTION_H_INCLUDED
#define ADDENCRYPTION_H_INCLUDED

#include <bits/stdc++.h>
#include "Helper.h"
using namespace std;
const int MOD = 26;
#define pb push_back

string addEncrypt(string x, int key){
    string res = "";
    x = toLower(x);
    for(int i = 0;i < x.size();i++){
        int cur = x[i] - 'a';
        cur += key;
        cur = ((cur %MOD) + MOD )%MOD;
        char curChar = cur + 'A';

        res += curChar;
    }
    return res;
}
string addDecrypt(string x, int key){
    string res = "";
    x = toUpper(x);
    for(int i = 0;i < x.size();i++){
        int cur = x[i] - 'A';
        cur -= key;
        cur = ((cur %MOD) + MOD )%MOD;
        char curChar = cur + 'a';

        res += curChar;
    }
    return res;
}

#endif // ADDENCRYPTION_H_INCLUDED

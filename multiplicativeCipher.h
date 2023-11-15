#ifndef MULTIPLICATIVECIPHER_H_INCLUDED
#define MULTIPLICATIVECIPHER_H_INCLUDED
#include <bits/stdc++.h>
#include "Helper.h"
using namespace std;
const int MOD = 26;
#define pb push_back

string mulEncrypt(string x, int key){
    if(inverse(key, 26) == -1){
        return "you can't encrypt this";
    }
    x = toLower(x);
    string res = "";
    for(int i = 0;i < x.size();i++){
        int cur = x[i] - 'a';
        cur *= key;
        cur = ((cur %MOD) + MOD )%MOD;
        char curChar = cur + 'A';

        res += curChar;
    }
    return res;
}
string mulDecrypt(string x, int key){
    key = inverse(26, key);
    string res = "";
    x = toUpper(x);
    for(int i = 0;i < x.size();i++){
        int cur = x[i] - 'A';
        cur *= key;
        cur = ((cur %MOD) + MOD )%MOD;
        char curChar = cur + 'a';

        res += curChar;
    }
    return res;
}


#endif // MULTIPLICATIVECIPHER_H_INCLUDED

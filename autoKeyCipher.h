#ifndef AUTOKEYCIPHER_H_INCLUDED
#define AUTOKEYCIPHER_H_INCLUDED

#include <bits/stdc++.h>
#include "Helper.h"
using namespace std;
const int MOD = 26;
#define pb push_back
string autoKeyEncrypt(string text, string key){
    key += text;
    string res = "";
    text = toLower(text);
    for(int i = 0;i < text.size();i++){
        int curKey = key[i] - 'a';
        string curText = "";
        curText += text[i];
        string curCipherText = addEncrypt(curText, curKey);
        res += curCipherText;
    }
    return res;
}

string autoKeyDecrypt(string text, string key){
    string res = "";
    int keySize = key.size();
    text = toUpper(text);
    for(int i = 0;i < keySize;i++){
        string curChar = "";
        curChar += text[i];
        int curKey = key[i] - 'a';
        string curDecrypt = addDecrypt(curChar, curKey);
        key += curDecrypt;
        res += curDecrypt;
    }

    for(int i = keySize;i < text.size();i++){
        string curChar = "";
        curChar += text[i];
        int curKey = key[i] - 'a';
        string curDecrypt = addDecrypt(curChar, curKey);
        res += curDecrypt;
    }
    return res;
}

#endif // AUTOKEYCIPHER_H_INCLUDED

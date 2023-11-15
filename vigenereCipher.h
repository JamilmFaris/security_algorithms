#ifndef VIGENERECIPHER_H_INCLUDED
#define VIGENERECIPHER_H_INCLUDED
#include <bits/stdc++.h>
#include "Helper.h"
#include "additiveCipher.h"
using namespace std;
#define pb push_back

string getVigenereKey(string key, int sz){
    int keySize = key.size();
    int keyIdx = 0;
    string vigenereKey = "";
    for(int i = 0;i < sz;i++){
        vigenereKey += key[keyIdx];
        keyIdx = (keyIdx + 1)%keySize;
    }
    return vigenereKey;
}

string vigenereEncrypt(string text, string key){
    text = toLower(text);
    key = getVigenereKey(key, text.size());
    string res = "";
    for(int i = 0;i < text.size();i++){
        int curKey = key[i] - 'a';
        string curText = "";
        curText += text[i];
        string curCipherText = addEncrypt(curText, curKey);
        res += curCipherText;
    }
    return res;
}

string vigenereDecrypt(string cipherText, string key){
    string res = "";
    cipherText = toLower(cipherText);
    key = getVigenereKey(key, cipherText.size());
    for(int i = 0;i < cipherText.size();i++){
        string curChar = "";
        curChar += cipherText[i];
        int curKey = key[i] - 'a';
        string curDecrypt = addDecrypt(curChar, curKey);
        res += curDecrypt;
    }
    return res;
}


#endif // VIGENERECIPHER_H_INCLUDED

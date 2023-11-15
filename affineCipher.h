#ifndef AFFINECIPHER_H_INCLUDED
#define AFFINECIPHER_H_INCLUDED
#include <bits/stdc++.h>
#include "Helper.h"
using namespace std;
const int MOD = 26;
#define pb push_back

string affineEncrypt(string text, int key1, int key2){
    if(inverse(key1, 26) == -1){
        return "key1 doesn\'t have an inverse";
    }
    string res = "";
    text = toLower(text);
    for(int i = 0;i < text.size();i++){
        char curText = text[i];
        string curTextString = "";
        curTextString += text[i];
        string cipherText = mulEncrypt(curTextString, key1);
        cipherText = addEncrypt(cipherText, key2);
        res += cipherText;
    }
    return res;
}

string affineDecrypt(string text, int key1, int key2){
    if(inverse(key1, 26) == -1){
        return "key1 doesn\'t have an inverse";
    }
    string res = "";
    text = toUpper(text);
    for(int i = 0;i < text.size();i++){
        char curText = text[i];
        string curTextString = "";
        curTextString += text[i];
        string cipherText = addDecrypt(curTextString, key2);
        cipherText = mulDecrypt(cipherText, key1);
        res += cipherText;
    }
    return res;
}


#endif // AFFINECIPHER_H_INCLUDED

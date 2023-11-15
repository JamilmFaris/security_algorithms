#ifndef RC4_H_INCLUDED
#define RC4_H_INCLUDED

#include <bits/stdc++.h>
#include "Helper.h"
using namespace std;
const int MOD = 26;
#define pb push_back


vector<int> RC4KeyStream(vector<int> plainText, vector<int> initKey, int keyStreamSize){
    vector<int > s, t, keyStream;
    for(int i = 0;i < keyStreamSize;i++){
        s.pb(i);
    }

    int initKeyIdx = 0;
    for(int i = 0;i < keyStreamSize;i++){
        t.pb(initKey[initKeyIdx]);
        initKeyIdx = (initKeyIdx + 1)% initKey.size();
    }
    int j = 0;
    for(int i = 0;i < keyStreamSize;i++){
        j = (j + s[i] + t[i]) % keyStreamSize;
        swap(s[i], s[j]);
    }
    /*
    cout << "s after the first for\n";
    for(auto nx : s){
        cout << nx << " ";
    }cout << endl;
    */

    //
    int i = 0;
    j = 0;
    for(int i1 = 0;i1 < plainText.size();i1++){
        i = (i+1) % keyStreamSize;
        j = (j + s[i]) % keyStreamSize;
        swap(s[i], s[j]);

        /*
        cout << "i j " << i << ' ' << j << endl;
        cout << "s i j " << s[i] << ' ' << s[j] << endl;
        cout << "keyStreamSize " << keyStreamSize << endl;
        cout << "s " <<  (s[i] + s[j])  % keyStreamSize << endl;
        */

        keyStream.pb(s[ (s[i] + s[j]) % keyStreamSize]);
    }

    /*
    cout << "key stream\n";
    for(auto nx: keyStream){
        cout << nx << " ";
    }cout << endl;
    */


    return keyStream;
}

vector<int > RC4Encrypt(vector<int> plainText, vector<int> initKey, int keyStreamSize){
    vector<int > cipherText;
    vector<int > keyStream = RC4KeyStream(plainText, initKey, keyStreamSize);
    int keyStreamIdx = 0;
    for(auto nx: plainText){
        cipherText.pb(nx ^ keyStream[keyStreamIdx]);
        keyStreamIdx++;
    }
    return cipherText;
}


string RC4Encrypt(string plainText, string initKey, int keyStreamSize){
    vector<int> plainTextVector, initKeyVector;
    plainText = toLower(plainText);
    initKey = toLower(initKey);
    for(int i = 0;i < plainText.size();i++){
        int cur = plainText[i] - 'a';
        plainTextVector.pb(cur);
    }

    for(int i = 0;i < initKey.size();i++){
        int cur = initKey[i] - 'a';
        initKeyVector.pb(cur);
    }
    vector<int> cipherText = RC4Encrypt(plainTextVector, initKeyVector, keyStreamSize);
    string cipherTextString = "";
    for(auto nx : cipherText){
        char cur = nx + 'A';
        cipherTextString += cur;
    }
    return cipherTextString;
}

#endif // RC4_H_INCLUDED

#ifndef PLAYFAIRCIPHER_H_INCLUDED
#define PLAYFAIRCIPHER_H_INCLUDED
#include <bits/stdc++.h>
#include "Helper.h"
using namespace std;

char playfairKey[8][8];
void fillPlayfairKey(string plainText){
    string plainTextSet = "";
    bool vis[26];
    for(int i = 0;i < 26;i++)vis[i] = 0;
    vis['j' - 'a'] = 1; // don't add j to the key


    for(int i = 0;i < plainText.length();i++){
        if(!vis[plainText[i] - 'a']){
            vis[plainText[i] - 'a'] = 1;
            plainTextSet += plainText[i];
        }
    }


    for(char a = 'a';a <= 'z';a++){
        if(!vis[a - 'a']){
            vis[a - 'a'] = 1;
            plainTextSet += a;
        }
    }
    int plainTextSetIdx = 0;
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            playfairKey[i][j] = plainTextSet[plainTextSetIdx++];
        }
    }

}
string fixPlayfairPlainText(string plainText){ // returns even long string (i.e 2n)
    for(int i = 0;i < plainText.length();i+=2){
        if(plainText[i] == plainText[i+1]){
            plainText.insert(i+1, "x");
        }
    }
    if(plainText.length() % 2 != 0){
        plainText += 'x';
    }
    return plainText;
}
string playfairEnc(string plainText){
    fillPlayfairKey(plainText);
    string fixedText = fixPlayfairPlainText(plainText);

    for(int i = 0;i < fixedText.length();i++){
        if(fixedText[i] == 'j'){
            fixedText[i] = 'i';
        }
    }

    cout << "fixed text is " << fixedText << endl;
    string res = "";
    for(int textIdx = 0;textIdx < fixedText.length();textIdx+=2){
        int r1 = -1, c1 = -1, r2 = -1, c2 = -1;

        // get the indexes of the first item of the group
        bool br = 0;
        for(int i = 0;i < 5;i++){
            for(int j = 0;j < 5;j++){
                if(fixedText[textIdx] == playfairKey[i][j]){
                    r1 = i;c1 = j;
                    br = 1;
                    break;
                }
            }
            if(br){
                break;
            }
        }

        // get the indexes of the second item of the group
        br = 0;
        for(int i = 0;i < 5;i++){
            for(int j = 0;j < 5;j++){
                if(fixedText[textIdx+1] == playfairKey[i][j]){
                    r2 = i;c2 = j;
                    br = 1;
                    break;
                }
            }
            if(br){
                break;
            }
        }

        char first, second;
        // encrypt the fixedText[i] char
        if(r1 == r2){
            int newC1 = (c1 + 1)% 5;
            int newC2 = (c2 + 1)% 5;
            first = playfairKey[r1][newC1];
            second = playfairKey[r1][newC2];
        }
        else if(c1 == c2){
            int newR1 = (r1 + 1)% 5;
            int newR2 = (r2 + 1)% 5;
            first = playfairKey[newR1][c1];
            second = playfairKey[newR2][c1];
        }
        else{
            first = playfairKey[r1][c2];
            second = playfairKey[r2][c1];
        }
        res += first;
        res += second;
    }
    res = toUpper(res);
    return res;
}

string playfairDec(string cipherText, char key[8][8]){
    cipherText = toLower(cipherText);
    string res = "";
    for(int textIdx = 0;textIdx < cipherText.length();textIdx+=2){
        int r1 = -1, c1 = -1, r2 = -1, c2 = -1;

        // get the indexes of the first item of the group
        bool br = 0;
        for(int i = 0;i < 5;i++){
            for(int j = 0;j < 5;j++){
                if(cipherText[textIdx] == key[i][j]){
                    r1 = i;c1 = j;
                    br = 1;
                    break;
                }
            }
            if(br){
                break;
            }
        }

        // get the indexes of the second item of the group
        br = 0;
        for(int i = 0;i < 5;i++){
            for(int j = 0;j < 5;j++){
                if(cipherText[textIdx+1] == key[i][j]){
                    r2 = i;c2 = j;
                    br = 1;
                    break;
                }
            }
            if(br){
                break;
            }
        }

        char first, second;
        // decrypt the fixedText[i] char
        if(r1 == r2){
            int newC1 = (c1 - 1 + 5)% 5;
            int newC2 = (c2 - 1 + 5)% 5;
            first = key[r1][newC1];
            second = key[r1][newC2];
        }
        else if(c1 == c2){
            int newR1 = (r1 - 1 + 5)% 5;
            int newR2 = (r2 - 1 + 5)% 5;
            first = key[newR1][c1];
            second = key[newR2][c1];
        }
        else{
            first = key[r1][c2];
            second = key[r2][c1];
        }
        res += first;
        res += second;
    }
    return res;
}

#endif // PLAYFAIRCIPHER_H_INCLUDED

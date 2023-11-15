#ifndef ADFGUX_H_INCLUDED
#define ADFGUX_H_INCLUDED
#include <bits/stdc++.h>
#include "Helper.h"
using namespace std;
const int MOD = 26;
#define pb push_back

void fillKeyADFGUX(string text){
    map<char, bool>vis;
    string textKey = "";
    for(int i = 0;i < text.size();i++){
        if(!vis[text[i]]){
            textKey += text[i];
            vis[text[i]] = 1;
        }
    }
    int num = 0;
    bool tr = 0;
    int i1 = 1, j1 = 1;
    for(int i = 1;i <= 6;i++){
        for(int j = 1;j <= 6;j++){
            if(num >= text.size()){
                tr = 1;
                break;
            }
            key[i][j] = textKey[num];
            i1 = i;
            j1 = j;
            num++;
        }
        if(tr){
            break;
        }
    }
    tr = 0;
    char a = 'a';
    int j = j1;
    bool tr2 = 1;
    for(int i = i1;i <= 6;i++){
        if(tr2){
            j = j1;
            tr2 = 0;
        }
        else{
            j = 1;
        }
        for(;j <= 6;j++){
            while(vis[a]){
                a++;
            }
            if(a > 'z'){
                tr = 1;
                break;
            }
            key[i][j] = a;
            vis[a] = 1;
            a++;
            i1 = i;
            j1 = j;
        }
        if(tr){
            break;
        }
    }

    //adding numbers
    tr = 0;
    char a1 = '0';
    j = 3;
    tr2 = 1;
    for(int i = 5;i <= 6;i++){
        if(tr2){
            j = j1;
            tr2 = 0;
        }
        else{
            j = 1;
        }
        for(;j <= 6;j++){
            if(a1 > '9'){
                tr = 1;
                break;
            }
            key[i][j] = a1;
            a1++;
        }
        if(tr){
            break;
        }
    }
}



#endif // ADFGUX_H_INCLUDED

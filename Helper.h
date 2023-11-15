#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED

#include <bits/stdc++.h>
using namespace std;
int _gcd(int x, int y){
    if(x == 0){
        return y;
    }
    return _gcd(y%x, x);
}

string toLower(string x){
    for(int i = 0;i < x.size();i++){
        if(x[i] >= 'A' && x[i] <= 'Z'){
                x[i] -= 'A';
                x[i] += 'a';
        }
    }
    return x;
}
string toUpper(string x){
    for(int i = 0;i < x.size();i++){
        if(x[i] >= 'a' && x[i] <= 'z'){
            x[i] -= 'a';
            x[i] += 'A';
        }
    }

    return x;
}

int inverse(int mod, int x){
    int r1 = mod, r2 = x;
    int t1 = 0, t2 = 1;
    while(r2 > 0){
        int q = r1/r2;
        int r = r1 - q*r2;
        r1 = r2;
        r2 = r;
        int t = t1 - q*t2;
        t1 = t2;
        t2 = t;
    }
    if(r1 == 1){
        t1 = (t1 + 26)%26;
        return t1;
    }
    return -1;
}

/*void swap(char* x, char* y){
    char temp = *x;
    *x = y;
    *y = temp;
}*/

#endif // HELPER_H_INCLUDED

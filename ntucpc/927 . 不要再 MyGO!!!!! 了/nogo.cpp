#include "lib0927.h"
#include <bits/stdc++.h>
//#include "grader.cpp"
using namespace std;

#define all(x) x.begin(), x.end()

void init() {
}

string Anon(int x, int k) {
    string ans;
    if (x == 0) return "O";
    while(x){
        if (x % 3 == 2)
            ans+="GGG";
        else if (x % 3 == 1)
            ans+="GGO";
        else 
            ans+="GOO";
        x /= 3;

    }
    return ans;
}

int Baluteshih(string s, int k) {
    if (s == "O") return 0;
    reverse(all(s));
    int ans=0;
    for(int i=0;i<s.size();i+=3){
        ans *=3;
        int gc = -1;
        for (int j = 0 ; j < 3 ; j++) {
            if (s[i+j] == 'G') gc++;
        }
        ans += gc;
    }
    return ans;
}
/*
13 3
12321321
1532132
85132123
1561231
18651312
156132123
851512
515151
51212
1024
256
1023
1





*/
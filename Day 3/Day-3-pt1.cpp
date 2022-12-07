#include <bits/stdc++.h>
#include <fstream>
#include <string>
#define len(s) (int)s.size()
using namespace std;
const int N = 1e3 + 7;
ifstream fi("input.txt");
ofstream fo("output.txt");
char bag[2][N];

void clear(){
    for (int i = 0; i < N; i++){
        bag[0][i] = 0;
        bag[1][i] = 0;
    }
}

int convert(char c){
    if (isupper(c)){
        return 27 + int(c - 'A');
    }else{
        return 1 + int(c - 'a');
    }
}

int search(int n){
    int i = 0;
    for (int j = 0; j < n; j++){
        while (bag[0][i] < bag[1][j]) i++;
        if (bag[0][i] == bag[1][j]){
            return convert(bag[0][i]);
        }
    }
    return 0;
}

int main(){
    string inp;
    int ans = 0;
    while (fi >> inp){
        clear();
        for (int i = 0; i < len(inp) / 2; i++){
            bag[0][i] = inp[i];
        }
        for (int i = len(inp) / 2; i < len(inp); i++){
            bag[1][i - len(inp) / 2] = inp[i];
        }
        sort(bag[0], bag[0] + len(inp) / 2);
        sort(bag[1], bag[1] + len(inp) / 2);
        ans += search(len(inp) / 2);
    }
    fo << ans;
}
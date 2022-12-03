#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
const int N = 1e6 + 7;
ifstream fi("input.txt");
ofstream fo("output.txt");
int n = 0;
int opponent[N];
int self[N];
int comp[4][4] = {{0, 0, 0, 0}, {0, 3, 1, 2}, {0, 1, 2, 3}, {0, 2, 3, 1}};

void set_opponent(char c, int p){
    switch (c){
        case 'A':
            opponent[p] = 1;
            break;
        case 'B':
            opponent[p] = 2;
            break;
        case 'C':
            opponent[p] = 3;
            break;
    }
}

void set_self(char c, int p){
    switch (c){
        case 'X':
            self[p] = 1;
            break;
        case 'Y':
            self[p] = 2;
            break;
        case 'Z':
            self[p] = 3;
            break;
    }
}

int calculate_score(){
    int score = 0;
    for (int i = 0; i < n; i++){
        score += (self[i] - 1) * 3 + comp[self[i]][opponent[i]];
    }
    return score;
}

int main(){
    char c1, c2;
    while (fi >> c1 >> c2){
        set_opponent(c1, n);
        set_self(c2, n);
        n++;
    }
    fo << calculate_score() << "\n";
}
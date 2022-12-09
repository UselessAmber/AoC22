#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>
#define len(s) (int)s.size()
using namespace std;
const int N = 4e4 + 7;
const int M = 20;
ifstream fi("input.txt");
ofstream fo("output.txt");
int rx[M], ry[M];
bool mp[N][N];
int ans = 0;

void update_head(char dir){
    switch (dir){
        case 'L':
            rx[0] -= 1;
            break;
        case 'R':
            rx[0] += 1;
            break;
        case 'U':
            ry[0] += 1;
            break;
        case 'D':
            ry[0] -= 1;
            break;
    }
}

void update_tail(int p){
    int dx = rx[p - 1] - rx[p];
    int dy = ry[p - 1] - ry[p];
    if (max(abs(dx), abs(dy)) >= 2){
        rx[p] += ((abs(dx) > 0)? dx / abs(dx) : 0);
        ry[p] += ((abs(dy) > 0)? dy / abs(dy) : 0);
    }
    if (p == 9){
        if (mp[rx[p] + 10000][ry[p] + 10000] == 0) ans += 1;
        mp[rx[p] + 10000][ry[p] + 10000] = 1;
    }
}

int main(){
    char dir;
    int step;
    while (fi >> dir >> step){
        for (int i = 0; i < step; i++){
            update_head(dir);
            for (int i = 1; i < 10; i++)
                update_tail(i);
        }
    }
    fo << ans;
}
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>
#define len(s) (int)s.size()
using namespace std;
const int N = 2e4 + 7;
ifstream fi("input.txt");
ofstream fo("output.txt");
int hx, hy, tx, ty;
bool mp[N][N];
int ans = 0;

void update_head(char dir){
    switch (dir){
        case 'L':
            hx -= 1;
            break;
        case 'R':
            hx += 1;
            break;
        case 'U':
            hy += 1;
            break;
        case 'D':
            hy -= 1;
            break;
    }
}

void update_tail(){
    int dx = hx - tx;
    int dy = hy - ty;
    if (max(abs(dx), abs(dy)) >= 2){
        tx += ((abs(dx) > 0)? dx / abs(dx) : 0);
        ty += ((abs(dy) > 0)? dy / abs(dy) : 0);
    }
    if (mp[tx + 10000][ty + 10000] == 0) ans += 1;
    mp[tx + 10000][ty + 10000] = 1;
}

int main(){
    char dir;
    int step;
    while (fi >> dir >> step){
        for (int i = 0; i < step; i++){
            update_head(dir);
            update_tail();
        }
    }
    fo << ans;
}
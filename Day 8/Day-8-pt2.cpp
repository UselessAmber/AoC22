#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>
#define len(s) (int)s.size()
using namespace std;
const int N = 1e3 + 7;
ifstream fi("input.txt");
ofstream fo("output.txt");
int visible[N][N];
int height[N][N];

int visible_score(int r, int c, int R, int C){
    int dir[4] = {0, 0, 0, 0};
    for (int i = r - 1; i >= 0; i--){
        dir[0]++;
        if (height[i][c] >= height[r][c])
            break;
    }
    for (int i = r + 1; i < R; i++){
        dir[1]++;
        if (height[i][c] >= height[r][c])
            break;
    }
    for (int i = c - 1; i >= 0; i--){
        dir[2]++;
        if (height[r][i] >= height[r][c])
            break;
    }
    for (int i = c + 1; i < C; i++){
        dir[3]++;
        if (height[r][i] >= height[r][c])
            break;
    }
    return visible[r][c] = dir[0] * dir[1] * dir[2] * dir[3];
}

int main(){
    int c = 0, r = 0;
    string inp;
    while (fi >> inp){
        c = len(inp);
        for (int i = 0; i < c; i++){
            height[r][i] = inp[i] - '0';
        }
        r++;
    }
    int ans = 0;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            ans = max(ans, visible_score(i, j, r, c));
        }
    }
    fo << ans;
}
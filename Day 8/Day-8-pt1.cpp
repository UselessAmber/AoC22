#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>
#define len(s) (int)s.size()
using namespace std;
const int N = 1e3 + 7;
ifstream fi("input.txt");
ofstream fo("output.txt");
bool visible[N][N];
int height[N][N];

bool is_visible(int r, int c, int R, int C){
    int test = 0;
    for (int i = 0; i < r; i++)
        if (height[i][c] >= height[r][c])
            test |= 1;
    for (int i = r + 1; i < R; i++)
        if (height[i][c] >= height[r][c])
            test |= 2;
    for (int i = 0; i < c; i++)
        if (height[r][i] >= height[r][c])
            test |= 4;
    for (int i = c + 1; i < C; i++)
        if (height[r][i] >= height[r][c])
            test |= 8;
    return visible[r][c] = !(test == 15);
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
            ans += is_visible(i, j, r, c);
        }
    }
    fo << ans;
}
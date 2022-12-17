#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>
#define len(s) (int)s.size()
using namespace std;
const int N = 1e3 + 7;
const int INF = 1e9 + 7;
typedef vector<int> vi;
typedef pair<int, int> pii;
ifstream fi("input.txt");
ofstream fo("output.txt");
const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};
int R = 0, C = 0;
int heightmap[N][N];
int vs[N][N];

bool bound(int r, int c){
    return (0 <= r) && (r < R) && (0 <= c) && (c < C);
}

void bfs(int r, int c){
    queue <pii> quwue;
    quwue.push(pii(r, c));
    vs[r][c] = 1;
    while (!quwue.empty()){
        int cr = quwue.front().first;
        int cc = quwue.front().second;
        quwue.pop();
        for (int i = 0; i < 4; i++){
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (bound(nr, nc) && (heightmap[cr][cc] - heightmap[nr][nc] <= 1) && vs[nr][nc] == 0){
                vs[nr][nc] = vs[cr][cc] + 1;
                quwue.push(pii(nr, nc));
            }
        }
    }
}

int main(){
    string row;
    int sr, sc, er, ec;
    while (fi >> row){
        C = len(row);
        for (int i = 0; i < len(row); i++){
            switch (row[i]){
                case 'S':
                    heightmap[R][i] = 0;
                    sr = R;
                    sc = i;
                    break;
                case 'E':
                    heightmap[R][i] = 25;
                    er = R;
                    ec = i;
                    break;
                default:
                    heightmap[R][i] = row[i] - 'a';
                    break;
            }
        }
        R++;
    }
    bfs(er, ec);
    int output = INF;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < R; j++){
            if (heightmap[i][j] == 0 && vs[i][j] != 0){
                output = min(output, vs[i][j] - 1);
            }
        }
    }
    fo << output;
}
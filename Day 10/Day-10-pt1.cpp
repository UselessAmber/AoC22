#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>
#define len(s) (int)s.size()
using namespace std;
const int N = 2e4 + 7;
ifstream fi("input.txt");
ofstream fo("output.txt");
int record = 0;
int rec[] = {20, 60, 100, 140, 180, 220, 999999};
int X = 1;
int ans = 0;

int main(){
    //noop
    string cmd;
    int value;
    int cycle_count = 1;
    while (fi >> cmd){
        if (cmd != "noop"){
            fi >> value;
            if (cycle_count + 2 > rec[record]){
                ans += X * rec[record];
                record++;
            }
            X += value;
            cycle_count += 2;
        }else{
            if (cycle_count + 1 > rec[record]){
                ans += X * rec[record];
                record++;
            }
            cycle_count++;
        }
        if (cycle_count == rec[record]){
            ans += X * rec[record];
            record++;
        }
    }
    fo << ans;
}
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>
#define len(s) (int)s.size()
using namespace std;
const int N = 2e4 + 7;
ifstream fi("input.txt");
ofstream fo("output.txt");
int X = 1;
int ans = 0;
int crt_ptr = 1;
int cycle_count = 1;

void execute_draw(){
    cycle_count++;
    if (abs((crt_ptr - 1) % 40 + 1 - X) <= 1){
        fo << "#";
    }else{
        fo << ".";
    }
    if (crt_ptr % 40 == 0) fo << "\n";
    crt_ptr++;
}

int main(){
    //noop
    string cmd;
    int value;
    while (fi >> cmd){
        if (cmd != "noop"){
            fi >> value;
            execute_draw();
            X += value;
        }
        execute_draw();
    }
}
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>
#define len(s) (int)s.size()
using namespace std;
const int N = 9;
ifstream fi("input.txt");
ofstream fo("output.txt");
int n;
deque <char> a[N];

int convert_to_int(string s){
    int ret = 0;
    for (char c : s){
        ret += (c - '0');
        ret *= 10;
    }
    return ret / 10;
}

string get_substring(string inp, int start, int length){
    string ans = "";
    for (int i = start; i < start + length; i++){
        ans = ans + inp[i];
    }
    return ans;
}

void parse_command(string inp){
    stringstream ss(inp);
    string cmd;
    int ptr = 0;
    int args[3] = {};
    while (getline(ss, cmd, ' ')){
        if (cmd == "move")
            ptr = 0;
        else if (cmd == "from")
            ptr = 1;
        else if (cmd == "to")
            ptr = 2;
        else
            args[ptr] = convert_to_int(cmd);
    }
    for (int i = 0; i < args[0]; i++){
        a[args[2] - 1].push_front(a[args[1] - 1].front());
        a[args[1] - 1].pop_front();
    }
}

string get_result(){
    string ans = "";
    for (int i = 0; i < n; i++){
        ans = ans + a[i].front();
    }
    return ans;
}

int main(){
    bool crate_sys = true;
    string inp;
    while(getline(fi, inp) && crate_sys){
        inp = inp + " ";
        n = len(inp) / 4;
        for (int i = 0; i < n; i++){
            string crate = get_substring(inp, i * 4, 3);
            if (isdigit(crate[1])){
                crate_sys = false;
                break;
            }
            if (crate[1] != ' '){
                a[i].push_back(crate[1]);
            }
        }
    }
    while(getline(fi, inp)){
        parse_command(inp);
    }
    fo << get_result();
}
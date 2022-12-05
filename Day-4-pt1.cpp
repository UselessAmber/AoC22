#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
const int N = 2e3 + 7;
ifstream fi("input.txt");
ofstream fo("output.txt");
pair <int, int> elf[N];
int n;

bool containment(pair <int, int> elf1, pair <int, int> elf2){
    return (elf1.first <= elf2.first && elf2.second <= elf1.second) || (elf2.first <= elf1.first && elf1.second <= elf2.second);
}

int convert_to_int(string s){
    int ret = 0;
    for (char c : s){
        ret += (c - '0');
        ret *= 10;
    }
    return ret / 10;
}

void readpair(string s, int &l, int &r){
    stringstream ss;
    string seg;
    ss << s;
    bool is_left = 1;
    while (getline(ss, seg, '-')){
        if (is_left){
            l = convert_to_int(seg);
        }else{
            r = convert_to_int(seg);
        }
        is_left = !is_left;
    }
}

void read(string s, int p){
    string cur = "";
    for (char c : s){
        switch(c){
            case ',':
            readpair(cur, elf[p].first, elf[p].second);
            cur = "";
            p++;
            break;

            default:
            cur = cur + c;
            break;
        }
    }
    readpair(cur, elf[p].first, elf[p].second);
}

int main(){
    string s;
    while(fi >> s){
        read(s, n);
        n += 2;
    }
    int ans = 0;
    for (int i = 0; i < n; i += 2){
        ans += containment(elf[i], elf[i + 1]);
    }
    fo << ans;
}
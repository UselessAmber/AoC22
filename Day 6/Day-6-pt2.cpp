#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>
#define len(s) (int)s.size()
using namespace std;
const int N = 1e3 + 7;
ifstream fi("input.txt");
ofstream fo("output.txt");
string s;
int s_lim = 14;

void set_bit(int &n, int p){
    n |= (1 << p);
}

int bit_count(int n){
    int counter = 0;
    while (n != 0){
        counter += ((n & 1)? 1 : 0);
        n >>= 1;
    }
    return counter;
}

int main(){
    fi >> s;
    for (int i = 0; i < len(s) - s_lim; i++){
        int marker = 0;
        for (int j = 0; j < s_lim; j++){
            set_bit(marker, s[i + j] - 'a');
        }
        if (bit_count(marker) == s_lim){
            fo << i + s_lim << "\n";
            break;
        }
    }
}
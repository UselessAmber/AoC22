#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>
#define len(s) (int)s.size()
using namespace std;
const int N = 1e5 + 7;
ifstream fi("input.txt");
ofstream fo("output.txt");
int dir_ptr = 0;
int top = 1;
bool ls_check[N];

struct directory{
    string dirname = "";
    long long dirsize = 0;
    vector <int> child_list;
    int parent = -1;
    bool is_file = false;
} tree[N];

void initialize(){
    tree[0].dirname = "/";
    tree[0].child_list.clear();
    tree[0].dirsize = 0;
    tree[0].parent = -1;
    top = 1;
    dir_ptr = 0;
}

int get_dir(int cur, string name){
    for (int subdir : tree[cur].child_list){
        if (tree[subdir].dirname == name){
            return subdir;
        }
    }
    return -1;
}

long long to_decimal(string inp){
    long long out = 0;
    for (char c : inp){
        out += c - '0';
        out *= 10;
    }
    return out / 10;
}

void parse_command(int &dir_ptr){
    string command;
    string arg1, arg2;
    fi >> arg1 >> arg2;
    while (arg1 == "$"){
        if (arg2 == "cd"){
            fi >> arg1;
            if (arg1 == "/")
                dir_ptr = 0;
            else if (arg1 == "..")
                dir_ptr = tree[dir_ptr].parent;
            else
                dir_ptr = get_dir(dir_ptr, arg1);
            fi >> arg1 >> arg2;
        }else if (arg2 == "ls"){
            while (fi >> arg1 >> arg2){
                if (arg1 == "$") break;
                if (!ls_check[dir_ptr]){
                    tree[top].dirname = arg2;
                    tree[top].parent = dir_ptr;
                    tree[dir_ptr].child_list.push_back(top);
                    if (arg1 != "dir"){
                        tree[top].dirsize = to_decimal(arg1);
                        tree[top].is_file = true;
                    }
                    top++;
                }
            }
            ls_check[dir_ptr] = true;
        }
    }
}

long long traverse(int cur, long long &out){
    long long output = 0;
    if (tree[cur].is_file){
        output = tree[cur].dirsize;
    }else{
        for (int subdir : tree[cur].child_list){
            output += traverse(subdir, out);
        }
        if (output <= 100000) out += output;
    }
    return output;
}

int main(){
    initialize();
    parse_command(dir_ptr);
    long long output = 0;
    traverse(0, output);
    fo << output;
}
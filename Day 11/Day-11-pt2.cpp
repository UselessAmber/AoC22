#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>
#define len(s) (int)s.size()
using namespace std;
const int N = 8;
const int INF = 1e9 + 7;
typedef vector<int> vi;
ifstream fi("input.txt");
ofstream fo("output.txt");
queue <vi> monkey[N];
int monkey_inspect_count[N];
int monkey_modulo[N];
//Behold: Modulo Arithmetic:
long long int m_add(int a, int b, int m){
    return ((a % m) + (b % m)) % m;
}

long long int m_mul(int a, int b, int m){
    return ((a % m) * (b % m)) % m;
}

void initialize(){
    for (int i = 0; i < N; i++){
        fi >> monkey_modulo[i];
    }
    for (int i = 0; i < N; i++){
        int item_count;
        fi >> item_count;
        for (int j = 0; j < item_count; j++){
            int value;
            fi >> value;
            vi init;
            for (int k = 0; k < N; k++){
                init.push_back(value % monkey_modulo[k]);
            }
            monkey[i].push(init);
        }
    }
}

void begin_round(){
    while (!monkey[0].empty()){
        monkey_inspect_count[0]++;
        vi current = monkey[0].front();
        for (int i = 0; i < N; i++){
            current[i] = m_mul(current[i], 5, monkey_modulo[i]);
        }
        monkey[0].pop();
        if (current[0] == 0)
            monkey[2].push(current);
        else
            monkey[3].push(current);
    }
    while (!monkey[1].empty()){
        monkey_inspect_count[1]++;
        vi current = monkey[1].front();
        for (int i = 0; i < N; i++){
            current[i] = m_mul(current[i], 11, monkey_modulo[i]);
        }
        monkey[1].pop();
        if (current[1] == 0)
            monkey[4].push(current);
        else
            monkey[0].push(current);
        
    }
    while (!monkey[2].empty()){
        monkey_inspect_count[2]++;
        vi current = monkey[2].front();
        for (int i = 0; i < N; i++){
            current[i] = m_add(current[i], 2, monkey_modulo[i]);
        }
        monkey[2].pop();
        if (current[2] == 0)
            monkey[5].push(current);
        else
            monkey[6].push(current);
        
    }
    while (!monkey[3].empty()){
        monkey_inspect_count[3]++;
        vi current = monkey[3].front();
        for (int i = 0; i < N; i++){
            current[i] = m_add(current[i], 5, monkey_modulo[i]);
        }
        monkey[3].pop();
        if (current[3] == 0)
            monkey[2].push(current);
        else
            monkey[6].push(current);
    }
    while (!monkey[4].empty()){
        monkey_inspect_count[4]++;
        vi current = monkey[4].front();
        for (int i = 0; i < N; i++){
            current[i] = m_mul(current[i], current[i], monkey_modulo[i]);
        }
        monkey[4].pop();
        if (current[4] == 0)
            monkey[0].push(current);
        else
            monkey[3].push(current);
        
    }
    while (!monkey[5].empty()){
        monkey_inspect_count[5]++;
        vi current = monkey[5].front();
        for (int i = 0; i < N; i++){
            current[i] = m_add(current[i], 4, monkey_modulo[i]);
        }
        monkey[5].pop();
        if (current[5] == 0)
            monkey[7].push(current);
        else
            monkey[1].push(current);
        
    }
    while (!monkey[6].empty()){
        monkey_inspect_count[6]++;
        vi current = monkey[6].front();
        for (int i = 0; i < N; i++){
            current[i] = m_add(current[i], 6, monkey_modulo[i]);
        }
        monkey[6].pop();
        if (current[6] == 0)
            monkey[7].push(current);
        else
            monkey[5].push(current);
        
    }
    while (!monkey[7].empty()){
        monkey_inspect_count[7]++;
        vi current = monkey[7].front();
        for (int i = 0; i < N; i++){
            current[i] = m_add(current[i], 7, monkey_modulo[i]);
        }
        monkey[7].pop();
        if (current[7] == 0)
            monkey[4].push(current);
        else
            monkey[1].push(current);
        
    }
}

long long finalize(){
    int first_max = -INF, second_max = -INF;
    for (int i = 0; i < N; i++){
        if (monkey_inspect_count[i] > first_max){
            second_max = first_max;
            first_max = monkey_inspect_count[i];
        }else if (monkey_inspect_count[i] > second_max){
            second_max = monkey_inspect_count[i];
        }
    }
    return (long long)first_max * (long long)second_max;
}

int main(){
    initialize();
    for (int i = 0; i < 10000; i++){
        begin_round();
    }
    fo << finalize();
}
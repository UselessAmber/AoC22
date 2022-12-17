#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>
#define len(s) (int)s.size()
using namespace std;
const int N = 8;
const int INF = 1e9 + 7;
ifstream fi("input.txt");
ofstream fo("output.txt");
//tThis one will not support custom input, because of the complexity of the f*cking input itself and how variable it can be.
queue <int> monkey[N];
int monkey_inspect_count[N];

void initialize(){
    monkey[0].push(83);
    monkey[0].push(88);
    monkey[0].push(96);
    monkey[0].push(79);
    monkey[0].push(86);
    monkey[0].push(88);
    monkey[0].push(70);
    //
    monkey[1].push(59);
    monkey[1].push(63);
    monkey[1].push(98);
    monkey[1].push(85);
    monkey[1].push(68);
    monkey[1].push(72);
    //
    monkey[2].push(90);
    monkey[2].push(79);
    monkey[2].push(97);
    monkey[2].push(52);
    monkey[2].push(90);
    monkey[2].push(94);
    monkey[2].push(71);
    monkey[2].push(70);
    //
    monkey[3].push(97);
    monkey[3].push(55);
    monkey[3].push(62);
    //
    monkey[4].push(74);
    monkey[4].push(54);
    monkey[4].push(94);
    monkey[4].push(76);
    //
    monkey[5].push(58);
    //
    monkey[6].push(66);
    monkey[6].push(63);
    //
    monkey[7].push(56);
    monkey[7].push(56);
    monkey[7].push(90);
    monkey[7].push(96);
    monkey[7].push(68);
}

void begin_round(){
    while (!monkey[0].empty()){
        monkey_inspect_count[0]++;
        int current = (monkey[0].front() * 5) / 3;
        monkey[0].pop();
        if (current % 11 == 0)
            monkey[2].push(current);
        else
            monkey[3].push(current);
    }
    while (!monkey[1].empty()){
        monkey_inspect_count[1]++;
        int current = (monkey[1].front() * 11) / 3;
        monkey[1].pop();
        if (current % 5 == 0)
            monkey[4].push(current);
        else
            monkey[0].push(current);
        
    }
    while (!monkey[2].empty()){
        monkey_inspect_count[2]++;
        int current = (monkey[2].front() + 2) / 3;
        monkey[2].pop();
        if (current % 19 == 0)
            monkey[5].push(current);
        else
            monkey[6].push(current);
        
    }
    while (!monkey[3].empty()){
        monkey_inspect_count[3]++;
        int current = (monkey[3].front() + 5) / 3;
        monkey[3].pop();
        if (current % 13 == 0)
            monkey[2].push(current);
        else
            monkey[6].push(current);
    }
    while (!monkey[4].empty()){
        monkey_inspect_count[4]++;
        int current = (monkey[4].front() * monkey[4].front()) / 3;
        monkey[4].pop();
        if (current % 7 == 0)
            monkey[0].push(current);
        else
            monkey[3].push(current);
        
    }
    while (!monkey[5].empty()){
        monkey_inspect_count[5]++;
        int current = (monkey[5].front() + 4) / 3;
        monkey[5].pop();
        if (current % 17 == 0)
            monkey[7].push(current);
        else
            monkey[1].push(current);
        
    }
    while (!monkey[6].empty()){
        monkey_inspect_count[6]++;
        int current = (monkey[6].front() + 6) / 3;
        monkey[6].pop();
        if (current % 2 == 0)
            monkey[7].push(current);
        else
            monkey[5].push(current);
        
    }
    while (!monkey[7].empty()){
        monkey_inspect_count[7]++;
        int current = (monkey[7].front() + 7) / 3;
        monkey[7].pop();
        if (current % 3 == 0)
            monkey[4].push(current);
        else
            monkey[1].push(current);
        
    }
}

int finalize(){
    int first_max = -INF, second_max = -INF;
    for (int i = 0; i < N; i++){
        if (monkey_inspect_count[i] > first_max){
            second_max = first_max;
            first_max = monkey_inspect_count[i];
        }else if (monkey_inspect_count[i] > second_max){
            second_max = monkey_inspect_count[i];
        }
    }
    return first_max * second_max;
}

int main(){
    initialize();
    for (int i = 0; i < 20; i++){
        begin_round();
    }
    fo << finalize();
}
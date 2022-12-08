#include<bits/stdc++.h>
#define N 1000001

using namespace std;

int d[N];
map<int, bool> visited;
vector<int> g[N];
int des; // nút đích

void BFS(int s){
    queue<int> qu;
    qu.push(s);
    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        for(auto v: g[u]){
            if(visited[v] == false){
                d[v] = d[u] + 1;
                visited[v] = true;
                qu.push(v);
            }
        }

    }
}

int main() {
    return 0;
}
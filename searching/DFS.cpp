#include<bits/stdc++.h>
#define N 1000001

using namespace std;

int d[N];
map<int, bool> visited;
vector<int> g[N];

void DFS(int s, int k){ // k là độ sâu yêu cầu (có thể bỏ)
    visited[s] = true;
    for(int v: g[s]){
        if(!visited[v]){
            visited[v] = true;
            DFS(v, k-1);
        }
    }
}

int main() {
    return 0;
}
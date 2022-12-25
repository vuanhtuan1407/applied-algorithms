#include<bits/stdc++.h>
#define N 1001

using namespace std;

int a[N][N];
int d[N][N];
int n, m;
int x, y;
int visited[N][N];
int result = -1;

int BFS(int x, int y) {
    queue<pair<int, int>> qu;
    qu.push(make_pair(x,y));
    visited[x][y] = 1;
    while (!qu.empty()) {
        pair<int, int> ceil = qu.front();
        qu.pop();
        int fi = ceil.first;
        int se = ceil.second;
        if (fi == 1 || fi == n || se == 1 || se == m){
            result = d[fi][se] + 1;
            // cout << fi << se << '\n';
            break;
        }
        else{
            if (!visited[fi+1][se]){
                d[fi+1][se] = d[fi][se] + 1;
                visited[fi+1][se] = 1;
                qu.push(make_pair(fi+1, se));
            }
            if (!visited[fi-1][se]){
                d[fi-1][se] = d[fi][se] + 1;
                visited[fi-1][se] = 1;
                qu.push(make_pair(fi-1, se));
            }
            if (!visited[fi][se+1]){
                d[fi][se+1] = d[fi][se] + 1;
                visited[fi][se+1] = 1;
                qu.push(make_pair(fi, se+1));
            }
            if (!visited[fi][se-1]){
                d[fi][se-1] = d[fi][se] + 1;
                visited[fi][se-1] = 1;
                qu.push(make_pair(fi, se-1));
            }
        }
    }
    
    return result;
}

int main() {
    cin >> n >> m >> x >> y;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
            if (a[i][j] == 1) visited[i][j] = 1;
        }
    }
    d[x][y] = 0;

    cout << BFS(x, y);
    return 0;
}
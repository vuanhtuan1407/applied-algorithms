#include<bits/stdc++.h>
#define N 100
#define inf 100000

using namespace std;

int n;
int start;
int c[N][N];
int x[N];
bool visited[N];
int f = 0;
int f_min = inf;
int g = 0;
int c_min = inf;

bool check(int v, int k){
    if(visited[v] == true) return false;
    return true;
}

void Try(int k){
    for(int v=1; v<=n; v++){
        if(check(v,k)){
            x[k] = v;
            visited[v] = true;
            f = f + c[x[k-1]][v];
            if(k==n) {
                if(f+c[v][start]<f_min) f_min = f+c[v][start]; // solution
            }
            else {
                g = f + (n-k+1)*c_min;
                if(g<f_min) Try(k+1);
            }
            f = f - c[x[k-1]][v];
            visited[v] = false;
        }
    }
}

int main() {
    start = 1;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> c[i][j];
            if(c[i][j]<c_min) c_min = c[i][j];
        }
    }
    x[1] = start;
    visited[start] = true;
    Try(2);
    // for(int i=1; i<=n; i++) cout << x[i] << ' ';
    // cout << endl;
    cout << f_min;
    return 0;
}
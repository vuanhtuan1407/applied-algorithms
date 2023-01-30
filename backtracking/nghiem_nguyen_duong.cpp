#include<bits/stdc++.h>
#define N 10000

using namespace std;

int n, M;
int a[N];
int x[N];
int res_check = 0;

bool check(int v, int k){
    return true;
}

void solution(){
    if(res_check == M){
        for(int i=1; i<=n; i++) cout << x[i] << ' ';
        cout << endl;
    }
}

void Try(int k){
    for(int v=1; v<=M; v++){
        if(check(v,k)){
            x[k] = v;
            res_check += a[k]*x[k];
            if(k==n) solution();
            else Try(k+1);
            res_check -= a[k]*x[k];
        }
    }
}

int main(){
    cin >> n >> M;
    for(int i=1; i<=n; i++) cin >> a[i];
    Try(1);
    return 0;
}
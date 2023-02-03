#include<bits/stdc++.h>
#define N 100

using namespace std;

int iMem[N][N];
int n,k;

int C(int k, int n){
    if(k==0 || k==n) return 1;
    if(iMem[k][n] != -1) return iMem[k][n];
    int res = C(k,n-1)+C(k-1,n-1);
    iMem[k][n] = res;
    return res;
}

int C_2(int k, int n){
    if(k==0 || k==n) return 1;
    int res = C(k,n-1)+C(k-1,n-1);
    return res;
}

int main() {
    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++) iMem[i][j] = -1;
    }
    cin >> n >> k;
    cout << C(k,n);
    cout << endl;
    cout << C_2(k,n);
    return 0;
}
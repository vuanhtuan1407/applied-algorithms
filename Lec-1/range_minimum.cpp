#include<bits/stdc++.h>

using namespace std;

int n, m;
int a[1000000];
int M[1000000][20];
long long Q = 0;

int minElement(int i, int j) {
    int min = a[i];
    for(int k=i; k<=j; k++){
        if(a[k] < min) min = a[k];
    }
    return min;
}

void preProcess() {
    for(int i=0; i<n; i++) M[i][0] = a[i];
    
    for(int j=1; (1<<j)<=n; j++){
        for(int i=0; i+(1<<(j-1))<n; i++){
            M[i][j] = std::min(M[i][j-1], M[i+(1<<(j-1))][j-1]);
        }
    }
}

int main() {
    cin >> n;
    for(int k=0; k<n; k++) cin >> a[k];
    
    cin >> m;

    preProcess();
    for(int k=0; k<m; k++){
        int i, j;
        cin >> i >> j;
        int t = log2(j-i+1);
        // Q += minElement(i, j);
        Q += std::min(M[i][t], M[j-(1<<t)+1][t]);
    }

    cout << Q;
    return 0;
}
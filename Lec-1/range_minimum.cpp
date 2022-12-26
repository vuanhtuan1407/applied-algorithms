#include<bits/stdc++.h>

using namespace std;

int n, m;
int a[1000000];
long long Q = 0;

int minElement(int i, int j) {
    int min = a[i];
    for(int k=i; k<=j; k++){
        if(a[k] < min) min = a[k];
    }
    return min;
}

int main() {
    cin >> n;
    for(int k=0; k<n; k++) cin >> a[k];
    
    cin >> m;
    for(int k=0; k<m; k++){
        int i, j;
        cin >> i >> j;
        Q += minElement(i, j);
    }

    cout << Q;
    return 0;
}
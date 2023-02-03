#include<bits/stdc++.h>
#define N 1000001

using namespace std;

int n;
int a[N];
int iMem[N];

int maxSubSeq(int i){
    if(i==1) return a[1];
    if(iMem[i] != -1) return iMem[i];
    int res = std::max(a[i], a[i] + maxSubSeq(i-1));
    iMem[i] = res;
    return res;
}

int main() {
    cin >> n;
    for(int i=1; i<=N; i++) iMem[i] = -1;
    for(int i=1; i<=n; i++) cin >> a[i];
    int res = maxSubSeq(n);
    for(int i=1; i<=n; i++){
        cout << iMem[i] << ' ';
        cout << endl;
        res = std::max(res, iMem[i]);
    }
    cout << res;
    return 0;
}
#include<bits/stdc++.h>
#define N 1000001

using namespace std;

int n;
int a[N];

int maxLeftMid(int l, int m){
    int sum = 0;
    int res = 0;
    for(int i = m; i>=l; i--){
        sum += a[i];
        if(sum>res) res = sum;
    }
    return res;
}

int maxRightMid(int m, int r){
    int sum = 0;
    int res = 0;
    for(int i = m; i<=r; i++){
        sum += a[i];
        if(sum>res) res = sum;
    }
    return res;
}

int SubSeqMax(int i, int j){
    if(i == j) return a[i];
    int mid = (i+j)/2;
    int wL = SubSeqMax(i,mid);
    int wR = SubSeqMax(mid+1,j);
    int wLM = maxLeftMid(i, mid);
    int wRM = maxRightMid(mid+1, j);
    int wM = wLM + wRM;
    return std::max(std::max(wL, wR), wM);
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    cout << SubSeqMax(1,n);
    return 0;
}
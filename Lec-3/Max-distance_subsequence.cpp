#include <bits/stdc++.h>

using namespace std;

int t;
int n, c;
long long x[1000001];

int check(int D){
    int current_value = x[1];
    int num = 1;
    for(int i=2; i<=n; i++) {
        if(current_value + D <= x[i]) {
            current_value = x[i];
            num++;
        }
    }
    return (num >= c);
}

int find_res(int min, int max){
    int l = min;
    int r = max;

    int res = -1;

    while(l<r) {
        int mid = (l+r+1)/2;
        if(check(mid) == true){
            res = std::max(res, mid);
            l = mid;
        }
        else r=mid-1;
    }
    return res;
}

int main(){

    cin >> t;
    while(t--){
        cin >>n >> c;
        for(int i=1; i<=n; i++) cin >> x[i];
        sort(x+1, x+n);
        cout << find_res(1, n) << ' ';
    }
    
    return 0;
}
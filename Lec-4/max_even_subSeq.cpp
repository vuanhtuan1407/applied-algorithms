#include<bits/stdc++.h>
#define N 10001
#define NOT_EXIST -1000001

using namespace std;

int n;
int a[N];
int s0[N], s1[N];
int res = NOT_EXIST;

void maxEvenSubSequence(){
    if(a[1]%2 == 0){
        s0[1] = a[1];
        s1[1] = NOT_EXIST;
    }
    else{
        s1[1] = a[1];
        s0[1] = NOT_EXIST; 
    }

    for(int i=2; i<=n; i++){
        // Quy hoach dong s0
        if(a[i]%2 == 0) s0[i] = std::max(a[i], s0[i-1]+a[i]);
        else if (a[i]%2 != 0 && s1[i-1] != NOT_EXIST) s0[i] = a[i]+s1[i-1];
        else s0[i] = NOT_EXIST;
        // cout << s0[i] << endl;

        // Quy hoach dong s1
        if(a[i]%2 != 0) s1[i] = std::max(a[i], s1[i-1]+a[i]);
        else if (a[i]%2 == 0 && s0[i-1] != NOT_EXIST) s1[i] = a[i]+s0[i-1];
        else s1[i] = NOT_EXIST;
        // cout << s1[i] << endl;

        // Combine Result
        res = std::max(res, s0[i]);
    }
    cout << res;
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    maxEvenSubSequence();
    return 0;
}
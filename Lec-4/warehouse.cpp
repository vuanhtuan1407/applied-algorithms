#include<bits/stdc++.h>
#define N 10001

using namespace std;

int n, T, D;
int a[N], t[N];
int f[N][N];
int res;

void findMaxSubSeq(){
    for(int i=1; i<=n; i++){
        for(int k=T; k>0; k--){
            if(k<t[i]) f[i][k]=0;
            else{
                if(i==1) f[i][k] = a[i];
                else
                    for(int j=i-D; j<=i-1; j++) f[i][k] = std::max(f[i][k], f[j][k-t[i]]);
            }
            res = std::max(res, f[i][k]);
        }
    }
    cout << res;
}

int main() {
    cin >> n >> T >> D;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> t[i];
    findMaxSubSeq();
    return 0;
}
#include<bits/stdc++.h>
#define N 10000

using namespace std;

int n,m;
int x[N];

bool check(int v, int k){
    return true;
}

void printCombineSeq(){
    for(int i=1; i<=m; i++) cout << x[i] << ' ';
    cout << endl;
}

void Try(int k) {
    for(int v=x[k-1]+1; v<=n; v++){
        if(check(v,k)){
            x[k] = v;
            if(k == m) printCombineSeq();
            else Try(k+1);
        }
    }
}

int main() {
    cin >> n >> m;
    x[0] = 0;
    Try(1);
    return 0;
}
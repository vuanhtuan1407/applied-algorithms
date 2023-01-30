#include<bits/stdc++.h>
#define N 100000

using namespace std;

int n;
int x[N];
int dem = 0;

bool check(int v, int k){
    return true;
}

void printBinarySeq() {
    dem += 1;
    for(int i=0; i<n; i++) cout << x[i] << ' ';
    cout << endl;
}

void Try(int k){
    for(int v=0; v<=1; v++){
        if(check(v,k)){
            x[k] = v;
            if (k == n-1) printBinarySeq();
            else Try(k+1);
        }
    }
}

int main() {
    cin >> n;
    Try(0);

    // check result
    if(dem == pow(2,n)) cout << true;
    else cout << false;
    return 0;
}
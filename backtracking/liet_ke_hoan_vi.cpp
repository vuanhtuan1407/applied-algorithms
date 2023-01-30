#include<bits/stdc++.h>
#define N 1000

using namespace std;

int n;
int x[N];
bool mark[N];
int dem = 0;

int Fac(int n){
    if (n<=1) return 1;
    else return n*Fac(n-1);
}

bool check(int v, int k) {
    if(mark[v] == true) return false;
    else return true;
}

void printSeq() {
    dem++;
    for(int i=1; i<=n; i++) cout << x[i] << ' ';
    cout << endl;
}

void Try(int k){
    for(int v=1; v<=n; v++){
        if(check(v, k)){
            x[k]=v;
            mark[v] = true;
            if(k==n) printSeq();
            else Try(k+1);
            mark[v] = false;
        }
    }
}

int main() {
    cin >> n;
    Try(1);

    //check
    if(dem == Fac(n)) cout << true;
    else cout << false;
    return 0;
}
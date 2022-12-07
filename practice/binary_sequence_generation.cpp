#include<bits/stdc++.h>
#define N 1000001

using namespace std;

int n;
int a[N];

void solution(){
    for(int i=0; i<n; i++) cout << a[i];
    cout << endl;
}

void Try(int k){
    for(int v=0; v<=1; v++){
        a[k] = v;
        if(k==n-1) solution();
        else Try(k+1);
    }
}

int main() {
    cin >> n;
    Try(0);    
    return 0;
}
#include<bits/stdc++.h>
#define N 1000001

using namespace std;

int n, M;
int a[N];
int x[N];
int T = 0;
int a_min = 0;
// int S[N];
int count_solution = 0;

int findMin() {
    int min = a[1];
    for(int i=2; i<=n; i++){
        if(min > a[i]) min = a[i];
    }
    return min;
}

void countSolution(){
    // if(T == M) count_solution += 1;
    if (T == M){
        // for(int i=1; i<=n; i++) cout << x[i] << ' ';
        // cout << endl;
        count_solution += 1;
    }
}

void Try(int k){
    for(int v=1; v<=(M-T-a_min*(n-k-1))/a[k]; v++){
        x[k] = v;
        T += a[k]*x[k];
        if(k == n) countSolution();
        else Try(k+1);
        T -= a[k]*x[k];
    }
}

int main() {
    cin >> n >> M;
    for(int i=1; i<=n; i++) cin >> a[i];
    a_min = findMin();
    Try(1);
    cout << count_solution;
    return 0;
}

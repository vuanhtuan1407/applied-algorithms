#include<bits/stdc++.h>
#define N 1000001

using namespace std;

int n, m;
int a[N];
int x[N];
int T = 0;
int S[N];
int count_solution = 0;

void countSolution(){
    if(T == m) count_solution += 1;
}

// void Try(int k){
//     for(int v=1; v<=S[k-1]; v++){
//         x[k] = v;
//         T += a[k]*x[k];
//         S[k] = (m-T)/((n-k+1)*a[k]);
//         if(k == n) countSolution();
//         else {
//             Try(k+1);
//             T -= a[k]*x[k];
//         }
//     }
// }

void Try(int k){
    for(int i=1; i<=m; i++){
        x[k] = i;
        T += a[k]*x[k];
        if(k == n) countSolution();
        else {
            Try(k+1);
            T -= a[k]*x[k];
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    // S[0] = m/(n*a[1]);
    Try(1);
    cout << count_solution;
    return 0;
}

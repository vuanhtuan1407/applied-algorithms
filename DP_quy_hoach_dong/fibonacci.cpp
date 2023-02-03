#include<bits/stdc++.h>
#define N 10000

using namespace std;

int iMem[N]; // Lưu giá trị đã tính

int fibonacci(int pos){
    if(pos <= 2) return 1;

    if(iMem[pos] != -1) return iMem[pos];

    int res = fibonacci(pos-1)+fibonacci(pos-2);
    iMem[pos] = res;

    return res;
}

int fibonacci_2(int pos){
    if(pos <= 2) return 1;
    return fibonacci_2(pos-1)+fibonacci_2(pos-2);
}

int main() {
    for(int i=1; i<=N; i++) iMem[i] = -1;
    int pos;
    cin >> pos;
    cout << fibonacci(pos);
    // cout << fibonacci_2(pos);
    return 0;
}
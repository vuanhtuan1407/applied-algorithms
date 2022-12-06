#include<bits/stdc++.h>
#define N 1000001

using namespace std;

int n;
long long a[N];
int d = 0;

int countTimePoint(){
    int point = a[1];
    int i=2;
    while(i<=n-1){
        if(a[i]>a[i-1] && a[i] > a[i+1]){
            d++;
            i+=2;
        }
        else i++;
    }
    return d;
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];

    cout << countTimePoint();

    return 0;
}
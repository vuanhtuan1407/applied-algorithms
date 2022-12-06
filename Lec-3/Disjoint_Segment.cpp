#include <bits/stdc++.h>
#define N 1000
using namespace std;

int n;

struct segment {
    int a;
    int b;
};

segment s[N];

bool comp(segment s1, segment s2){
    return s1.b <= s2.b;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s[i].a >> s[i].b;
    }
    sort(s, s+n-1, comp);
    int d = 1;
    int last = s[0].b;
    for(int i=1; i<n; i++){
        if(s[i].a >= last){
            d++;
            last = s[i].b;
        }
    }

    cout << d;

    return 0;
}

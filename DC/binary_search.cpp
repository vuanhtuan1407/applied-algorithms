#include<bits/stdc++.h>

using namespace std;

int n;
int k;
vector<int> vt;

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int a;
        cin >> a;
        vt.push_back(a);
    }
    sort(vt.begin(), vt.end());
    // bsearch()
    cin >> k;
    cout << binary_search(vt.begin(), vt.end(), k);
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int n;
int k;
vector<int> vt;

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        vt.push_back(i+2);
    }
    // sort(vt.begin(), vt.end());
    // bsearch()
    cin >> k;
    vector<int>::iterator low;
    // cout << binary_search(vt.begin(), vt.end(), k);
    low = lower_bound(vt.begin(), vt.end(), k);
    cout << (low-vt.begin());
    return 0;
}
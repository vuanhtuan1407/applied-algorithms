#include<bits/stdc++.h>
#define N 100000

using namespace std;

vector<int> a;
int n;

void merge(int L, int M, int R){
    vector<int> l,r;
    for(int i=L; i<=M; i++) l.push_back(a[i]);
    for(int j=M+1; j<=R; j++) r.push_back(a[j]);

    int n1 = M-L+1;
    int n2 = R-M;
    int i=0, j=0, k=L;

    while(i<n1 && j<n2){
        if(l[i]<r[j]){
            a[k] = l[i];
            k++;
            i++;
        }
        else{
            a[k] = r[j];
            k++;
            j++;
        }
    }

    while(i>=n1 && j<n2){
        a[k] = r[j];
        k++;
        j++;
    }

    while(j>=n2 && i<n1){
        a[k] = l[i];
        k++;
        i++;
    }
}

void mergeSort(int L, int R){
    if(L<R){
        int M = (L+R)/2;
        mergeSort(L, M);
        mergeSort(M+1, R);
        merge(L, M, R);
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        a.push_back(num);
    }

    mergeSort(0,n-1);

    for(int i=0; i<n; i++) cout << a[i] << ' ';

    return 0;
}
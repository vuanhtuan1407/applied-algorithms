#include<bits/stdc++.h>
#define N 10000

using namespace std;

int n;
bool markCol[N];
bool markDiag1[N]; // duong cheo chinh
bool markDiag2[N]; // duong cheo phu
int dem = 0;
int x[N];
bool barr[N];

bool check(int c, int r){
    if(markCol[c] == false && markDiag1[r-c+n] == false && markDiag2[r+c+n] == false) return true;
    else return false;
}

void printChessGround(){
    for(int r=1; r<=n; r++){
        for(int c=1; c<=n; c++){
            if(c == x[r]) cout << " x ";
            else cout << " - ";
        }
        cout << endl;
    }
    for(int i=1; i<=n; i++) cout << x[i] << "  ";
    cout << endl << "-----------------------" << endl;
}

void solution() {
    dem++;
    // for(int i=1; i<=n; i++) cout << x[i] << ' ';
    printChessGround();
    cout << endl;
}

void Try(int r){
    for(int c=1; c<=n; c++){
        if(check(c, r)){
            x[r] = c;
            markCol[c] = true;
            markDiag1[r-c+n] = true;
            markDiag2[r+c+n] = true;
            if(r == n) solution();
            else Try(r+1);
            markCol[c] = false;
            markDiag1[r-c+n] = false;
            markDiag2[r+c+n] = false;
        }
    }
}

int main() {
    cin >> n;
    Try(1);
    cout << dem << endl;

    for(int i=1; i<=n; i++) cout << barr[i] << ' ';
    return 0;
}
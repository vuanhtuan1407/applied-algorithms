#include<bits/stdc++.h>

using namespace std;

// Khai báo biến toàn cục
int n;

// Check giá trị v có thỏa mãn ràng buộc ở vị trí k không?
bool check(auto v, int k);

// Hàm xử lý result
void solution();

void Try (int k){
    int v; // chọn v từ tập ƯCV
    if(check(v, k) == true){
        // 1. S = S U {v}
        // 2. Xử lý dữ liệu (nếu có)
        // 3. Backtracking
            if (k == n) solution();
            else Try(k+1);
    }
}

int main() {
    //init data

    // call backtracking
    Try(0);
    return 0;
}
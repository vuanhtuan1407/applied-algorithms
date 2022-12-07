#include<bits/stdc++.h>
#define N 1000001

using namespace std;

// Khai báo biến toàn cục
int n;
int UCV[N];

// Check giá trị v có thỏa mãn ràng buộc ở vị trí k không?
bool check(auto v, int k);

// Hàm xử lý result
void solution();

void Try (int k){
    for(auto v : UCV){ // chọn v từ tập ƯCV
        if(check(v, k) == true){
            // 1. S = S U {v}
            // 2. Xử lý dữ liệu (nếu có)
            // 3. Backtracking
                if (k == n) solution();
                else Try(k+1);
            // 4. Xóa phương án cũ để chuyển sang quay lui
            // phương án mới
        }
    }
}

int main() {
    //init data

    // call backtracking
    Try(0);
    return 0;
}
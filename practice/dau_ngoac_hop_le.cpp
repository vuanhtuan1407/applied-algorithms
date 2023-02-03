#include<bits/stdc++.h>
#define N 1000000

using namespace std;

string par;

int checkParenthes(string par){
    stack<char> s;
    for(char c: par){
        if(c == '(' || c == '[' || c == '{') s.push(c);
        else if(c == ')' || c == ']' || c == '}') {
            if(s.empty()) return 0;
            char p = s.top();
            s.pop();
            if(c == ')' && p != '(') return 0;
            else if (c == ']' && p != '[') return 0;
            else if (c == '}' && p != '{') return 0;
        }
    }
    if(!s.empty()) return 0;
    return 1;
}

int main() {
    cin >> par;
    cout << checkParenthes(par);
    return 0;
}
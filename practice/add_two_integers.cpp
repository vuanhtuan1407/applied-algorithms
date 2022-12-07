#include<bits/stdc++.h>
using namespace std;

string a, b;
int maxlen = 0;
int re = 0;
stack<int> num1, num2, result;

void addTwoIntegers(string &a, string &b){
    for(char c: a) num1.push((c-'0'));
    for(char c: b) num2.push((c-'0'));
    if(a.length()>b.length()){
        for(int i=0; i<a.length()-b.length(); i++) num2.push(0);
    }
    else if (a.length()<b.length()){
        for(int i=0; i<b.length()-a.length(); i++) num1.push(0);
    }
    int digit = 0;    
    for(int i=0; i<maxlen; i++){
        if((!num1.empty()) && (!num2.empty())){
            digit = num1.top()+num2.top()+re;
            num1.pop();
            num2.pop();
            result.push(digit%10);
            re = digit/10;
        }
    }
    if(re != 0) result.push(re);
    while(!result.empty()){
        printf("%d", result.top());
        result.pop();
    }
}

int main(){
    cin >> a >> b;
    if(a.length()>=b.length()) maxlen = a.length();
    else maxlen = b.length();
    //cout << maxlen;
    addTwoIntegers(a,b);
    return 0;
}
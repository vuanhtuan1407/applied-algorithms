#include<bits/stdc++.h>
#define N 100001

using namespace std;

int total_transactions = 0;
int total_money = 0; 
map<string, int> money_from;
map<string, bool > checked;
map<string, bool> visited;
map<string, int> d;
map<string, vector<string>> from_to;
vector<string> accounts;
string a[N];
bool res = false;

bool comp(string acc1, string acc2){
    return acc1 <= acc2;
}

bool find_acc(vector<string> accounts, string des){
    for(string acc : accounts){
        if(acc == des) return true;
    }
    return false;
}

void print(){
    for(int i=0; i<a->length(); i++) cout << a[i] << ' ';
    cout << endl;
}

void find_cycle(string acc, string des, int length) {
    visited[acc] = true;

    if(length==0){
        visited[acc] = false;
        for(string v : from_to[acc]){
            if(v == des){
                res = true;
                return;
            }
        }
    }

    for(string v : from_to[acc]){
        if(!visited[v]){
            find_cycle(v, des, length-1);
        }
    } 

    visited[acc] = false;
    return;
}

int main(int argc, char const *argv[]) {
    
    int i=0;
    while(true) {

        string from_acc, to_acc, time_point, atm;
        int money;

        cin >> from_acc;
        if (from_acc == "#") break;
        cin >> to_acc >> money >> time_point >> atm;

        if(from_acc.length() >= 6 && from_acc.length() <= 20 && to_acc.length() >= 6 && to_acc.length() <= 20) total_transactions++;

        if(checked[from_acc] == false){
            accounts.push_back(from_acc);
            checked[from_acc] = true;
        }
        if(checked[to_acc] == false){
            accounts.push_back(to_acc);
            checked[to_acc] = true;
        }
        
        if(find_acc(from_to[from_acc], to_acc) == false && from_acc != to_acc) from_to[from_acc].push_back(to_acc);

        total_money += money;

        money_from[from_acc] += money;

    }

    while(true) {
        string type;
        cin >> type;

        if(type == "?number_transactions"){
            cout << total_transactions << endl;
        }
        else if(type == "?total_money_transaction"){
            cout << total_money << endl;
        }
        else if(type == "?list_sorted_accounts"){
            sort(accounts.begin(), accounts.end(), comp);
            for(string acc: accounts) cout << acc << ' ';
            cout << endl;
        }
        else if(type == "?total_money_transaction_from"){
            string from_acc;
            cin >> from_acc;
            cout << money_from[from_acc] << endl;
        }
        else if(type == "?inspect_cycle"){
            string acc;
            int length;
            cin >> acc >> length;

            // for(string from_acc: accounts){
            //     for(string acc: from_to[from_acc]) cout << acc << ' ';
            //     cout << endl;
            // }

            // cout << find_cycle(acc, acc, length) << endl;
            
            // reset res
            res = false;
            find_cycle(acc, acc, length-1);
            cout << res << endl;
        }
        else if(type == "#") break;
    }
    return 0;
}

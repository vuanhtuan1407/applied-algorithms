#include<bits/stdc++.h>

using namespace std;

struct Transaction {
    string from_acc, to_acc, time_point, atm;
    int money;
};

Transaction trans[10];

int total_transactions = 0;
int total_money = 0; 
map<string, int> money_from;
map<string, bool > checked;
map<string, bool> visited;
map<string, int> d;
map<string, vector<string>> from_to;

map<pair<string, string>, bool> checked_from_to;
vector<string> accounts;

bool comp(string acc1, string acc2){
    return acc1 <= acc2;
}

bool find_acc(vector<string> accounts, string des){
    for(string acc : accounts){
        if(acc == des) return true;
    }
    return false;
}

int BFS(string acc, int length) {
    bool res = false;
    queue<string> qu;
    qu.push(acc);
    visited[acc] = true;
    while (!qu.empty()) {
        string u = qu.front();
        qu.pop();
        for (string v : from_to[u]) {
            if (v == acc && d[u] == length-1){
                return 1;
            }
            else {
                d[v] = d[u]+1;
                qu.push(v);
            }
        }
    }
    return 0;   
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
        
        if(find_acc(from_to[from_acc], to_acc) == false) from_to[from_acc].push_back(to_acc);

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
            cout << BFS(acc, length) << endl;
        }
        else if(type == "#") break;
    }
    return 0;
}

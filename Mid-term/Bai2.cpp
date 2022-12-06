#include<bits/stdc++.h>

using namespace std;

struct Transaction {
    string from_acc, to_acc, time_point, atm;
    long long money;
};

Transaction trans[10000];

long long total_transactions = 0;
long long total_money = 0; 
map<string, long long> money_from;
map<string, bool> checked;
map<string, bool> visited;
map<string, int> d;
map<string, list<string>> from_to;
queue<string> qu;

bool comp1(Transaction t1, Transaction t2){
    return t1.from_acc <= t2.from_acc;
}

bool comp2(Transaction t1, Transaction t2){
    return t1.to_acc <= t2.to_acc;
}

// bool BFS(string acc) {
//     bool res = false;
//     qu.push(acc);
//     visited[acc] = true;
//     while (!qu.empty()) {
//         string u = qu.front();
//         qu.pop();
//         for (auto v : from_to[u]) {
//             if (!visited[v]) {
//                 d[v] = d[u]+1;
//                 visited[v] = true;
//                 qu.push(v);
//             }
//         }
//     }
// }

int main() {
    
    int i=0;
    while(true) {

        cin >> trans[i].from_acc >> trans[i].to_acc >> trans[i].money >> trans[i].time_point >> trans[i].atm;

        if(trans[i].from_acc.length() >= 6 && trans[i].from_acc.length() <= 20 && trans[i].to_acc.length() >= 6 && trans[i].to_acc.length() <= 20) total_transactions++;

        from_to[trans[i].from_acc].push_back(trans[i].to_acc);

        total_money += trans[i].money;

        money_from[trans[i].from_acc] += trans[i].money;

        fflush(stdin);

        if(getchar() == '#') break;

    }

    while(true) {
        string type;
        cin >> type;

        if(type == "?number_transactions"){
            cout << total_transactions << endl;
        }
        else if(type == "?total_money_transactions"){
            cout << total_money << endl;
        }
        else if(type == "?list_sorted_accounts"){
            int i=0, k=0;
            string sorted_account[100000];
            sort(trans, trans+total_transactions-1, comp1);
            while(i<total_transactions){
                if(checked[trans[i].from_acc] == true) sorted_account[k++]=trans[i++].from_acc;
                else i++;
            }
            i=0;
            sort(trans, trans+total_transactions-1, comp2);
            while(i<total_transactions){
                if(checked[trans[i].to_acc] == true) sorted_account[k++]=trans[i++].to_acc;
                else i++;
            }
            for(int i=0; i<total_transactions; i++) cout << sorted_account[i];

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
        }
        else if(type == "#") break;
    }



    return 0;
}
#include<bits/stdc++.h>

using namespace std;

bool check_phone_number = true;
bool checkPhoneNumber(string phone_number){
    if (phone_number.length() != 10) return false;
    for(char digit : phone_number){
        if (digit > '9' || digit < '0') return false;
    }
    return true;
}

map<string, long long> number_call_from;

long long number_total_calls = 0;

long long transform(string time){
    long long hh = (time[0]-'0')*10 + (time[1]-'0');
    long long mm = (time[3]-'0')*10 + (time[4]-'0');
    long long ss = (time[6]-'0')*10 + (time[7]-'0');

    return hh*3600 + mm*60 + ss;
}
long long timeDuration(string from_time, string to_time){
    return transform(to_time)- transform(from_time);
}
map<string, long long> count_time_calls_from;


int main() {
    
    while(true){
        string type;
        cin >> type;
        if (type == "#") break;
        
        string from_number, to_number, date, from_time, to_time;
        cin >> from_number >> to_number >> date >> from_time >> to_time;
        
        // pre-processing
        if (checkPhoneNumber(from_number) == false || checkPhoneNumber(to_number) == false) check_phone_number = false;
        else {
            number_total_calls++;
            count_time_calls_from[from_number] += timeDuration(from_time, to_time);
        }

        if(checkPhoneNumber(from_number) == true) number_call_from[from_number]++;

    }

    while (true){
        string query;
        cin >> query;
        if (query == "?check_phone_number"){
            cout << check_phone_number << "\n";
        }
        else if (query == "?number_calls_from"){
            string phone_number;
            cin >> phone_number;
            cout << number_call_from[phone_number] << "\n";
        }
        else if (query == "?number_total_calls"){
            cout << number_total_calls << "\n";
        }
        else if (query == "?count_time_calls_from"){
            string phone_number;
            cin >> phone_number;
            cout << count_time_calls_from[phone_number] << "\n";
        }
        else if (query == "#") break;
    }
    
    return 0;
}
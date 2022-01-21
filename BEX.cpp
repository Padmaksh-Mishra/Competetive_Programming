//Coding_Duck PM

# include <iostream>
# include <bits/stdc++.h>
# define ll long long

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N; 
    stack<pair<int,string>> S;
    vector<int> min;
    while(N--){
        int ip;
        cin >> ip;
        if(ip!=-1){
            pair<int,string> p;
            p.first = ip;
            string bookName;
            cin >> bookName;
            if(ip==0){
                continue;
            }
            S.push({ip,bookName});
            if((min.size()==0) or (ip<=min.back())){
                min.push_back(ip);
            }
        }else{
            int count = 0;
            while(S.top().first!=min.back()){
                count++;
                S.pop();
            }
            cout << count <<" " <<S.top().second << "\n";
            S.pop();
            min.pop_back();
        }
    }
    return 0;
}
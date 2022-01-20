//Coding_Duck PM

# include <iostream>
# include <bits/stdc++.h>
# define ll long long

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout.tie(NULL);

    int TT;
    cin >> TT; 
    while(TT--){
        int N,C;
        cin >> N >> C ;
        string s;
        cin >> s;
        set<char> Set;
        for(int i = 0; i < N; i++){
            Set.insert(s[i]);
        }
        if(C>Set.size()){
            cout << C-Set.size() << endl;
        }else{
            cout << "0" << endl;
        }
        
    }
    return 0;
}
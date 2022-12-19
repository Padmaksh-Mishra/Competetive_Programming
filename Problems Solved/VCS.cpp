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
        int N,M,K;
        cin >> N >> M >> K;
        map<int, int> m;
        set<int> s;
        int M_ignored[M] , K_tracked[K]; 
        for(int i = 0; i <M;i++) {
            cin >> M_ignored[i];
            m[M_ignored[i]]++;
            s.insert(M_ignored[i]);
        }
        for(int i = 0; i <K;i++) {
            cin >> K_tracked[i];
            m[K_tracked[i]]++;
            s.insert(K_tracked[i]);
        }
        int T_I = 0 ;
        for(auto val : m){
            //cout << val.first << " --> " <<val.second << endl;
            if(val.second == 2){
                T_I++;
            }
        }
        cout << T_I << " " << N-s.size() << endl;
        
    }
    return 0;
}
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
        int N,K,X;
        cin >> N >> K >> X;
        vector<int> V;
        int i = 0;
        if(K>=X){
            while(N--){
                if(i<X){
                    V.push_back(i);
                }else{
                    i = 0;
                    V.push_back(i);
                }
                i++;
            }
            for(auto val : V){
                cout << val << " ";
            }
            cout << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}
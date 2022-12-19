//Name.Redacted || Coding_Duck || PM

# include <bits/stdc++.h>	//iostream already included 
# define endl "\n"
using namespace std;
typedef long long ll;

ll calc_Goodness(string &s , ll N){
    ll goodness = 0;
    for(int i = 0; i<(N/2); i++){
        if(s[i]!=s[N-i-1]){
            s[i] = 'X';
            s[N-i] = 'X';
            goodness ++;
        }
    }
    //cout << "goodness = " << goodness << endl;
    return goodness;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC; 
    for(int j = 1;j<=TC;j++){
        ll N,K;
        string s;
        cin >> N >> K;
        cin >> s;
        //cout << "K = " << K << endl;
        K = K - calc_Goodness(s,N);
        // ll i = 0,operations = 0;
        // while(K>0){
        //     if(s[i]!='X'){
        //         s[N-i] = 'X';
        //         operations ++;
        //         K--;
        //     }
        //     i++;
        // }
        // cout << "Case #" << j << ": " << operations << endl;
        cout << "Case #" << j << ": " << K << endl;
    }
    return 0;
}
//Name.Redacted || Coding_Duck || PM

# include <bits/stdc++.h>	//iostream already included 

using namespace std;
typedef long long ll;

ll calc_Prefix(string s , int mid){
    ll calculations = 0;
    for(int i = mid-1 ; i >= 0 ; i--){
        calculations += ((int)s[i])%10;
        for(int j = 0; j < i ; j++) s[j] += ((int)s[i])%10;
    }
    return calculations;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC; 
    while(TC--){
        ll N,K;
        string s ;
        cin >> N >> K;
        cin >> s;
        int high = N , low = 0 , mid;
        // while(high > low){
        //     mid = (high + low)/2;
        //     ll operations = calc_Prefix(s.substr(0,mid),mid);
        //     if(K>=mid){
        //         low = mid;
        //     }else high = mid;
        // }
        // cout << mid << endl;
        cout << calc_Prefix(s,N) << endl;
    }    
    return 0;
}
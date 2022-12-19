//Name.Redacted PM

# include <bits/stdc++.h>	//iostream already included 

using namespace std;
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC; 
    while(TC--){
        vector<ll> V(3);
        for(int i = 0; i <3 ;i++) cin >> V[i];
        sort(V.begin(), V.end());
        if(V[0]+V[1]==V[2]){
            cout << "YES" << endl;
        }else cout << "NO" << endl;
    }
    return 0;
}
//Name.Redacted PM

# include <bits/stdc++.h>	//iostream already included 

using namespace std;
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    set<ll> s;
    for (int i = 0; i < n-1; i++) {
        ll temp;
        cin >> temp;
        s.insert(temp);
    }
    for (int i = 1; i < n+1; i++){
        if(s.find(i) == s.end()){
            cout << i;
        }
    } 
    return 0;
}
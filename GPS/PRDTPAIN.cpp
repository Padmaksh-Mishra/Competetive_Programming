//Coding_Duck PM

# include <iostream>
# include <bits/stdc++.h>
# define ll long long

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TT;
    cin >> TT; 
    while(TT--){
        ll n , sum=0;
        cin >> n;
        vector<ll> V;
        for(ll i = 0; i<n; i++){
            ll temp;
            cin >> temp;
            V.push_back(temp);
        }
        for (ll i = 0; i < n; i++)
        {
            for (ll k = i+2 ; k < n ; k++){

                auto func = [&](int j){
                    return (V[k]-V[j])*(V[j]-V[i]);
                };
                int j = lower_bound(V.begin()+i, V.begin()+k,(V[i]+V[k])/2) - V.begin();
                sum += max(func(j),func(j-1));
            }
        }
        cout << sum << endl;
    }
    return 0;
}
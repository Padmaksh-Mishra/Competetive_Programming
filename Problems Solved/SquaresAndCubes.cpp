//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

using namespace std;

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int TC;
    cin >> TC;
    while(TC--){
    
        ll n;
        cin >> n;
        set<int> set;
        for(int i = 1; i*i < n+1 ;i++) {
            set.insert(i*i);
        }
        for(int i = 1; i*i*i < n+1 ;i++) {
            set.insert(i*i*i);
        }
        cout << set.size() << endl;
    }

}

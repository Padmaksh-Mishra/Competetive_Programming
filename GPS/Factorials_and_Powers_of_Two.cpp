//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

int factorial[15]; 

void fact(){
    factorial[0] = 1;
    for(int i=1; i<15 ; i++){
        factorial[i] = factorial[i-1]*i;
    }
}
int setBits(ll n){
    int count = 0;
    while(n){
        if(n&1) count ++;
        n >>= 1;
    }
    return count;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    fact();
    while(TC--){
        ll n; cin >> n;
        set<ll> s;
        int *closestfact = (lower_bound(factorial,factorial+15,n)-1);
        if(setBits(n)==1) cout << 1 << endl;
        else if(*(closestfact+1)==n) cout << 1 << endl;
        else {
            int mini = 1;
            int facts = 0;
            cout << *factorial << endl;
            setBits(n);
            for(auto it = closestfact;it!=factorial+1;it--){
                ll k = *(it);
                n = n - k;
                //facts++;
                setBits(n);
                //mini = min(mini,extras);
                //cout << extras << endl;
            }
            cout << mini << endl;
        }

    }
    return 0;
}

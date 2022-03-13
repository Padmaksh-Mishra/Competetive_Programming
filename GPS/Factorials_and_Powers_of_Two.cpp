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
        if(setBits(n)==1) cout << 1 << endl;
        else {
            n = n - *((lower_bound(factorial,factorial+15,n)-1));
            
        }

    }
    return 0;
}

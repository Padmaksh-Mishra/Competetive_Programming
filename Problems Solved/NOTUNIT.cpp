//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int A,B; cin >> A >> B;
    if(A==1) cout << A << " " << A+1 << endl;
    else if(!(A&1)){
        if(B-A<2) cout << -1 << endl;
        else cout << A << " " << A + 2 << endl;
    }
    else{
        if(B-A<3) cout << -1 << endl;
        //else if(__gcd(A,A+1) !=1) cout << A << " " << A+1 << endl;
        //else if(__gcd(A,A+2) !=1) cout << A << " " << A +2 << endl;
        else if(__gcd(A,A+3) !=1) cout << A << " " << A + 3 << endl;
        else cout << A + 1 << " " <<  A + 3 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // useless since cout is not tied to anything

    int TC = 1;
    cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}

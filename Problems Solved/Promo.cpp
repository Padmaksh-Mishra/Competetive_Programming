//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	ll n,q; cin >> n >> q;
	vector<ll> p(n);
  	for(ll i=0;i<n;i++) cin >> p[i];
  	sort(p.begin(),p.end(),greater<ll>());
  	vector<ll> qr(n+1);
    qr[0]=0;
    for(ll i=0;i<n;i++){
        qr[i+1] += qr[i] + p[i];
        //deb(qr[i]);
    }
    while(q--){
        ll x,y ; cin >> x >> y;
        cout << qr[x]-qr[x-y] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // useless since cout is not tied to anything

    ll TC = 1;
    //cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}


//Binary Exponention Iterative
int bexpo(int n,int p){ 
    int ans = 1,tmp = n;
    while(p>0){
        if(p&1) ans = (ans * 1LL * tmp)%MOD;
        tmp = (tmp * 1LL * tmp)%MOD;
        p>>=1;
    }
    return ans;
}

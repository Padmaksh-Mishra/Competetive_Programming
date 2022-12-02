# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define pb push_back
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define all(x) (x).begin(), (x).end()

using namespace std;

const ll MOD = 1e9 +7;
const int N = 1e5 + 1;

void setIO(string name) {  
#ifndef ONLINE_JUDGE
    if((int)name.size() > 0){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
#endif
}

void solve();

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
    setIO("sublime");    //Does not work with Google     
    ll TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	ll n; cin >> n;
	ll sum=0;
	vll ips(n);
	for(int i=0;i<n;++i) cin >> ips[i],sum+=ips[i];

	multiset<ll> ms(all(ips));
	multiset<ll> q = {sum};

	while(q.size()){
		ll val = *(--q.end());
		q.erase(--q.end());

		if(val<*(--ms.end())){	//sabse badi value required se choti ho gai to chod do
			break;
		}
		if(ms.find(val)!=ms.end()){	
			ms.erase(--ms.end());
			continue;	
		}

		q.insert(ceil(val/2.0));
		q.insert(floor(val/2.0));
	}
	if(ms.size()) cout << "NO" << endl;
	else cout << "YES" << endl;
}

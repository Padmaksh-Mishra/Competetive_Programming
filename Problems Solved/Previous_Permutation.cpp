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
    //cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 
static bool cmp(pair<ll,ll> p,pair<ll,ll> q){
	if(p.f<q.f) return true;
	else if(p.f==q.f) return q.s>p.s;
	else return false;
}

void solve(){
	ll n; cin >> n;
	ll ips[n];
	for(int i=0;i<n;++i){
		cin >> ips[i];
	}
	ll dowithit = ips[n-1];
	pair<ll,ll> ans = {-1,-1};   
	ll pj = -1;
	// for(int i=n-1;i>=0;--i){
	// 	if(dowithit<ips[i]){
	// 		swap(ips[n-1],ips[i]);
	// 		sort(ips+i+1,ips+n,greater<ll>());
	// 	}else dowithit = ips[i];
	// }
	for(int i=n-1;i>=0;--i){
		for(int j=i;j>=0;--j){
			if(ips[i]<ips[j]){
				if(j>pj){
					pj = j;
					// if(ans.s!=0) continue;
					ans = make_pair(pj,i);
				}
			}
		}
	}
	ll a = ans.f,b = ans.s;
	// deb(a);
	// deb(b);
	swap(ips[a],ips[b]);
	sort(ips+a+1,ips+n,greater<ll>());
	for(int i = 0;i<n;++i){
		cout << ips[i] << " ";
	}
	cout << endl;
}

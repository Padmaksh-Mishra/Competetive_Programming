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
vll hsh(200001);
vll ips(200001);
ll n,m;
bool isPossible(ll t){
	ll tasksDone = 0;
	for(int i=1;i<=n;++i){
		tasksDone += min(t,hsh[i]) + ((t-min(t,hsh[i]))>>1);
	}
	if(tasksDone>=m) return true;
	else return false;
}
void solve(){
	cin >> n >> m;
	fill(all(hsh),0);
	for(int i=0;i<m;++i){
		ll tmp; cin >> tmp;
		hsh[tmp]++;
	}
	ll M = (m<<1);
	ll m = 1;
	ll mid = 0;
	while(M-m>1){
		mid = ((M+m)>>1);
		if(isPossible(mid)){
			M = mid;
		}else{
			m = mid+1;
		}
	}
	if(isPossible(m)) cout << m << endl;
	else if(isPossible(mid)) cout << mid << endl;
	else cout << M << endl;
}

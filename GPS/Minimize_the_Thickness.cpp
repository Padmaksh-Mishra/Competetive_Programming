# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define pb push_back
# define f first
// # define s second
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
	vll ps(n);
	cin >> ps[0];
	for(int i=1;i<n;++i){
		ll tmp; cin >> tmp;
		ps[i] = ps[i-1] + tmp;
	}    
	int ms=n;
	for(int k=n;k>0;--k){
		int s=0;
		int temp = 0;
	    int pos = -1;
	    int total_sum = ps[n-1];
    	if (total_sum % k != 0) break;
	    for (int i = 0; i < n; i++)
	    {       
	    	deb(ps[i] - ((pos == -1) ? 0 : ps[pos]));
	        if (ps[i] - ((pos == -1) ? 0 : ps[pos]) == (total_sum / k))
	        {
	        	s = max(s,i-pos);
	        	deb(s);
	            pos = i;
	            temp++;
	        }
	        else if (ps[i] - ps[pos] > (total_sum / k)) break;
	    }
	    if(temp == k) ms=min(ms,s),deb(k);
	}
	cout << ms << endl;
}

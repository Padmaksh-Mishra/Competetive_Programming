# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define pll pair<ll,ll>
# define all(x) (x).begin(), (x).end()

using namespace std;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9; 
const int N = 2e5 + 1;

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
	cin.tie(nullptr); 
    //setIO("sublime");    //Does not work with Google     
    ll TC = 1;
    //cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	stack<pll> stk;
	string s; cin >> s;
	//bitset<26> ht;
	ll n = siz(s);
	ll set = 0;
	ll rec = 0;
	for(int i=0;i<n;++i){
		if(s[i]=='('){
			stk.push(make_pair(i,rec));
			rec = 0;
		}else if(s[i]==')'){
			ll prv = stk.top().f;
			// deb(prv);
			set-=rec;
			rec = stk.top().s;
			stk.pop();
			// for(int j = i-1;j>prv;--j){
			// 	ht[s[j]-'a'] = 0;
			// }
		}else{
			// if(ht[s[i]-'a']==1){
			// 	cout << "No" << endl;
			// 	return;
			// }else ht[s[i]-'a'] = 1;
			if(set&(1<<(s[i]-'a'))){
				cout << "No" << endl;
				return;
			}else{
				set+=(1<<(s[i]-'a'));
				rec+=(1<<(s[i]-'a'));
			}
		}
		// for(auto val : ht) cout << val << " ";
		// cout << endl;
	}
	cout << "Yes" << endl;	    
}

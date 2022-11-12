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
	vector<char> abc(26);
	vector<bool> visited(26,false);

	for(int i=0;i<26;++i){
		abc[i] = 'a'+i;
		//deb(abc[i]);
	}    
	string s; cin >> s;
	deb(s);
	string b = "";
	map<char,char> m;
	ll j=0;
	for(auto val : abc){
		// deb(val);
		m[val] = '?';
	}
	ll lent = 0;
	for(int i=0;i<siz(s);++i){
		//deb(m[s[i]]);
		if(m[s[i]]!='?'){
			b+=m[s[i]];
		}else{
			for(int j=0;j<26;++j){
				//deb(m[abc[j]]);
				if(visited[j]) continue;
				if(abc[j]==s[i]) continue;
				if(m[abc[j]]=='?'){
					m[s[i]] = abc[j];
					lent++;
					b+=m[s[i]];
					visited[j] = true;
					break;
				}
				else if(m[abc[j]]!='?'){
					if(lent==25){
						m[s[i]] = abc[j];
						lent++;
						b+=m[s[i]];
						visited[j] = true;
						break;
					}
				}
			}
		}
		// deb(m[s[i]]);
	}
	cout << b << endl;
}

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
bool ok(vector<char> &parent,char posPar,char child){
	while(parent[posPar-'a']!='X'){
		if(parent[posPar-'a'] == child){
			return false;
		}
		posPar = parent[posPar-'a'];
		// deb(posPar);
	}
	//deb(posPar);
	return true;
}
void solve(){
	ll n; cin >> n;
	string t; cin >> t;
	vector<char> parent(27,'X');
	set<char> s;
	for(int i=0;i<26;++i){
		s.insert('a'+i);
	}
	for(int i=0;i<n;++i){
		auto itr = s.begin();
		if(parent[t[i]-'a']!='X') continue;
		while(itr!=s.end()){
			if((*itr)!=t[i]&&ok(parent,*itr,t[i])){
				parent[t[i]-'a'] = *itr;
				s.erase(itr);
				break;
			}
			++itr;	
		}
		
	} 
	string ans = "";
	for(int i=0;i<n;++i){
		if(parent[t[i]-'a']=='X') parent[t[i]-'a'] = *s.begin();
		ans+=parent[t[i]-'a'];
	}   
	cout << ans << endl;
}

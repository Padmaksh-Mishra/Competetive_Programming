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
static bool cmp(string a,string b){
	return a.size()>b.size();
}
string unique(string s)
{
    string str;
    int len = s.length();
 
    // loop to traverse the string and
    // check for repeating chars using
    // IndexOf() method in Java
    for(int i = 0; i < len; i++)
    {
         
        // character at i'th index of s
        char c = s[i];
 
        // If c is present in str, it returns
        // the index of c, else it returns npos
        auto found = str.find(c);
        if (found == std::string::npos)
        {
             
            // Adding c to str if npos is returned
            str += c;
        }
    }
    return str;
}
void solve(){
	ll n; cin >> n;
	set<int> s;
	ll old = 0;
	ll ans = 0;
	vector<string> ips(n);
	for(int i=0;i<n;++i){
		cin >> ips[i];
		ips[i] = unique(ips[i]);
	}
	sort(all(ips),cmp);
	for(int i=0;i<n;++i){
		string str = ips[i];
		// deb(str);
		unordered_set<char> st;
		for(int j=0;j<siz(str);++j) st.insert(str[j]);
		for(auto it=st.begin();it!=st.end();++it){
			if(s.find(*it)==s.end()) s.insert(*it);
		}
		if(siz(s)-old==siz(st)) ans++;
		old = siz(s);
	}  
	cout << (ans==0?1:ans) << endl;  
}
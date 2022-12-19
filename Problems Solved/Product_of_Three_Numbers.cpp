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
	map<ll,ll> m;
	set<ll> s;
	ll a,b,c;a=b=c=-1;

	while (n % 2 == 0)
    {
        m[2]++;
      	s.insert(2);
        n = n/2;
    }
	for(int i=3;i<=sqrt(n);i+=2){
		while(n%i==0){
			m[i]++;
			s.insert(i);
			n/=i;
		}
	}
	if(n>2){
		m[n]++;
		s.insert(n);
	}
	
	if(s.size()>2){
		a = *s.begin();
		a = pow(a,m[a]);
		s.erase(s.begin());
		b = *s.begin();
		b = pow(b,m[b]);
		s.erase(s.begin());
		c = 1;
		for(auto val : s){
			c *= pow(val,m[val]);
		}
	}else if(s.size()==2){
		ll tmp = m[*s.begin()] + m[*(++s.begin())];
		if(tmp>=4){
			a = *s.begin();
			b = *(++s.begin());
			c = pow(a,m[a]-1)*pow(b,m[b]-1);
		}
	}else{
		ll tmp = m[*s.begin()];
		if(tmp>=6){
			a = *s.begin();
			b = pow(a,2);
			c = pow(a,m[a]-3);	
		}
	}
	if(a==-1){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
 		cout << a << " " << b << " " << c << endl;
	}
}

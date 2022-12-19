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

const ll MOD = 1e18 +7;
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
ll capicity[501][501];
vll graph[501];

ll bfs(ll s,ll t,vll &parent){
	fill(all(parent),-1);
	parent[s] = -2;
	queue<pair<ll,ll>> q;
	q.push(make_pair(s,MOD));

	while(!q.empty()){
		ll current = q.front().f;
		ll flow = q.front().s;
		q.pop();

		for(ll next : graph[current]){
			if(parent[next]==-1&&capicity[current][next]){
				ll new_flow = min(flow,capicity[current][next]);	//flow sirf kam hoga badh nahi sakta
				parent[next] = current;								// as generate sirf source kar sakta hai
				if(next==t){
					return new_flow;
				}
				q.push(make_pair(next,new_flow));
			}
		}
	}
	return 0;
}

ll max_flow(ll s,ll t){
	ll flow = 0;
	vll parent(501);
	ll new_flow;
	while(new_flow = bfs(s,t,parent)){
		flow+=new_flow;
		ll current = t;
		while(current!=s){
			ll prv = parent[current];
			capicity[prv][current]-=new_flow;
			capicity[current][prv]+=new_flow;
			current = prv;
		}
	}
	return flow;
}
void solve(){
	ll n,m; cin >> n >> m;
	while(m--){
		ll a,b,c; cin >> a >> b >> c;
		graph[a].pb(b);
		graph[b].pb(a);
		capicity[a][b] += c;
		capicity[b][a] = 0;		//reverse ki capicity 0 hi hoti hai
	}
	cout << max(max_flow(1,n),0ll) << endl;
}

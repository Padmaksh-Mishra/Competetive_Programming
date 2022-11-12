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
bool graph[1001][1001],visited[1001][1001];
ll perimeter,area;
vector<pair<ll,ll>> moves = {
	{1,0},{-1,0},
	{0,1},{0,-1}
};
bool isValid(ll i,ll j){
	if(i<0||i>=1000||j<0||j>=1000) return false;
	else return true;
}
void dfs(ll i,ll j){
	// cout << i << " " << j << endl;
	if(!isValid(i,j)||!graph[i][j]){
		perimeter++;
		return;
	}
	if(visited[i][j]) return;
	visited[i][j] = 1;
	for(auto move : moves){
		dfs(i+move.f,j+move.s);
	}
	area++;
}
void solve(){
	ll n; cin >> n;
	pair<ll,ll> ap = {0,0};
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			char tmp; cin >> tmp;
			graph[i][j]=(tmp=='#') ? true : false;
		}
	}	    
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(!visited[i][j]&&graph[i][j]){
				dfs(i,j);
			}
			if(area>ap.f){
				ap.f = area;
				ap.s = perimeter;
			}else if(area==ap.f){
				ap.s = min(ap.s,perimeter);
			}
			area=perimeter=0;
		}
	}
	cout << ap.f << " " << ap.s << endl;
	return;
}

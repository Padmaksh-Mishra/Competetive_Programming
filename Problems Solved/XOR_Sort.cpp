# include <bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>

# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define pll pair<ll,ll>
# define vpll vector<pll>
# define all(x) (x).begin(), (x).end()

//Namespaces
using namespace __gnu_pbds;
using namespace std;

//Templates
template<typename T>
using ordered_set= tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>; //less_equal=ms can have duplicates
//order_of_key (K): Number of items strictly smaller than K.
//find_by_order(K): Kth element in a Set (counting from zero).

//Constants
const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9; 
const int N = 2e5 + 1;   

//For fileIO
void setIO(string name) {  
#ifndef ONLINE_JUDGE
    if((int)name.size() > 0){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
#endif
}

//bexpo
ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve();

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    //setIO("sublime");        
    ll TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Doing something good 
vector<pll> ans;
void cycle_sort(vll &Array, int array_size)
{
	for (int cycle_start = 0; cycle_start < array_size - 1; cycle_start++)
	{
		ll item = Array[cycle_start];

		int pos = cycle_start;
		for (int i = cycle_start + 1; i < array_size; i++)
			if (Array[i] < item)
				pos += 1;
		if (pos == cycle_start)
			continue;
		while (item == Array[pos])
			pos += 1;

		swap(Array[pos], item);
		ll xx = pos;
		ll yy = cycle_start;
		if(xx!=yy){
			ans.emplace_back(make_pair(xx,yy));
			ans.emplace_back(make_pair(yy,xx));
			ans.emplace_back(make_pair(xx,yy));
		}
		
		while (pos != cycle_start)
		{
			pos = cycle_start;
			for (int i = cycle_start + 1; i < array_size; i++)
				if (Array[i] < item)
					pos += 1;
			while (item == Array[pos])
				pos += 1;

			swap(Array[pos], item);
			xx = pos;
			yy = cycle_start;
			if(xx!=yy){
				ans.emplace_back(make_pair(xx,yy));
				ans.emplace_back(make_pair(yy,xx));
				ans.emplace_back(make_pair(xx,yy));
			}
		}
	}
}
void solve(){
	ans.clear();
    ll n; cin >> n;
    vll v(n),s(n);
    map<ll,ll> pos;
    for(int i=0;i<n;++i){
    	cin >> v[i];
    	s[i] = v[i];
    	pos[v[i]] = (i);
    }
    sort(all(v));
    vector<pll> ans;
    for(int i=0;i<n;++i){
    	if(v[i]==s[i]) continue;
    	ll old_pos = pos[v[i]];
    	// pos[v[i]].pop_back();
    	ll a = s[old_pos];
    	ll b = s[i];
    	ans.emplace_back(make_pair(i,old_pos));
    	ans.emplace_back(make_pair(old_pos,i));
    	ans.emplace_back(make_pair(i,old_pos));
    	s[old_pos] = b;
    	pos[b] = old_pos;
    	s[i] = a;
    }

    // cycle_sort(v,n);
    cout << siz(ans) << endl;
    for(auto val : ans){
    	cout << val.f+1 << " " << val.s+1 << endl;
    }
}

# include <bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>

# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define f first
# define s second
# define siz(x) (ll)(x).size()
# define vll vector<ll>
# define pll pair<ll,ll>
# define all(x) (x).begin(), (x).end()
# define YES cout<<"Yes"<<endl
# define NO cout<<"No"<<endl

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
const ll N = 2e5 + 1;   

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




//Trie implementation 

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode {
    TrieNode *children[11];
    int count;  //number of strings that have this node
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < 11; i++)
            children[i] = nullptr;
        isEndOfWord = false;
        count = 0;
    }
};

// trie data structure
class Trie {
    TrieNode *root;

public:
    Trie() {
        root = new TrieNode();
    }

    // insert a word into the trie
    void insert(vll &inv) {
        TrieNode *pCrawl = root;
        for (int i = 0; i < inv.size(); i++) {
            int index = inv[i];
            if (!pCrawl->children[index])
                pCrawl->children[index] = new TrieNode();
            pCrawl = pCrawl->children[index];
            pCrawl->count++;
        }
        pCrawl->isEndOfWord = true;
    }

    // search for a word in the trie
    bool search(vll &inv) {
        TrieNode *pCrawl = root;
        for (int i = 0; i < inv.size(); i++) {
            int index = inv[i];
            if (!pCrawl->children[index])
                return false;
            pCrawl = pCrawl->children[index];
        }
        return (pCrawl != nullptr && pCrawl->isEndOfWord);
    }
    
    // gives length of longest common subsequences -- atcoder
    int lcs(vll &inv) {
        TrieNode *pCrawl = root;
        ll ans = 0;
        for (int i = 0; i < inv.size(); i++) {
            int index = inv[i];
            // deb(index);
            if (!pCrawl->children[index])
                return ans;
            pCrawl = pCrawl->children[index];
            ans++;
        }
        return ans;
    }
};





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

void solve(){
    ll n,m; cin >> n >> m;
    vector<vll> v(n,vll(m));
    Trie trie;
    for(int i=0;i<n;++i){
    	vll tmp(m);
    	for(int j=0;j<m;++j){
    		cin >> v[i][j];
    		v[i][j]--;
    		// cout << v[i][j] << " ";
    		tmp[v[i][j]] = j;
    	}
    	// cout << endl;
    	trie.insert(tmp);
    	// for(auto val: tmp) cout << val << " ";
    	// cout << endl;
    	// deb(trie.lcs(tmp));
    }
    for(int i=0;i<n;++i){
    	cout << trie.lcs(v[i]) << " ";
    }
    cout << endl;
}

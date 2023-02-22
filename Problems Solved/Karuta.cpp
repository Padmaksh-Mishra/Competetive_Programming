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
const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode {
    TrieNode *children[ALPHABET_SIZE];
    int count;
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < ALPHABET_SIZE; i++)
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
    void insert(string word) {
        TrieNode *pCrawl = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = new TrieNode();
            pCrawl = pCrawl->children[index];
            pCrawl->count++;
        }
        pCrawl->isEndOfWord = true;
    }

    // search for a word in the trie
    bool search(string word) {
        TrieNode *pCrawl = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (!pCrawl->children[index])
                return false;
            pCrawl = pCrawl->children[index];
        }
        return (pCrawl != nullptr && pCrawl->isEndOfWord);
    }
    ll lcs(string word) {
        TrieNode *pCrawl = root;
        ll ans = 0;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (!pCrawl->children[index])
                return ans;
            pCrawl = pCrawl->children[index];
            if(pCrawl->count<2){
            	return ans;
            }else ans++;
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
    //cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Doing something good 

void solve(){
	ll n; cin >> n;
	Trie trie;
	vector<string> v(n);
	for(int i=0;i<n;++i){
		cin >> v[i];
		trie.insert(v[i]);
	}	    
	for(int i=0;i<n;++i){
		cout << trie.lcs(v[i]) << endl;
	}
}

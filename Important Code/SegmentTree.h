class SegmentTree {
public:
    SegmentTree(ll n, const vector<ll>& a) : n(n),t(2*N) {
        for (int i = 0; i < n; i++) {
            t[i + n] = a[i];
        }
    }

    void printLeves(){
        for(int i=n;i<(n<<1);++i){
            cout << t[i] << " ";
        }
        cout << endl;
    }

    // What operation you want to perform on tree (default is add)
    ll combine(ll a,ll b){
        return a+b;
    }
    //CAUTION: Don't forget to build the tree
    void build() {
        for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1],t[i<<1|1]);
    }

    //This code is for modification of an element
    void modify(ll p, ll value) {
        for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = combine(t[p] , t[p^1]);
    }

    //Access the entire interval
    ll query(ll l, ll r) {      //r is excluded
        ll res = 0;             //make inf in min
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = combine(res,t[l++]);
            if (r&1) res = combine(res,t[--r]);
        }
        return res;
    }
private:
    const ll n;
    vector<ll> t;
};
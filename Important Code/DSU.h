/* 
Without the small->large merging the time O(n) and also without the path compression but only small->large uinon
the time is O(logn) [true for revese also].
So for a better time complexity we need both of these optimizations leading to O(log*h)

log*h is the number of times I have to apply log to get a number smaller than 1

eg h = 2^65536

2^65536 -> 2^16 -> 2^4 -> 2^2 -> 2^1 -> 1 -> 0    6 times even for such a huge number (overflow in calculator)

Robert Tarjan was the first to prove the complexity in terms of the inverse Ackermann function. 
This is a very slow growing function.
In practice we can consider the disjoint-set to work in constant time for each operation.

We can also store the results of all assosicative operations of sets using dsu
*/

class DSU {
public:
    DSU(ll n) {
        parent.resize(n+1);
        size.resize(n+1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    // What operation you want to perform on tree (default is none) !!! only associ ops
    ll operate(ll a,ll b){
        return 0;
    }

    ll get(ll x) {
        if (parent[x] == x) return x;
        return parent[x] = get(parent[x]);
    }

    bool unite(ll x,ll y){		// union by size
    	ll px = get(x);
    	ll py = get(y);
    	if(px==py) return false;
    	if(size[px]>size[py]) swap(px,py);
    	parent[px] = py;
    	size[py] += size[px];
    	return true;
    }

    bool same_set(ll x,ll y){
    	return (get(x)==get(y));
    }

private:
	vll parent;
    vll size;
};

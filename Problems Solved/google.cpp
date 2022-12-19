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

void solve();

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
    ll TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
        cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 
// Function to print all subarrays in the array which
// has sum 0
ll ans;
void findSubArrays(vll &arr, int n,vll &ps)
{
	ans = 0;
    // create an empty map
    unordered_map<int, vector<int> > map;
  
    // create an empty vector of pairs to store
    // subarray starting and ending index
    vector <pair<int, int>> out;
  
    // Maintains sum of elements so far
    int sum = 0;
  
    for (int i = 0; i < n; i++)
    {
        // add current element to sum
        sum += arr[i];
  
        // if sum is 0, we found a subarray starting
        // from index 0 and ending at index i
        if (sum >= 0)
            out.push_back(make_pair(0, i));
  
        // If sum already exists in the map there exists
        // at-least one subarray ending at index i with
        // 0 sum
        if (map.find(sum) != map.end())
        {
            // map[sum] stores starting index of all subarrays
            vector<int> vc = map[sum];
            for (auto it = vc.begin(); it != vc.end(); it++){
                out.push_back(make_pair(*it + 1, i));
                ans+=(ps[i+1]-ps[*it]);
            }
        }
  
        // Important - no else
        map[sum].push_back(i);
    }
  
    // return output vector
    //return out;
}
void solve(){
	ll n; cin >> n;
	vll arr(n),ps(n+1,0);
	for(int i=0;i<n;++i) cin >> arr[i],ps[i+1] = ps[i] + arr[i];
	findSubArrays(arr,n,ps);
	cout << ans << endl;
}

//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const int sze = 1e5;
using namespace std;


int arr[sze];
void solve(){
	int N; cin >> N;
	ll cost = 0;
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}
	int sf = -1;
	int tail = N-1;
	int head = 0;
	while(head<=tail){
		if(arr[head]<arr[tail]){
			if(arr[head]>=sf){
				cost++;
				sf = arr[head];
			}
			head++;
		}else{
			if(arr[tail]>=sf){
				cost++;
				sf = arr[tail];	
			}
			tail--;
		}
	}
	cout << cost << endl;    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // useless since cout is not tied to anything

    int TC = 1;
    cin >> TC;
    int x = 0;
    while(TC--){
    	x++;
    	cout << "CASE #" << x <<": ";
        solve();
    }
    return 0;
}

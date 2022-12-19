# include <bits/stdc++.h>
# define endl "\n"
using namespace std;
int trees[300000];
int n;
typedef long long ll;
ll calc(int MaxH){
    ll odd = 0, even = 0,ans;
    for(int i = 0;i<n;i++){
        odd+=((MaxH-trees[i])&1);
        even+=((MaxH-trees[i])>>1);
    }
    if(odd>even) ans = odd*2 -1;
    else {
        ans = ((odd + even*2)/3)*2;
        int extra = (odd+even*2)%3;
        if(extra == 2) ans+=2;
        else if(extra == 1 ) ans+=1;
    }
    return ans;
}
void solve(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> trees[i];
    sort(trees,trees+n);
    ll ans1 = calc(trees[n-1]);
    ll ans2 = calc(trees[n-1]+1);
    if(ans1>ans2) cout << ans2 << endl;
    else cout << ans1 << endl;
}

int main(){
    int TC = 1;
    cin >> TC;
    while(TC--){
        solve();
    }
    
    return 0;
}
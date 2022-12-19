//Name.Redacted || Coding_Duck || PM

# include <bits/stdc++.h>	//iostream already included 

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC; 
    while(TC--){
        int N ,bigg;
        cin >> N;
        int ary[N];
        for(int i = 0; i < N;i++){
            cin >> ary[i];
            if(ary[i]>bigg) bigg=ary[i];
        }
    }
    return 0;
}
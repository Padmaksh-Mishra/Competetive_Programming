# include <bits/stdc++.h> //iostream already included
# define endl "\n"

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC;
    while (TC--){
        int N,K;
        cin >> N >> K;
        int arr[N];
        K = (N==K) ? 1 :N - K;
        //if(N&1) K++;
        for(int i = 0; i <N;i++) arr[i] = i+1;
        if((K>N)||(K==0)) cout << -1 << endl; 
        //else if (K==1) continue;
        else {
            if((K&1)&&(N>1)){
                int temp = arr[0];
                arr[0] = arr[1];
                arr[1] = temp;
                K--;
            }
            for(int i = N-1; i > 2; i--){
                if(K==1) break;
                int temp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = temp;
                K--;
            }
        }
        for(int i = 0 ; i <N ; i++) cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
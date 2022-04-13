#include <iostream>
# define endl "\n" 
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,k; cin >> n >> k;
    int ary[n];
    int hash[2] = {0,0};
    for(int i=0;i<n;i++){
        cin >> ary[i];
        if(ary[i]==1) hash[1]++;
        else hash[0]++;
    }
    int maxi = -1;
    for(int i = 0; i<k;i++){
        int count = 0;
        for(int h =i;h<n;h+=k){
            if(ary[h] == 1) count++;
            else count --;
        }
        maxi = max(maxi,abs(hash[1]-hash[0]-count));
    }
    cout << maxi << endl;
    return 0;
}
//Coding_Duck PM

# include <iostream>
using namespace std;
typedef long long ll;

bool isPossible(ll &h,int &coins){
    if((h*(h+1)/2)<=coins){
        return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TT;
    cin >> TT; 
    while(TT--){
        int N;
        cin >> N;
        ll low = 1,high = N,mid,answer = 0;
        while(low <= high){
            mid = (low+high)/2;
            if(isPossible(mid,N)){
                low = mid+1;
                answer = mid;
            }else{
                high = mid - 1;
            }
        }
        cout << answer << endl;
    }
    return 0;
}
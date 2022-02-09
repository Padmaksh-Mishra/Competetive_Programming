// Name.Redacted || Coding_Duck || PM

#include <bits/stdc++.h> //iostream already included

using namespace std;
typedef long long ll;

void print(vector<pair<int,int>> &ops);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int TC;
    cin >> TC;
    while(TC--){

        //Required fields
        int N;
        bool oddExists = false,odd = false,even = false;
        //ll count = 0;
        int array[N];
        //int odd_pos = -1,even_pos = -1; //DNE
        vector<pair<int, int>> ops1 , ops2;

        // Inputs
        cin >> N;

        //LOGIC BEGINS

        for(int i = 0; i < N; i++) {
            cin >> array[i];
            if(array[i]%2!=0){
                oddExists = true;
                if(i%2==0) even = true; ///////////////////
                else odd = true;                
            }
        }

        if(oddExists){

            if(odd){
                int odd_pos = -1;
                for(int i = 0; i <N ; i++) {
                    if((array[i]%2!=0) and (i&1)) odd_pos = i;
                }
                for(int i = 0; i < N; i++) {
                    if((array[i]%2!=0) and (!(i&1))) ops1.push_back({i,odd_pos});
                    else if((array[i]%2==0) && (i&1)) ops1.push_back({i,odd_pos});             
                }
            }
            else if(even){
                int even_pos = -1;
                for(int i = 0; i <N ; i++ ){
                    if((array[i]%2!=0) and (!(i&1))) even_pos = i;
                }
                for(int i = 0; i < N; i++) {
                    if((array[i]%2==0)&&(!(i&1))) ops2.push_back({i,even_pos});
                    else if((array[i]%2!=0)&&(i&1)) ops2.push_back({i,even_pos});             
                }
            }
            int ans1 = ops1.size(),ans2 = ops2.size();
            if(odd && even){
                if(ans1<ans2) print(ops1);
                else print(ops2);
            }
            else if(odd) print(ops1);
            else print(ops2);

        }else cout << "-1" << endl;
    }

    return 0;
}

void print(vector<pair<int,int>> &ops){
    cout << ops.size() << endl;
    for(auto [x,y] : ops){
        cout << x+1 << " " << y+1 << endl;
    }
}
//Coding_Duck PM

# include <iostream>
# include <bits/stdc++.h>
# define ll long long

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout.tie(NULL);

    int N;
    cin >> N;
    ll c = (N*(N-1))/2;
    map<int,pair<int,int>> m;
    for (int i = 0; i < c;i++){
        int T1, T2, G1, G2;
        cin >> T1 >> T2 >> G1 >> G2;
        m[T1].first += G1;
        m[T2].first += G2;
        if(G1>G2){
            m[T1].second +=4;
        }else if(G1<G2){
            m[T2].second +=4;
        }else{
            m[T1].second +=1;
            m[T2].second +=1;
        }
    }
    int max_Points = -1 , max_Goals = -1;
    int winner = -1;
    for(auto x : m){
        //cout << x.first << "-->" << x.second.first << "--" << x.second.second << endl;
        if(x.second.second==max_Points){
            if(max_Goals < x.second.first){
                max_Goals = x.second.first;
                winner = x.first;
                max_Points = x.second.second;
            }
        }else if(x.second.second>max_Points){
            winner = x.first;
            max_Points = x.second.second;
            max_Goals = x.second.first;
        }
    }
    cout << winner << endl;
    return 0;
}
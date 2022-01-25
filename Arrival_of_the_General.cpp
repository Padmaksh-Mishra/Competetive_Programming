//Coding_Duck PM

# include <iostream>
# include <bits/stdc++.h>
# define ll long long

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n; 
    //int max_no,min_no;
    vector<int> V;
    for(int i = 0;i < n;i++){
        int temp;
        cin >>  temp;
        V.push_back(temp);
    }
    auto max_no = max_element(V.begin(),V.end());
    auto min_no = min_element(V.begin(),V.end());
    //auto posOFmax = lower_bound(V.begin(),V.end(),max_no);
    //auto posOFmin = lower_bound(V.begin(),V.end(),min_no);
    int ans = (V.end()-1-min_no) + (max_no - V.begin());
    if((abs(max_no-min_no)==1)&&((min_no == V.begin())||(max_no == V.end()-1))){
        ans--;
    }
    cout << ans;
    return 0;
}
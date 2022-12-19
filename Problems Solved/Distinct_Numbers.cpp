# include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	set<int> uos;
	while(n--){
		int temp; cin >> temp;
		uos.insert(temp);
	}
	cout << uos.size();
	return 0;
}

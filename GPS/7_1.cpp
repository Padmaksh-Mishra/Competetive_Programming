# include <bits/stdc++.h>
using namespace std;

void printans(vector<int> &ans){
	reverse(ans.begin(), ans.end());
	for(auto val : ans){
		cout << val;
	}
	cout << endl;
}
int main(){
	vector<int> multiple;
	int element;
	int sum = 0;
	cout << "Please input the size of array : ";
	int n;
	cin >> n;	//please provide the size of the multiple array
	cout << "Please input the array : ";
	for(int i=0;i<n;++i){
		int element;
		cin >> element;
		multiple.push_back(element);
		sum+=element;
	}
	cout << endl;
	int rem = sum%3;
	sort(multiple.begin(), multiple.end());

	if(rem==0){
		//do nothing
	}
	else if(rem==1){
		bool ok = false;
		for(int i=0;i<n;++i){
			if(multiple[i]%3==1){
				multiple.erase(multiple.begin()+i);
				ok = true;
				break;
			}
		}
		if(!ok) {
			cout << " NO COMBINATION EXISTS " << endl;
			return 0;
		}
	}
	else{
		vector<int> rem1;	//will store the smallest 2 elements having reminder 1 
							//it will be used 
		bool ok = false;
		for(int i=0;i<n;++i){
			if(multiple[i]%3==2){
				multiple.erase(multiple.begin()+i);
				ok=true;
				break;
			}
			if(rem1.size()<2){
				if(multiple[i]%3==1) rem1.push_back(i);
			}
		}
		if(ok){
			// Do nothing
		}
		else if(rem1.size()==2&&!ok){
			multiple.erase(multiple.begin()+rem1[0]);
			multiple.erase(multiple.begin()+rem1[1]-1);
		}
		else{
			cout << " NO COMBINATION EXISTS " << endl;
			return 0;
		}
	}
	if(multiple.size()==0|| multiple[0]==0){
		cout << " NO COMBINATION EXISTS " << endl;
	}
	else printans(multiple);
	return 0;
}
# include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cout << "Enter the number of buildings : ";
	cin >> n;
	cout << "Enter the height of buildings : \n";
	vector<int> height(n);
	for(int i=0;i<n;++i){
		cin >> height[i];
	}
	vector<int> leftmax(n+2,0),rightmax(n+2,0);		//will store the max height to the left and the right of the index respectively
													//0 and n+1 th index will be 0 for them
	for(int i=0;i<n;++i){
		leftmax[i+1] = max(leftmax[i],height[i]);
	}
	for(int i=n;i>0;--i){
		rightmax[i] = max(rightmax[i+1],height[i-1]);
	}
	int totalWater = 0;
	for(int i=0;i<n;++i){
		totalWater+=max(0,min(leftmax[i+1],rightmax[i+1])-height[i]);
	}
	cout << totalWater << endl;
	return 0;
}
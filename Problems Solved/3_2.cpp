# include <bits/stdc++.h>
using namespace std;

// NOTE
//IN the output we get an extra line having id as 0 this is because map stores all values as 0

struct job{
	int id;
	int arrival_tme;
	int priority;
	int processing_tme;
};

map<int,struct job> System;
vector<int> pq;		//vector havin priorities of the elements to be prossed
vector<int> aux_queue;
int tme;

void process(int priority){		//Simulates the task
	for(auto it = System.begin();it!=System.end();++it){
		struct job task = (*it).second; 
		if(task.priority==priority){
			cout << "id:" << task.id << " :insert tme=" << task.arrival_tme << " :start tme=" << tme;
			tme+=task.processing_tme;
			System.erase(it);	//Remove the completed task
			return;
		}

	}
}

void heapify(vector<int> &pq,int i){	//heapify the pq
	int n = pq.size();
	int largestindx = i;
  	int leftChild = (2*i + 1<n) ? pq[2*i + 1] : -1;
  	int rightChild = (2*i + 2<n) ? pq[2*i + 2] : -1;
	if (leftChild > pq[largestindx]){
	  	largestindx = 2*i + 1;
	}
	if (rightChild > pq[largestindx]){
		largestindx = 2*i + 2;
	}
	swap(pq[i],pq[largestindx]);
}

void max_heap(vector<int> &pq){
	int n = pq.size();
	for(int i=(n/2)-1;i>=0;--i){
		heapify(pq,i);
	}
}

int main(){
	int n; 
	cin >> n;
	for(int i=0;i<n;++i){
		struct job task;
		int id;
		cin >> id;
		task.id = id;
		cin >> task.arrival_tme;
		cin >> task.processing_tme;
		cin >> task.priority;
		aux_queue.push_back(id);
		System[id]=task;
	}
	while(System.size()!=0){
		for(auto it = aux_queue.begin();it!=aux_queue.end();++it){
			if(System[(*it)].arrival_tme<=tme){
				pq.push_back(System[(*it)].priority);
			}
		}
		while(pq.size()!=0){
			max_heap(pq);
			process(pq[0]);
			pq.erase(pq.begin());
			cout << endl;
		}
	}
	return 0;
}
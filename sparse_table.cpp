#include <bits/stdc++.h>
using namespace std;

//sparse table to solve range minimum queries 
//Time complexity for preprocessing - O(N*log(N))
//O(1) for queries

const int Max = 1e5+9;
const int Log = 17;
int LOG[Max];
int arr[Max]; //input array
int ans[Max][Log]; //it denotes the min in range (i,2^j);

void prepcompute(int n){
	//for 2^0 it's the element itself
	for(int i=0; i<n; ++i){
		ans[i][0] = arr[i];
	}

	//finding min for every power of 2 starting from 1 to log(n);
	for(int j=1; j<Log; ++j){
		for(int i=0; i+(1<<j)-1<n; ++i){
			ans[i][j] = min(ans[i][j-1],ans[i+(1<<(j-1))][j-1]);
		}
	}
	//precompute log(r-l+1) for every range of
	LOG[1]=0;
	for(int i=2; i<=Max; ++i){
		LOG[i] = LOG[i/2]+1;
	}
}

int query(int l, int r){
	// for range minimum queries you can just use two range of 
	//power of 2 rather than log(r-l+1); 

	//actual query
	int j = LOG[r-l+1];
	return min(ans[l][j],ans[r-(1<<j)+1][j]);

}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>arr[i];
	}
	prepcompute(n);
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<query(l,r)<<"\n";
	}
}

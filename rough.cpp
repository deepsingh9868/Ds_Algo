// #include <bits/stdc++.h>
// using namespace std;


// struct Node{
// 	int val;
// 	Node* next;
// 	Node(int v){
// 		val=v;
// 	}
// };

// //1->2->3;  x=3;

// int solve(Node* head, int x){
// 	int ans=-1;
// 	while(head!=NULL){
// 		if(head->val==x){
// 			ans = x;
// 			break;
// 		}
// 		head = head->next;
// 	}
// 	return ans;
// }


// int main(){
// 	Node* head = new Node(1);
// 	head->next = new Node(2);
// 	head->next->next= new Node(3);
// 	cout<<solve(head,4);
// }


#include <bits/stdc++.h>
using namespace std;


// const int mx = 1000;
// int vis[mx][mx];
// int dx[8] = {-1,1,0,0,-1,1,-1,1};
// int dy[8] = {0,0,-1,1,-1,-1,1,1};

// bool valid(vector<vector<int>>& a, int r, int c, int n, int m){
// 	if(r>=0 and r<n and c>=0 and c<m and !vis[r][c] and a[r][c]==1) return true;
// 	return false;
// }

// void dfs(vector<vector<int>>& a, int r, int c, int n, int m, int& ans){
// 	vis[r][c]=1;
// 	ans++;
// 	for(int i=0; i<8; ++i){
// 		int x = dx[i]+r;
// 		int y = dy[i]+c;
// 		if(valid(a,x,y,n,m)) dfs(a,x,y,n,m,ans);
// 	}
// }

// void solve(){
// 	int n,m;
// 	cin>>n>>m;
// 	vector<vector<int>> a(n,vector<int>(m));
// 	for(int i=0; i<n; ++i){
// 		for(int j=0; j<m; ++j){
// 			cin>>a[i][j];
// 		}
// 	}
// 	int res=0;
// 	for(int i=0; i<n; ++i){
// 		for(int j=0; j<m; ++j){
// 			if(!vis[i][j] and a[i][j]==1){
// 				int ans=0;
// 				dfs(a,i,j,n,m,ans);
// 				res = max(res,ans);
// 			}
// 		}
// 	}
// 	cout<<res<<"\n";

// }

// int main(){
//     solve();
// }


void solve(){
}

int main(){
	solve();
}

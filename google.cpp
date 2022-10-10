#include <bits/stdc++.h>
using namespace std;

int vis[100000];
int level_cnt[100000];
int level[100000];
vector<int> adj[100000];


void dfs(int src){
	vis[src]=1;
	for(auto c: adj[src]){
		if(!vis[c]){
			level[c] = level[src]+1;
			dfs(c);
		}
	}
}

void solve(){
	memset(vis,0,sizeof(vis));
	memset(level,0,sizeof(level));
	memset(level_cnt,0,sizeof(level_cnt));
	int n,q;
	cin>>n>>q;
	for(int i=1; i<n; ++i){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int Q=q;
	while(q--){
		int x;
		cin>>x;
	}
	dfs(1);
	for(int i=1; i<=n; ++i){
		level_cnt[level[i]]++;
	}
	int ans=0,it=0;
	while(Q>0){
	    if(level_cnt[it]>Q) break;
	    ans+=level_cnt[it];
	    Q-=level_cnt[it];
	    it++;
	}
	
	cout<<ans<<"\n";
}

int main(){
	int t,tt=0;
	cin>>t;
	while(t--){
		cout<<"Case #"<<++tt<<": ";
		solve();
	}
}
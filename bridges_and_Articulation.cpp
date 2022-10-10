#include <bits/stdc++.h>
#define dbg(x) cout<<#x<<" "<<x<<"\n";
#define ll long long  
#define ld long double
using namespace std;

//find articulation point and bridges in a graph

// Conditions
// Now we need to know if some vertex U is an articulation point. So, for that we will check the following conditions:

// #1) If there is NO way to get to a node V with strictly smaller discovery time than the discovery 
//     time of U following the DFS traversal, then U is an articulation point. (it has to be strictly because 
//     if it is equal it means that U is the root of a cycle in
//     the DFS traversal which means that U is still an articulation point).

// #2) If U is the root of the DFS tree and it has at least 2 children subgraphs
// disconnected from each other, then U is an articulation point.

vector<int> adj[2000];
int disc[2000],low[2000],ap[2000];
int Time=0;

int dfs(int curr, int parent){
    int children = 0;
    low[curr]=disc[curr] = ++Time;
    for(auto& c: adj[curr]){
        if(c==parent) continue;  //we don't want to go back through the same path.
        // if we go back is because we found another way back
        
        if(!disc[c]){
            children++;
            dfs(c,curr);
            if(disc[curr]<=low[c]){ //condition #1
                ap[curr] = 1;//means that node is a articulation point
            }
            low[curr] = min(low[curr],low[c]); //low[c] might be an ancestor of curr
        }
        //if curr was already discovered means that we found an ancestor          
        else{
            low[curr] = min(low[curr],disc[c]);//finds the ancestor with the least discovery time
        }
    }
    return children;
}


//In case of bridges just use disc[curr]<low[c]

void solve(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0; i<n; ++i){
        if(!disc[i]){
            ap[i] = dfs(i,i)>1;//condition for root node
        }
    }
    for(int i=0; i<n; ++i){
        cout<<ap[i]<<" ";
    }


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

 





#include <bits/stdc++.h>
using namespace std;


// //union find 
// //uses-> 1) used to find cycle in a undirected graph
// //       2) find two nodes belong to same component or not
// //       3) used in kruskal algo
// // operations -> 1) find -> find the parent of a node i.e which set it belong to 
// //               2) union -> if two nodes have different parent then union them

// const int mx = 1000;
// int Rank[mx];
// int parent[mx];

// void init(){
//     for(int i=1; i<=mx; ++i){
//         parent[i]=i; // initallizing itself its parent or you can also assign -1 
//         Rank[i]=0;
//     }
// }
// int find_par(int node){
//     if(node==parent[node]) return node;
//     return parent[node] = find_par(parent[node]); //path compression
// }

// bool Union(int x, int y){ // this will return true if there is no cycle
//     int par_x = find_par(x);
//     int par_y = find_par(y);
//     if(par_x==par_y) return false; // don't include because it's forming a cycle
//     else if(Rank[par_x]<Rank[par_y]) parent[par_x] = par_y;
//     else if(Rank[par_y]<Rank[par_x]) parent[par_y] = par_x;
//     else{
//         parent[par_x]=par_y;
//         Rank[par_y]++;
//     }
//     return true;
// }


void solve(){
	
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










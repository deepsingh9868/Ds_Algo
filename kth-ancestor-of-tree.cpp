#include <bits/stdc++.h>
#define dbg(x) cout<<#x<<" "<<x<<"\n";
#define ll long long  
#define ld long double
using namespace std;

const int mx = 1e5+9;
vector<int> adj[mx];
vector<int> fake[mx];
map<int,int> mp;





int solve(){
   int n;
   cin>>n;
   int temp=n;
   temp--;
   vector<pair<int,int>> v;
   while(temp--){
    int a,b;
    cin>>a>>b;
    fake[a].push_back(b);
    fake[b].push_back(a);
    v.push_back({a,b});
   }
   
   for(int i=0; i<n; ++i){
    int x;
    cin>>x;
    mp[i+1]=x;
   }
   int Max=0,node;
    for(int i=1; i<=n; ++i){
        if(fake[i].size()>Max){
            Max = fake[i].size();
            node=i;
        }
    }
    for(auto c: v){
        if(c.first!=node and c.second!=node){
            adj[c.first].push_back(c.second);
            adj[c.second].push_back(c.first);
        }
    }
    // cout<<node;
    int sum=0;
    for(int i=1; i<=n; ++i){
        if(i!=node){
            int result=0;
            for(auto c: adj[i]){
                cout<<c<<": "<<mp[c]<<"\n";
                result = __gcd(mp[c],result);
                if(result==1){
                    sum+=1;
                    break;
                }
            }
            sum+=result;
        }
    }
    // cout<<sum<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
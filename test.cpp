//                           ,;;;;;;,
//                                 ,;;;'""`;;\
//                               ,;;;/  .'`',;\
//                             ,;;;;/   |    \|_
//                            /;;;;;    \    / .\
//                          ,;;;;;;|     '.  \/_/
//                         /;;;;;;;|       \
//              _,.---._  /;;;;;;;;|        ;   _.---.,_
//            .;;/      `.;;;;;;;;;|         ;'      \;;,
//          .;;;/         `;;;;;;;;;.._    .'         \;;;.
//         /;;;;|          _;-"`       `"-;_          |;;;;\
//        |;;;;;|.---.   .'  __.-"```"-.__  '.   .---.|;;;;;|
//        |;;;;;|     `\/  .'/__\     /__\'.  \/`     |;;;;;|
//        |;;;;;|       |_/ //  \   //  \ \_|       |;;;;;|
//        |;;;;;|       |/ |/    || ||    \| \|       |;;;;;|
//         \;;;;|    __ || _  .-.\| |/.-.  _ || __    |;;;;/
//          \jgs|   / _\|/ = /_o_\   /_o_\ = \|/_ \   |;;;/
//           \;;/   |`.-     `   `   `   `     -.`|   \;;/
//          _|;'    \ |    _     _   _     _    | /    ';|_
//         / .\      \_  ( '--'(     )'--' )  _//      /. \
//         \/_/       \_/|  /_   |   |   _\  |\_/       \_\/
//                       | /|\  \   /  //|\  |
//                       |  | \'._'-'_.'/ |  |
//                       |  ;  '-.```.-'  ;  |
//                       |   \    ```    /   |
//     __                ;    '.-"""""-.'    ;                __
//    /\ \_         __..--\     `-----'     /--..__         _/ /\
//    \_'/\`''---''`..;;;;.'.__,       ,__.',;;;;..`''---''`/\'_/
//         '-.__'';;;;;;;;;;;,,'._   _.',,;;;;;;;;;;;''__.-'
//              ``''--; ;;;;;;;;..`"`..;;;;;;;; ;--''``   _
//         .-.       /,;;;;;;;';;;;;;;;;';;;;;;;,\    _.-' `\
//       .'  /_     /,;;;;;;'/| ;;;;;;; |\';;;;;;,\  `\     '-'|
//      /      )   /,;;;;;',' | ;;;;;;; | ',';;;;;,\   \   .'-./
//      `'-..-'   /,;;;;','   | ;;;;;;; |   ',';;;;,\   `"`
//               | ;;;','     | ;;;;;;; |  ,  ', ;;;'|
//              _\__.-'  .-.  ; ;;;;;;; ;  |'-. '-.__/_
//             / .\     (   )  \';;;;;'/   |   |    /. \
//             \/_/   (`     `) \';;;'/    '-._|    \_\/
//                     '-/ \-'   '._.'         `
//                       """      /.`\
//                                \|_/




#include <bits/stdc++.h>
#define dbg(x) cout<<#x<<" "<<x<<"\n";
#define ll long long  
#define ld long double
using namespace std;

//binary exponentiation takes (log(power) multiplcations)
const int mod  =998244353;
ll power(ll n, ll p){
    ll ans = 1;
    while(p>0){
        if(p&1) ans = (ans*n)%mod;
        n=(n*n)%mod;
        p>>=1;
    }
    return ans;
}

//Euclid gcd
ll gcd(ll a, ll b){
    return b? gcd(b,a%b):a;
}

//sieve of eratosthenes to finding all the prime numbers in a give range
// vector<bool> isprime(n,true);
// for(int i=2; i<=n; ++i){
//     if(isprime[i]){
//         for(int j=i*i; j<=n; j+=i){
//             isprime[j]=0;
//         }
//     }
// }





//largest power of two less than or equal to n
ll largestpower2(ll n){
    return log2(n);
    
}

bool ispower2(ll n){
    return (n && (!(n&(n-1))));
    
}

ll modInverse(ll n){
    return power(n,mod-2);
}

//selection sort
void selection_sort(int arr[], int n){
    for(int i=0; i<n-1; ++i){ //we need to do n-2 passes last element is already sorted
        int mid_ind = i;
        for(int j=i+1; j<n; ++j){ //find the min from i to n index and swap 
            if(arr[j]<arr[mid_ind]){
                mid_ind=j;
            }
        }
        swap(arr[i],arr[mid_ind]);
    }
    for(int i=0; i<n; ++i) cout<<arr[i]<<" ";
}
    


//bubble sort
void bubble_sort(int arr[], int n){
    for(int i=0; i<n-1; ++i){
        bool flag=false;
        for(int j=0; j<n-i-1; ++j){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=true;
            }
        }
        if(flag==false) break; // array is already sorted
    }
    for(int i=0; i<n; ++i) cout<<arr[i]<<" ";
}


//mergesort
//It's a divde and conquer algo
//we will divide the array in 2 equal half from mid and keep on doing that
//until we reach only 1 element then we start merging it

void mergetwosortedlist(int arr[],int left[], int right[], int n, int m){
    int i=0,j=0,k=0;
    while(i<n and j<m){
        if(left[i]<=right[j]){
            arr[k++]=left[i++];
        }
        else{
            arr[k++]=right[j++];
        }
    }
    while(i<n){
        arr[k++]=left[i++];
    }
    while(j<m){
        arr[k++]=right[j++];
    }
}

void merge_sort(int arr[], int n){
    if(n==1) return;
    int mid = n/2;
    int left[mid],right[n-mid];
    for(int i=0; i<mid; ++i){
        left[i] = arr[i];
    }
    for(int j=mid; j<n; ++j){
        right[j-mid] = arr[j];
    }
    merge_sort(left,mid);
    merge_sort(right,n-mid);
    mergetwosortedlist(arr,left,right,mid,n-mid);
}


int digitsum_untilreached_a_single_digit(int n){
    if(n==0) return n;
    return (n%9==0? 9: n%9);
}

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(a%b,b);
}


// powerset use to find all the subset or subsequences of array
// ex -[1,2,3] - [], [1], [1,2], [2], [1,3], [2,3] , [1,2,3], [3] i.e 2^n
// time complexity - O(2^N*N)

void powerset(int arr[], int n){
    for(int i=0; i<(1<<n); ++i){  // going to 2^N;
        for(int j=0; j<n; ++j){
            if(i&(1<<j)) cout<<arr[j]<<" "; // check whether the jth bit is set in i or not
        }
        cout<<"\n";
    }
}



int vis[1e5+9];


void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; ++i){
        cin>>a[i];
    }
    int k;
    cin>>k;
    for(int i=0; i<k; ++i){
        int x;
        cin>>x;
        vis[x]=1;
    }
    for(int i=0; i<n; ++i){
        if(vis[a[i]]==0) cout<<a[i]<<" ";
    }
    cout<<"\n";
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

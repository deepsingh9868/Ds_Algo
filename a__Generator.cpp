#include <bits/stdc++.h>
using namespace std;
//to run generator press 
//go to original file 
//control +shift + p
//make stress

int main(){
	srand(time(0));
	int t = 10;
	cout<<t<<"\n";
	for(int i=0; i<t; ++i){
		// int n = rand()%1000;
		// int k = rand()%1000;
		// cout<<n<<" ";
		// if(k<n) cout<<k<<"\n";
		int xk=rand()%10+1,yk=rand()%10+1,x1=rand()%10+1,y1=rand()%10+1,x2=rand()%10+1,y2=rand()%10+1;
	    bool flag = (xk!=x1 or xk!=x2 or yk!=y1 or yk!=2);

		if(xk<=8 and yk<=8 and x1<=8 and y1<=8 and x2<=8 and y2<=8 and flag==true){
			cout<<xk<<" "<<yk<<"\n";
			cout<<x1<<" "<<y1<<"\n";
			cout<<x2<<" "<<y2<<"\n";
		}
		cout<<"\n";
	}
	cout<<"\n";
}






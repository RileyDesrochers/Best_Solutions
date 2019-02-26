/*
Written by: Riley Desrochers
problem statement:https://acpc18.kattis.com/problems/trimmingpolygons
*/
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
//input storage 
int x[401],y[401],c[401]; 
//DP array
long long F[401][401];

//calculate the area of a triangle represented by three points 
long long calcTri(int a,int n,int b){
    pair<ll,ll> l[2];
    l[0]=make_pair(x[a]-x[n],y[a]-y[n]);
    l[1]=make_pair(x[a]-x[b],y[a]-y[b]);
    return abs(l[0].first*l[1].second-l[0].second*l[1].first);
}

//DP function
long long f(int a,int b){
    if(b-a==1)//base case
        return 0;
    long long tmp=0;
    
    if(F[a][b]==-1){//if input has been calculated, calculate and save to DP table
        for(int n=a+1;n<b;n++){//check if the optimal answer sells all the nodes between two points
            tmp+=c[n];
        }
        for(int n=a+1;n<b;n++){//check if the optimal answer does not sell each node using DP
            tmp=max(tmp,f(a,n)+f(n,b)+calcTri(a,n,b));
        }
        F[a][b]=tmp;
    }
    return F[a][b];
}

int main() {
   ios_base::sync_with_stdio(false);//speed up IO by turning off non-command line IO streams
   int n; cin>>n;
   FR(i,n){cin>>x[i]>>y[i]>>c[i];}//input x and y coordinates and sell value for each point
   FR(i,401){fill(F[i],F[i]+401,-1);}//fill DP table with -1 for unsolved 
   copy(x,x+n,x+n);//copy each input the rewrite them to the same array so the data loops over itself 
   copy(y,y+n,y+n);
   copy(c,c+n,c+n);
   long long total=0;
   FR(i,n){//check if the answer is to sell all the nodes 
       total+=c[i];
   }
   FR(i,n){//choose 2 the check if those 2 points are in the answer
       for(int m=i+1;m<n;m++){
           total=max(f(i,m)+f(m,i+n),total);
       }
   }
   cout<<total<<endl;
}

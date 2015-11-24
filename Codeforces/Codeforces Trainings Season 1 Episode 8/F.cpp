#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=20;

int a[maxn],n;

bool check1(){
    int d;
    bool found=0;
    FOR(i,1,n-1) if(a[i]!=0 && a[i+1]%a[i]==0){
        found=1;
        d=a[i+1]/a[i];   
        break;
    }
    if(!found) return 0;
    FOR(i,1,n-1) if(a[i]*d!=a[i+1]) return 0;
    printf("%d\n",a[n]*d);
    //cout<<"Case 1"<<endl;
    return 1;
}

bool check2(){
    int a1=a[1], b1=a[2], c1=-a[3];
    int a2=a[2], b2=a[3], c2=-a[4];   
    int d=a1*b2-a2*b1;
    if(d==0) return 0;
    int dx=b1*c2-b2*c1;
    int dy=c1*a2-c2*a1;
    int X=dx/d, Y=dy/d;
    FOR(i,3,n) if(a[i-2]*X+a[i-1]*Y!=a[i]) return 0;
    printf("%d\n",a[n-1]*X+a[n]*Y);
    //cout<<"Case 2"<<endl;
    return 1;
}

double arr[5][5],x[5];
int ans[5];

void solve(){
    FOR(i,1,2){
        if(arr[i][i]==0){
            FOR(j,i+1,3) if(arr[j][i]!=0){
                FOR(k,1,4) swap(arr[i][k],arr[j][k]);   
            }   
        }
        FOR(j,i+1,3) if(arr[j][i]!=0){
            double d=arr[j][i]/arr[i][i];         
            FOR(k,i,4) arr[j][k]-=arr[i][k]*d;
        }
    }
    FORD(i,3,1){
        double val=0;
        FOR(k,i+1,3) val+=x[k]*arr[i][k]; 
        x[i]=(arr[i][4]-val)/arr[i][i];
        ans[i]=int(floor(x[i]+1e-9));
    }
}

bool check3(){
    FOR(i,1,3)
        FOR(j,1,4) arr[i][j]=a[i+j-1];   
    solve();
    printf("%d\n",ans[1]*a[n-2]+ans[2]*a[n-1]+ans[3]*a[n]);
    //cout<<"Case 3"<<endl;
    return 1;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    int T;
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d",&n);   
        FOR(i,1,n) scanf("%d",&a[i]);
        if(!check1()) if(!check2()) check3();
    }   
    
}

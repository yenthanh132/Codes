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
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=100007;

int n;
int a[maxn],b[maxn];
ll f[maxn],s[maxn];

ll cal(int i, int j){
    return f[j] + 1ll*b[j]*a[i];   
}

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    scanf("%d",&n);   
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) scanf("%d",&b[i]);
    s[0]=0;
    FOR(i,1,n) s[i]=s[i-1]+a[i]; 
    
    f[1]=0;
    int left,right,mid;
    FOR(i,2,n){
        f[i]=oo;
        FORD(j,i-1,1) f[i]=min(f[i],cal(i,j));
        left=1; right=i-1;
        /*while(left<=right){
            mid=(left+right)/2;
            f[i]=min(f[i],cal(i,mid));
            if(mid>left && cal(i,mid-1)<=cal(i,mid)) right=mid-1; else left=mid+1;
        }*/
        
    }
    cout<<f[n]<<endl;
    
    getch();
    return 0;
}

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

const int maxn=1007;

int n,a[maxn],p[15],q[15][15],m,f[maxn],b[maxn],t[maxn];
pii move[5],res[5];
int K=-1;

bool check(int i){
    if(K!=-1) return 1;
    
    FOR(i,1,n) t[i]=a[i];
    FOR(j,1,i){
        int l=move[j].fi, r=move[j].se;
        int len=r-l+1;
        FOR(x,l,r) b[x]=t[r+l-x];
        FOR(x,l,r) t[x]=b[x];        
    }
    FOR(i,1,n) if(t[i]!=i) return 0;
    K=i;
    FOR(j,1,K) res[j]=move[j];
    return 1;
}

void duyet(int i){
    if(K!=-1 || check(i-1)) return;
    if(i==4) return;
    FOR(x,1,m-1) FOR(y,x+1,m){
        if(p[x]+1<p[y]){
            FOR(j,1,m) q[i][j]=p[j];
            move[i]=pii(p[x]+1,p[y]);
            FOR(z,x+1,y-1) p[z]=q[i][x]+q[i][y]-q[i][z];
            sort(p+1,p+m+1);
            duyet(i+1);
            FOR(j,1,m) p[j]=q[i][j];
        }
    }
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    
    m=0;
    f[1]=0;
    FOR(i,2,n){
        if(abs(a[i]-a[i-1])>1){
            p[++m]=i-1;
            f[i]=0;
        }
        else{
            if(a[i]>a[i-1]) f[i]=1; else f[i]=-1;
            if(f[i]*f[i-1]<0){
                p[++m]=i-1;
                f[i]=0;
            }                      
        }
    }
    p[++m]=0; p[++m]=n;
    sort(p+1,p+m+1);
    int mm=m;
    FOR(i,1,m-1) if(p[i]+2==p[i+1]) p[++mm]=p[i]+1;
    m=mm;
    sort(p+1,p+m+1);
    duyet(1);
    cout<<K<<endl;
    FORD(i,K,1) cout<<res[i].fi<<' '<<res[i].se<<endl;
    
    //getch();
    return 0;
}

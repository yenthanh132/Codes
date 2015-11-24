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

const int maxn=100007;
const int maxk=17;

int a[maxn][maxk],n,m;
int BIT[maxk][maxn];
ll res;

void update(int *BIT, int p, int v){
    for(int i=p; i<=n; i+=i&(-i)) BIT[i]+=v;
}

int get(int *BIT, int p){
    int v=0;
    for(int i=p; i; i-=i&(-i)) v+=BIT[i];
    return v;   
}

int toLeft(int *BIT, int p){
    int s=p-get(BIT,p),s2;   
    int l=0, r=p, mid, res=p;
    while(l<=r){
        mid=(l+r)/2;
        s2=mid-get(BIT,mid);
        if(s2==s){
            res=mid;
            r=mid-1;     
        }else l=mid+1;
    }
    return res;
}

int toRight(int *BIT, int p){
    int s=p-get(BIT,p),s2;   
    int l=p, r=n, mid, res=p;
    while(l<=r){
        mid=(l+r)/2;
        s2=mid-get(BIT,mid);
        if(s2==s){
            res=mid;
            l=mid+1; 
        }else r=mid-1;
    }
    return res; 
}


int getBIT(int x, int y){
    return get(BIT[x],y)-get(BIT[x],y-1);   
}

void outputBIT(){
    REP(j,2){
        FOR(i,1,n) cout<<getBIT(j,i)<<' ';
        cout<<endl;   
    }
    cout<<"_______"<<endl;
}

int main(){
    scanf("%d%d",&n,&m);
    int p,v;
    reset(BIT,0);
    FOR(i,1,n){
        scanf("%d",&v);
        REP(j,maxk){
            a[i][j]=(v>>j)&1;
            if(a[i][j]) update(BIT[j],i,1);
        }
    }
    res=0;
    REP(b,maxk){
        int i=1; 
        while(i<=n){
            while(i<=n && a[i][b]==0) ++i;
            if(i>n) break;
            int j=i;
            while(j<n && a[j+1][b]==1) ++j;
            res+=1LL*(j-i+1)*(j-i+2)/2*(1<<b);     
            i=j+1;
        }   
    }
    
    REP(q,m){
        scanf("%d%d",&p,&v);
        int mul=1;
        REP(j,maxk){
            int x=(v>>j)&1;
            if(a[p][j]!=x){
                int cl=0,cr=0;
                if(p>1 && a[p-1][j]==1)
                    cl=p-toLeft(BIT[j],p-1)-1;
                if(p<n && a[p+1][j]==1)
                    cr=toRight(BIT[j],p+1)-p;
                    
                if(x==1){
                    res-=1LL*cl*(cl+1)/2*mul; 
                    res-=1LL*cr*(cr+1)/2*mul;
                    res+=1LL*(cl+cr+1)*(cl+cr+2)/2*mul;
                    update(BIT[j],p,1);
                }else{
                    res+=1LL*cl*(cl+1)/2*mul; 
                    res+=1LL*cr*(cr+1)/2*mul;
                    res-=1LL*(cl+cr+1)*(cl+cr+2)/2*mul;
                    update(BIT[j],p,-1);
                }
                
                a[p][j]=x;
            }
            mul<<=1;
        }  
        printf("%I64d\n",res);
    }
    
    return 0;
}

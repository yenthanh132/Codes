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

const int maxn=200007;

#include <conio.h>

int a[maxn],n;
ll val[maxn][2];
bool free1[maxn][2],indfs[maxn][2];
int infor[maxn][2];

ll get(int v, int t){
    if(v<=1 || v>n) return 0;
    if(!free1[v][t]) return val[v][t];
    free1[v][t]=0;
    indfs[v][t]=1;
    int vt;
    if(t==0){
        vt=v-a[v];
        if(vt>=1){
            if(free1[vt][1^t] || ((!free1[vt][1^t]) && (!indfs[vt][1^t]))){
                infor[v][t]=0;
                val[v][t]=a[v]+get(vt,1^t);
                if(infor[vt][1^t]!=0) infor[v][t]=infor[vt][1^t];
                else if(vt==1) infor[v][t]=1;
            }else if(indfs[vt][1^t]){
                infor[v][t]=-1;
                val[v][t]=0;
            }

        }else{
            infor[v][t]=0;
            val[v][t]=a[v];
        }
    }else{
        vt=v+a[v];
        if(vt<=n){
            if(free1[vt][1^t] || ((!free1[vt][1^t]) && (!indfs[vt][1^t]))){
                infor[v][t]=0;
                val[v][t]=a[v]+get(vt,1^t);
                if(infor[vt][1^t]!=0) infor[v][t]=infor[vt][1^t];
            }else if(indfs[vt][1^t]){
                infor[v][t]=-1;
                val[v][t]=0;
            }
        }else{
            infor[v][t]=0;
            val[v][t]=a[v];
        }
    }
    indfs[v][t]=0;
    return val[v][t];
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,2,n) scanf("%d",&a[i]);
    reset(free1,1);
    reset(indfs,0);
    reset(infor,0);
    ll res;
    int t;
    FOR(i,1,n-1){
        res=get(1+i,0);
        if(infor[1+i][0]!=0) puts("-1");
        else if(infor[1+i][0]==0)
            printf("%I64d\n",res+i);
    }
    
    //getch();
    return 0;
}
            
    

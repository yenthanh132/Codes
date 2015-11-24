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

const int maxn=300007;

int n,a[maxn],BIT[maxn],x,y,pos[maxn],q,val[maxn];

void update(int i, int v){
    for(int j=i; j<n; j+=j&(-j)) BIT[j]+=v;   
}

int get(int i){
    int res=0;
    for(int j=i; j; j-=j&(-j)) res+=BIT[j];
    return res;
}

int get(int i, int j){
    return get(j-1)-get(i-1);
}

void update(int v){
    if(v>1 && pos[v]<pos[v-1] && val[v-1]==0){
        val[v-1]=1;
        update(v-1,1);
    }
    if(v>1 && pos[v]>pos[v-1] && val[v-1]==1){
        val[v-1]=0;
        update(v-1,-1);
    }
    if(v<n && pos[v]>pos[v+1] && val[v]==0){
        val[v]=1;
        update(v,1);
    }
    if(v<n && pos[v]<pos[v+1] && val[v]==1){
        val[v]=0;
        update(v,-1);
    }
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);   
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]), pos[a[i]]=i;
    reset(BIT,0);
    FOR(i,1,n){
        update(i);
    }
    scanf("%d",&q);
    int x,y,t;
    REP(i,q){
        scanf("%d%d%d",&t,&x,&y);
        if(t==1)
            printf("%d\n",get(x,y)+1);
        else{
            
            swap(a[x],a[y]);
            pos[a[x]]=x;
            pos[a[y]]=y;
            update(a[x]);
            update(a[y]);
            
        }
    }
    //getch();
    return 0;
}

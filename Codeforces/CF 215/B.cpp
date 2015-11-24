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

int a[maxn],b[maxn],n,m,p;
int mark[maxn],cnt;
map<int,int> mm;

void add(int v){
    if(mark[v]==0) cnt++;
    if(mark[v]==-1) cnt--;
    mark[v]++;
}

void del(int v){
    if(mark[v]==1) cnt--;   
    if(mark[v]==0) cnt++;
    mark[v]--;    
}

vector<int> list;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    scanf("%d%d%d",&m,&n,&p);
    mm.clear();
    int num=0;
    FOR(i,1,m){
        scanf("%d",&a[i]);
        if(mm.count(a[i])==0) mm[a[i]]=++num;
        a[i]=mm[a[i]];
    }
    FOR(i,1,n){
        scanf("%d",&b[i]);
        if(mm.count(b[i])==0) mm[b[i]]=++num;
        b[i]=mm[b[i]];
    }
    
    reset(mark,0);
    cnt=0;
    FOR(i,1,n) add(b[i]);
    FOR(i,1,p){
        ll left=i-1ll*(n+1)*p;
        for(int q=i; q<=m; q+=p){
            left+=p;
            if(left>=1) add(a[left]);
            del(a[q]);
            if(cnt==0) list.pb(int(left+p));
        }  
        int pos=int(max(left+p,1ll*i));
        while(pos<=m){
            add(a[pos]);
            pos+=p;
        }
    }
    sort(list.begin(),list.end());
    printf("%d\n",sz(list));
    REP(i,sz(list)) printf("%d ",list[i]);
    return 0;
}   

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

const int maxn = 100005;

ll IT[maxn*4][5];
int sum[maxn*4],n,m,a[maxn];
vector<pii> query;

void updateIT(int i, int l, int r, int pos){
    if(pos<l || pos>r) return;
    if(l==r){
        if(sum[i]) sum[i]=IT[i][0]=0;
        else sum[i]=1, IT[i][0]=a[pos];
        return;
    }
    int mid=(l+r)/2;
    updateIT(i*2,l,mid,pos);
    updateIT(i*2+1,mid+1,r,pos);
    sum[i]=(sum[i*2]+sum[i*2+1])%5;
    REP(k,5) IT[i][k]=IT[i*2][k]+IT[i*2+1][(k-sum[i*2]+5)%5];
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    char s[5];
    int v;
    scanf("%d",&n); m=0;
    REP(i,n){
        scanf("%s",&s);
        if(s[0]=='s') query.pb(pii(0,0));
        else{
            scanf("%d\n",&v);  
            query.pb(pii(1,v));
            a[++m]=v;
        }
    }
    sort(a+1,a+m+1);
    int *it=unique(a+1,a+m+1);
    m=it-(a+1);
    REP(i,n) if(query[i].fi){
        v=lower_bound(a+1,a+m+1,query[i].se)-(a);
        updateIT(1,1,m,v);
    }else printf("%I64d\n",IT[1][2]);
    //getch();
    return 0;
}

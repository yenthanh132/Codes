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

const int maxv=100017;
const int maxn=507;

bool isprime[maxv+1];
int list[maxv],cnt,a[maxn][maxn],s[maxn][maxn],res,m,n;

void init(){
    for(int i=3; i<=maxv; i+=2) isprime[i]=1;
    isprime[2]=1;
    for(int i=3; i*i<=maxv; i+=2) if(isprime[i])
        for(int j=i*i; j<=maxv; j+=i*2) isprime[j]=0;
    list[cnt=1]=2;
    for(int i=3; i<=maxv; i+=2) if(isprime[i]) list[++cnt]=i;
}

int find(int v){
    int l, r, mid, res;
    l=1; r=cnt;
    while(l<=r){
        mid=(l+r)/2;
        if(list[mid]>=v){
            res=list[mid];
            r=mid-1;
        }else l=mid+1;
    }
    return res;
}

#include <conio.h>
int main(){
    init();
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&m,&n);
    int v;
    FOR(i,1,m) FOR(j,1,n){
        scanf("%d",&v);
        a[i][j]=find(v)-v;
    }
    res=oo;
    FOR(i,1,m) FOR(j,1,n) s[i][j]=s[i-1][j]+a[i][j];
    FOR(i,1,n) res=min(res,s[m][i]);
    FOR(i,1,m) FOR(j,1,n) s[i][j]=s[i][j-1]+a[i][j];
    FOR(i,1,m) res=min(res,s[i][n]);
    
    printf("%d\n",res);
    //getch();
    return 0;
}

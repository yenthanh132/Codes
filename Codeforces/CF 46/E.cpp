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

const int maxn=51;
const int maxk=26;

int m,n,a[2][maxn],ck,f[2][maxn][maxn][maxk],g[maxn][maxn];

vector<pii> trans[maxk];
char buf[maxn];

bool can_trans(int id, int l, int r, int k){
    if(l>r) return 0;
    if(l==r) return (k==a[id][l]);
    if(f[id][l][r][k]!=-1) return f[id][l][r][k];
    int &res=f[id][l][r][k];
    res=0;
    REP(i,sz(trans[k]))
        FOR(j,l,r-1) if(can_trans(id,l,j,trans[k][i].fi) && can_trans(id,j+1,r,trans[k][i].se)){
            res=1;
            return 1;
        }   
    return 0;
}

int dp(int m, int n){
    if(m==0 && n==0) return 0;
    if(g[m][n]!=-1) return g[m][n];
    int &res=g[m][n];
    res=oo;    
    REP(k,26) REP(i,m) REP(j,n)
        if(can_trans(0,m-i,m,k) && can_trans(1,n-j,n,k))            
            res=min(res,dp(m-i-1,n-j-1)+1);                    
    return res;   
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%s",buf+1);
    m=strlen(buf+1);
    FOR(i,1,m) a[0][i]=buf[i]-'a';
    scanf("%s",buf+1);
    n=strlen(buf+1);
    FOR(i,1,n) a[1][i]=buf[i]-'a';
    
    scanf("%d\n",&ck);
    char x,y,z;
    REP(i,ck){
        scanf(" %c -> %c %c ",&x,&y,&z);
        trans[x-'a'].pb(pii(y-'a',z-'a'));
    }
    
    reset(f,-1); reset(g,-1);
    int res=dp(m,n);
    if(res<oo) cout<<res<<endl;
    else cout<<-1<<endl;
    
    //getch();
    return 0;
}

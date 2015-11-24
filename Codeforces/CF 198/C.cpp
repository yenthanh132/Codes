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

const int maxn=2007;

ll f[maxn],C[maxn][maxn];
int n,a[maxn],x,y;
bool mark[maxn];

bool go(int v){
    if(a[v]==-1) return 1;
    else if(mark[v]==0) return 0;
    mark[v]=0;
    return go(a[v]);
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    f[1]=0; f[2]=1; f[0]=1;
    FOR(i,3,n){
        f[i]=(i-1)*(f[i-1]+f[i-2]);
        f[i]%=oo;
    }
    
    x=y=0;
    FOR(i,1,n) if(a[i]==-1) x++;
    
    reset(mark,1);
    FOR(i,1,n) if(a[i]!=-1 && mark[i]) if(go(i)){
        x--;
        y++;
    }
    
    reset(C,0);
    C[0][0]=1;
    FOR(i,1,y){
        C[i][0]=1;
        FOR(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%oo;
    }
    
    ll res=0;
    FOR(i,0,y) res = (res + f[x+i]*C[y][i])%oo;
    cout<<res<<endl;
    /*
    int p[10];
    FOR(i,1,n) p[i]=i;
    int cnt=0;
    do{
        bool ok=1;
        FOR(j,1,n) if(p[j]==j) ok=0;
        FOR(j,1,n) if(a[j]!=-1 && p[j]!=a[j]) ok=0;
        if(ok){
            FOR(j,1,n) cout<<p[j]<<' ';
            cout<<endl;
            cnt++;
        }
    }while(next_permutation(p+1,p+n+1));
    cout<<"Total: "<<cnt<<endl;
    */
    //getch();
    return 0;
}

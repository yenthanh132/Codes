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

const int maxn=6007;

ll a[maxn][maxn];
int pri[maxn*2],val[maxn*2],id[maxn*2];
int n,p;

bool cmp(const int &a, const int &b){
    return pri[a]<pri[b];
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&p);
    FOR(i,1,n*2) pri[i]=val[i]=0;

    char buf[10];
    FOR(i,1,p){
        int pos,v;
        scanf("%s%d%d",&buf,&pos,&v);
        if(buf[0]=='C') pos+=n;
        pri[pos]=i;
        val[pos]=v;
    }
    FOR(i,1,n*2) id[i]=i;
    sort(id+1,id+n*2+1,cmp);
    FOR(i,1,n*2){
        int j=id[i];
        if(j<=n){
            int v=val[j];
            FOR(y,1,n) a[j][y]=v;
        }else{
            int v=val[j];
            j-=n;
            FOR(x,1,n) a[x][j]=v;
        }
    }
    ll res=0;
    FOR(x,1,n) FOR(y,1,n) res+=a[x][y];

    cout<<res<<endl;

    return 0;
}

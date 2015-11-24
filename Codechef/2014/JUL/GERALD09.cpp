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

const ll base=73471;
const ll base2=10007;
const int maxn=20;
const char key[4]={'A','C','G','T'};

int a[maxn][maxn],m,n,T,k,best,res[maxn][maxn];
ll val[maxn][maxn],pw[maxn], val2[maxn][maxn], pw2[maxn];
vector<ll> L;

int cal(){
    int c=0;
    FOR(i,1,m) FOR(j,1,n) val[i][j]=val[i][j-1]*base+a[i][j];
    int res=0;
    FOR(h,1,m) FOR(w,1,n){
        L.clear();
        FOR(j,1,n-w+1) FOR(i,1,m){
            val2[i][j]=val2[i-1][j]*base2 + (val[i][j+w-1]-val[i][j-1]*pw[w]);
            ++c;
            if(i>=h) L.pb(val2[i][j]-val2[i-h][j]*pw2[h]);
        }
        sort(L.begin(),L.end());
        res+=unique(L.begin(),L.end())-L.begin();
    }
    //cout<<c<<endl;
    return res;
}

int main(){
    //freopen("input.txt","r",stdin);
    pw[0]=pw2[0]=1;
    FOR(i,1,15) pw[i]=pw[i-1]*base, pw2[i]=pw2[i-1]*base2;

    scanf("%d",&T);
    REP(tt,T){
        scanf("%d%d%d",&m,&n,&k);
        FOR(i,1,m) FOR(j,1,n) a[i][j]=res[i][j]=1;
        best=m*n;
        REP(r,7){
            int i=rand()%m+1, j=rand()%n+1;
            int vt=-1;
            int old=a[i][j];
                FOR(v,1,3) if(v!=old){
                    a[i][j]=v;
                    int kval=cal();
                    if(abs(kval-k)<abs(best-k)){
                        best=kval;
                        vt=v;
                        FOR(i,1,m) FOR(j,1,n) res[i][j]=a[i][j];
                    }
                }
            if(vt!=-1) a[i][j]=vt; else a[i][j]=old;

        }

        FOR(i,1,m){
            FOR(j,1,n) printf("%c",key[res[i][j]-1]);
            puts("");
        }
        //cout<<best<<' '<<k<<endl;

    }
}

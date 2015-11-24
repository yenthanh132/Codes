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

const int maxn=107;
const int maxm=10007;

int n,m,p[maxm];
vector<int> a[maxn];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int T,c,v,res;
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d%d",&n,&m);
        FOR(i,1,m) scanf("%d",&p[i]);
        REP(i,n){
            scanf("%d",&c);
            a[i].resize(c,0);
            REP(j,c) scanf("%d",&a[i][j]);
            sort(a[i].begin(),a[i].end());
        }
        res=0;
        FOR(i,1,m) if(!a[p[i]].empty()){
            res+=a[p[i]].back();
            a[p[i]].pop_back();
        }
        printf("%d\n",res);
    }
    //getch();   
    return 0;
}
        

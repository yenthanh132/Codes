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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1007;
int n,a[maxn],BIT[maxn][maxn],save[maxn][maxn],f[maxn][2];
pii list[maxn];

void update(int i, int v){
    int vv=v;
    while(i<=n){
        v=vv;
        while(v<=n){
            BIT[i][v]++;
            v+=v & (-v);
        }
        i+=i & (-i);
    }
}

int get(int i, int v){
    if(save[i][v]!=-1) return save[i][v];
    int res=0,vv=v;
    while(i>0){
        v=vv;
        while(v>0){
            res+=BIT[i][v];
            v&=v-1;
        }
        i&=i-1;
    }
    save[i][v]=res;
    return res;
}

int getval(int x, int y){
    return(x-get(x,y));
}

void optimize(){
    reset(BIT,0);
    FOR(i,1,1000) FOR(j,1,1000) save[i][j]=-1;
    FOR(i,1,n) update(i,a[i]);
    f[0][0]=f[0][1]=0;
    f[1][0]=f[1][1]=0;
    int t;
    FOR(i,2,n){
        t=getval(i-1,a[i]); 
        f[i][0]=f[i-1][0]+t;
        f[i][1]=f[i-1][1]+t;
        FOR(j,1,i-1) if(a[j]>a[i])
            f[i][1]=min(f[i][1],f[i][0] - t + getval(j-1,a[i]) - (f[j][0]-f[j-1][0]) + getval(i-1,a[j])
                        + (getval(i-1,a[j]-1) - getval(i-1,a[i]-1))
                        - (getval(j,a[j]-1) - getval(j,a[i]-1)));
    }
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    
    optimize();
    printf("%d\n",min(f[n][0],f[n][1]));
    //getch();
    return 0;
}

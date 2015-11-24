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
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;
const int maxk=507;

int a[maxn],b[maxn],m,n,s,e,k,f[maxn][maxk];
int res;
vector<int> val[maxn];

int findnext(int i, int v){
    if(val[v].empty()) return -1;
    vector<int>::iterator it = lower_bound(val[v].begin(), val[v].end(), i+1);
    if(it==val[v].end()) return -1;
    return *it;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d%d",&m,&n,&s,&e);
    k=s/e;
    res=0;

    for(int i=1; i<=m; ++i) scanf("%d",&a[i]);
    for(int i=1; i<=n; ++i) scanf("%d",&b[i]), val[b[i]].pb(i);
    f[0][1]=oo;
    for(int i=1; i<=n; ++i){
        f[i][1]=f[i-1][1];
        int p=findnext(0,a[i]);
        if(p!=-1) f[i][1]=min(f[i][1],p);
        if(i+f[i][1]+e<=s) res=1;
    }
    for(int j=2; j<=k; ++j){
        f[0][j]=oo;
        for(int i=1; i<=m; ++i) if(i+j*e<=s){
            f[i][j]=f[i-1][j];
            if(f[i-1][j-1]!=oo){
                int p=findnext(f[i-1][j-1],a[i]);
                if(p!=-1) f[i][j]=min(f[i][j],p);
            }
            if(i+f[i][j]+j*e<=s) res=j;
        }
    }

    printf("%d\n",res);

    return 0;
}

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

const int maxn=407;

int pos[maxn],a[maxn],Next[maxn][maxn],id[maxn],n,m;

int main(){
    //freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        scanf("%d%d",&n,&m);
        for(int i=1; i<=m; ++i) scanf("%d",&a[i]);
        reset(pos,-1);
        for(int i=m; i>=1; --i){
            for(int j=1; j<=400; ++j) if(pos[j]==-1) Next[i][j]=m+1; else Next[i][j]=pos[j];
            pos[a[i]] = i;
        }
        for(int j=1; j<=n; ++j) id[j]=-1;
        int res = 0;
        for(int i=1; i<=m; ++i){
            int best, p = -1;
            for(int j=1; j<=n; ++j) if(id[j]==-1 || id[j]==a[i]){
                p=j;
                break;
            }else if(p==-1 || best < Next[i][id[j]]){
                p=j;
                best = Next[i][id[j]];
            }
            ++res;
            if(id[p]==a[i]) --res;
            id[p]=a[i];
        }

        printf("%d\n",res);
    }
}

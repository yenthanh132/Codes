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

const int maxn=2007;

char a[maxn][maxn];
bool free1[maxn];
int n;
vector<int> e[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%s",a[i]+1);
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(a[i][j]=='1'){
        e[i].pb(j);
    }

    int res=0;
    for(int i=1; i<=n; ++i){
        int c=1;
        reset(free1,1);
        free1[i]=0;
        for(int j=0; j<sz(e[i]); ++j){
            int v=e[i][j];
            if(free1[v]) ++c;
            free1[v]=0;
            for(int j2=0; j2<sz(e[v]) && c<n; ++j2){
                int w=e[v][j2];
                if(free1[w]) ++c;
                free1[w]=0;
            }
        }
        res+=c-1-sz(e[i]);
    }
    cout<<res<<endl;
}

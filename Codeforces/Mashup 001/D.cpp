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
const int maxv=100000;
int n;
vector<int> a[maxn];

bool exist(int x, int y){
    int l=0, r=sz(a[x])-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[x][mid]==y) return 1;
        if(a[x][mid]<y) l=mid+1;
        else r=mid-1;
    }
    return 0;
}

int main(){
    //freopen("input.txt","r",stdin);
    int x,y;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i){
        scanf("%d%d",&x,&y);
        a[x].pb(y);
    }

    int res=0;
    for(int x=0; x<=maxv; ++x){
        sort(a[x].begin(), a[x].end());
        int m=sz(a[x]);
        if(m<=300){
            for(int i=0; i<m; ++i) for(int j=i+1; j<m; ++j){
                int len=a[x][j]-a[x][i];
                if(len>x) break;
                if(exist(x-len,a[x][i]) && exist(x-len,a[x][j])){
                    ++res;
                }
            }
        }else{
            for(int x0=0; x0<x; ++x0){
                m=sz(a[x0]);
                for(int i=0; i<m; ++i){
                    int len=x-x0;
                    int y0=a[x0][i];
                    if(exist(x,y0) && exist(x,y0+len) && exist(x0,y0+len)) ++res;
                }
            }
        }
    }

    printf("%d\n",res);

    return 0;
}

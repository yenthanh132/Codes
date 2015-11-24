#include <iostream>
#include <algorithm>
#include <cstdio>
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
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
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
typedef pair<pii,int> iii;

#define maxn 1007

int x[maxn],a[maxn],deg[maxn],n;
bool res;

void solve(){
    queue<int> myqueue;
    int i,j,c=0;
    for(i=1;i<=n;i++) if(deg[i]==0) myqueue.push(i);
    while (!myqueue.empty()){
        c++;
        while(!myqueue.empty()){
            a[myqueue.front()]=c;
            deg[myqueue.front()]=-1;
            if (x[myqueue.front()]) deg[x[myqueue.front()]]--;
            myqueue.pop();
        }
        for(i=1;i<=n;i++) if(deg[i]==0) myqueue.push(i);
    }
    res=true;
    for(i=1;i<n;i++){
        for(j=i+1;j<x[i];j++) if((a[j]-a[i])*(x[i]-i)>=(a[x[i]]-a[i])*(j-i)){
            res=false;
            return;
        }
        for(j=x[i]+1;j<=n;j++) if((a[j]-a[i])*(x[i]-i)>(a[x[i]]-a[i])*(j-i)){
            res=false;
            return;
        }
    }
}
    
int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int test,index,i;
    scanf("%d",&test);
    for(index=1;index<=test;index++){
        scanf("%d",&n);
        reset(deg,0);
        x[n]=0;
        for(i=1;i<n;i++){
            scanf("%d",x+i);
            deg[x[i]]++;
        }
        solve();
        printf("Case #%d: ",index);
        if(res){
            for(i=1;i<n;i++) printf("%d ",a[i]); printf("%d\n",a[n]);
        }else printf("Impossible\n");
    }
    return 0;
}
            

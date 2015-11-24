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

#define maxn 10007
int n,l[maxn],d[maxn],D;
bool res;

void solve(){
    priority_queue<pii,vector<pii>,greater<pii> > heap;
    int i,j;
    heap.push(pii(0,min(d[0],l[0])*2));
    for(i=1;i<n;i++){
        while(!heap.empty() && heap.top().se<d[i]) heap.pop();
        if (heap.empty()){
            res=false;
            return;
        }
        j=heap.top().fi;
        heap.push(pii(i,min(d[i]-d[j],l[i])+d[i]));
    }
    while(!heap.empty() && heap.top().se<D) heap.pop();
    res=(!heap.empty());
}
int main(){
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int test,i,index;
    scanf("%d",&test);
    for(index=0;index<test;index++){
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d%d",d+i,l+i);
        scanf("%d",&D);
        solve();
        printf("Case #%d: ",index+1);
        if (res) printf("YES\n"); else printf("NO\n");
    } 
    return 0;
}

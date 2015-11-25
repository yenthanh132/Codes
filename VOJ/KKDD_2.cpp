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

int heap_min[maxn],heap_max[maxn],n,k,a[maxn],n_min,n_max;
ll sum_min,sum_max,f[maxn];

void add_min(int v){
    heap_min[++n_min]=v;
    int child=n_min, parent=child/2;
    while(parent>0 && heap_min[parent]>v){
        heap_min[child]=heap_min[parent];
        child=parent; parent=child/2;
    }
    heap_min[child]=v;
    sum_min+=v;
}

int pop_min(){
    int res=heap_min[1], v=heap_min[n_min--], r=1,c;
    while(r*2<=n_min){
        c=r*2;
        if(c<n_min && heap_min[c+1]<heap_min[c]) c++;
        if(v<=heap_min[c]) break;
        heap_min[r]=heap_min[c];
        r=c;
    }
    heap_min[r]=v;
    sum_min-=res;
    return res;
}

void add_max(int v){
    heap_max[++n_max]=v;
    int child=n_max, parent=child/2;
    while(parent>0 && heap_max[parent]<v){
        heap_max[child]=heap_max[parent];
        child=parent; parent=child/2;
    }
    heap_max[child]=v;
    sum_max+=v;
}

int pop_max(){
    int res=heap_max[1], v=heap_max[n_max--], r=1, c;
    while(r*2<=n_max){
        c=r*2;
        if(c<n_max && heap_max[c+1]>heap_max[c]) c++;
        if(v>=heap_max[c]) break;
        heap_max[r]=heap_max[c];
        r=c;
    }
    heap_max[r]=v;
    sum_max-=res;
    return res;
}

void add(int v){
    if (n_max>0 && v>heap_max[1]) add_min(v); else add_max(v);
    while (n_max-1>n_min) add_min(pop_max());
    while (n_max<n_min) add_max(pop_min());
}

ll getvalue(){
    ll m=heap_max[1];
    return(sum_min+m*(n_max-n_min)-sum_max);
}

void optimize(){
    int i,j;
    for(i=1;i<=n;i++) f[i]=100000000000000007ll; f[0]=0;
    for(i=k;i<=n;i++){
        sum_max=sum_min=n_max=n_min=0;
        for(j=i;j>=1 && i-j+1<=2*k;j--){
            add(a[j]);
            if(i-j+1>=k) f[i]=min(f[i],f[j-1]+getvalue());
        }
    }
}
int main(){
    freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    optimize();
    printf("%lld",f[n]);
    return 0;
}

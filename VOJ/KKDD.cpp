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

int n,k,a[maxn];
ll f[maxn],sum_min,sum_max;
priority_queue<int> heap_min;
priority_queue<int,vector<int>,greater<int> > heap_max;

void add(int v){
    if (!heap_min.empty() && v>heap_min.top()){
        heap_max.push(v);
        sum_max+=v;
    }else{
        heap_min.push(v);
        sum_min+=v;
    }
        //balance
    while(sz(heap_min)-1>sz(heap_max)){
        heap_max.push(heap_min.top());
        sum_max+=heap_min.top(); sum_min-=heap_min.top();
        heap_min.pop();
    }
    while(sz(heap_min)<sz(heap_max)){
        heap_min.push(heap_max.top());
        sum_min+=heap_max.top(); sum_max-=heap_max.top();
        heap_max.pop();
    }
}

ll getvalue(){
    ll median=heap_min.top();
    return (sum_max+median*(sz(heap_min)-sz(heap_max))-sum_min);
}

void optimize(){
    int i,j;
    for(i=1;i<=n;i++)f[i]=100000000000000007ll; f[0]=0;
    for(i=k;i<=n;i++){
        heap_min=priority_queue<int>();
        heap_max=priority_queue<int,vector<int>,greater<int> >();
        sum_min=sum_max=0;
        for(j=i;j>=1 && i-j+1<=2*k;j--){
            add(a[j]);
            if(i-j+1>=k) f[i]=min(f[i],f[j-1]+getvalue());
        }
    }
}           
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    optimize();
    printf("%lld",f[n]);
    //getch();
    return 0;
}

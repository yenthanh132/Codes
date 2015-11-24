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

const int maxn=100007;

int n,a[maxn],c0,c1,d[maxn];
ll k;

int find(int v){
    int l,r,mid;
    l=1;r=n;
    while(l<=r){
        mid=(l+r)/2;
        if(a[mid]==v) return mid;
        else if(a[mid]>v) r=mid-1; else l=mid+1;
    }
    return -1;
}

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%I64d",&n,&k);
    FOR(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    c0=c1=0;
    FOR(i,1,n){
        if(d[i]==0) c0++; else c1++;
        if(a[i]*k<=a[n]){
            int pos=find(a[i]*k);
            if(pos>i) d[pos]=1^d[i];
        }
    }
    //FOR(i,1,n) cout<<d[i]<<' '; cout<<endl;
    printf("%d\n",max(c0,c1));
    return 0;
}

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

const int maxn=2007;

vector<int> list;
int n,a[maxn],res;
int BIT[maxn*2];

void update(int p, int v){
    p=p+2001;
    for(int i=p; i; i-=i&(-i)) BIT[i]+=v;
}

int get(int p){
    p=p+2001;
    int res=0;
    for(int i=p; i<=4001; i+=i&(-i)) res+=BIT[i];
    return res;
}

int cal(){
    reset(BIT,0);
    int res=0;
    FOR(i,1,n){
        res+=get(a[i]+1);
        update(a[i],1);
    }
    return res;
}

#include <conio.h>
int main(){
    //freopen("Test.txt","r",stdin);
    scanf("%d",&n);
    
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n) if(a[i]<0) a[i]=-a[i];
    FOR(i,1,n) list.pb(a[i]);
    sort(list.begin(),list.end());
    list.resize(unique(list.begin(),list.end())-list.begin());
    FOR(i,1,n) a[i]=lower_bound(list.begin(),list.end(),a[i])-list.begin();
    
    res=oo;
    FOR(i,1,n){
        a[i]=-a[i];
        res=min(res,cal());
    }
    cout<<res<<endl;
    //getch();
    return 0;
}

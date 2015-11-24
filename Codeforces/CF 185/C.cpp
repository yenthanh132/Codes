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

const int maxn=1000007;
const int maxv=1000000;
ll BIT[maxn],save[maxn];
int a[maxn],n;

void update(int p, ll v){
    for(int i=p; i<=maxv; i+=i&(-i)) BIT[i]=(BIT[i]+v)%oo;
}

ll get(int p){
    ll res=1;
    for(int i=p; i; i-=i&(-i)) res=res+BIT[i];
    return res%oo;
}


#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    ll res=0;
    FOR(i,1,n){
        ll val=get(a[i])*a[i]%oo;
        res=(res + val - save[a[i]] +oo)%oo;
        update(a[i],(val - save[a[i]] +oo)%oo);
        save[a[i]]=(val)%oo;
    }
    cout<<(res+oo)%oo<<endl;
    //getch();
    return 0;
    
}
        

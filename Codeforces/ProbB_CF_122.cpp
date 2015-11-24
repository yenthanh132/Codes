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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii,int> iii;

#define maxn 35

struct arr{ll a[maxn];} a,b,k,p ;

int n,u,r,d[maxn];
ll res=-oo;

void keepvalue(const arr& a){
    ll t=0;
    FOR(i,1,n) t+=a.a[i]*k.a[i];
    res=max(res,t);
}

arr oper1(arr& a){
    arr res;
    FOR(i,1,n) res.a[i]=a.a[i]^b.a[i];
    return res;
}

arr oper2(arr& a){
    arr res;
    FOR(i,1,n) res.a[i]=a.a[p.a[i]]+r;
    return res;
}

void duyet(int i, arr a){
    if(i>u){
        keepvalue(a);
        return;
    }
    if((u-i+1)%2==0) keepvalue(a);
    if(d[i-1]!=1){
        d[i]=1;
        duyet(i+1,oper1(a));
    }
    d[i]=0;
    duyet(i+1,oper2(a));
}   
        
//#include <conio.h>

int main(){
    //freopen("test.txt","r",stdin);
    cin>>n>>u>>r;
    FOR(i,1,n) cin>>a.a[i];
    FOR(i,1,n) cin>>b.a[i];
    FOR(i,1,n) cin>>k.a[i];
    FOR(i,1,n) cin>>p.a[i];
    d[0]=0;
    duyet(1,a);
    cout<<res<<endl;
    //getch();
    return 0;
}


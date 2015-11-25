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
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
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

#define maxn 101
#define time 1000000006

int f[maxn],n,v[maxn],cl,cr;

int val(int v){return (v>=0)?v:(v+1000);}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    FOR(i,1,n) cin>>v[i];
    sort(v+1,v+n+1);
    reset(f,0);
    cl=cr=0;
    FOR(i,1,n-1) if (f[i]==0 && v[i+1]-v[i]==1) f[i]=1, f[i+1]=2, cl++,cr++;
    FOR(i,1,n) if(f[i]==0) if(cl==cr) f[i]=1,cl++; else f[i]=2, cr++;
    ll res=0;
    FOR(i,1,n) if(f[i]==1) 
        FOR(j,1,n) if(f[j]==2)
            res=res+(1+(time-val(v[j]-v[i])*5)/5000)*2;
    cout<<res<<endl;
    //getch();
    return 0;
}
    

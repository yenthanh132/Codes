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
typedef pair<pii,int> piii;

int const maxn = 5001;

int n,w,h,trace[maxn],f[maxn];
vector<piii> a;

bool cmp(const piii &a, const piii &b){
    if(a.fi.fi<b.fi.fi) return 1; else if(a.fi.fi>b.fi.fi) return 0;
    else if(a.fi.se>b.fi.se) return 1; else return 0;
}

void optimize(){
    int v,best=0,pos=-1;
    REP(i,n){
        trace[i]=-1;
        v=((a[i].fi.fi>w && a[i].fi.se>h)?1:0);
        f[i]=0;
        REPD(j,i) if(a[i].fi.se>a[j].fi.se && f[i]<f[j]){
            f[i]=f[j];
            trace[i]=j;
        }
        f[i]+=v;
        if(best<f[i]) best=f[i], pos=i;
    }
    cout<<best<<endl;
    vector<int> list;
    while(pos!=-1){
        list.pb(a[pos].se);
        pos=trace[pos];
    }
    REPD(i,sz(list)) cout<<list[i]+1<<' ';
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n>>w>>h;
    int x,y;
    REP(i,n){
        cin>>x>>y;
        a.pb(piii(pii(x,y),i));
    }
    sort(a.begin(),a.end(),cmp);
    optimize();
    //getch();
    return 0;
}

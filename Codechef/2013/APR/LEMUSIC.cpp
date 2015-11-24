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

int n;
struct music{int b,l;} a[maxn];
ll res,sum;
set<int> mys;

bool cmp(const music &a, const music &b){return a.l<b.l;}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int T;
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d",&n);
        FOR(i,1,n) scanf("%d%d",&a[i].b,&a[i].l);   
        sort(a+1,a+n+1,cmp);
        mys.clear();
        sum=res=0;
        FOR(i,1,n)
            if(mys.find(a[i].b)==mys.end()){
                mys.insert(a[i].b);
                res+=1ll*a[i].l*sz(mys);
            }else sum+=a[i].l;
        res+=sum*sz(mys);
        cout<<res<<endl;
    }
    //getch();
    return 0;
}
    
    

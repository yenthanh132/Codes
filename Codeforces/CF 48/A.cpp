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
typedef pair<pii,pii> i4;

int n,v[4],t[4],z[4];
i4 a[1007];

int cmp(){
    REP(i,4) if(t[i]<v[i]) return -1; else if(t[i]>v[i]) return 1;
    return 0;
}
    
#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n){
        char buf[5];
        scanf("%s",buf);
        v[0]=buf[0]-'0';
        v[1]=buf[1]-'0';
        scanf("%s",buf);
        v[2]=buf[1]-'0';
        v[3]=buf[0]-'0';
        scanf("%s",buf);
        REP(j,4) z[j]=v[j];
        REP(j,4){
            REP(k,4) t[k]=z[(k+j)%4];
            if(cmp()<0) REP(k,4) v[k]=t[k];
        }
        //REP(j,4) cout<<v[j]<<' '; cout<<endl;
        a[i]=i4(pii(v[0],v[1]),pii(v[2],v[3]));
    }
    sort(a+1,a+n+1);
    cout<<unique(a+1,a+n+1)-(a+1);
    //getch();
    return 0;
}
        



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
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    ll a[5],b[5],c[5];
    char k[4][4];
    FOR(i,1,4) cin>>a[i];
    FOR(i,1,3) scanf("%s",k[i]);
    ll res=oo;
    FOR(x,1,3) FOR(y,x+1,4){
        if(k[1][0]=='+') b[1]=a[x]+a[y]; else b[1]=a[x]*a[y];
        int p=2;
        FOR(z,1,4) if(z!=x && z!=y) b[p++]=a[z];
        FOR(x2,1,2) FOR(y2,x2+1,3){
            if(k[2][0]=='+') c[1]=b[x2]+b[y2]; else c[1]=b[x2]*b[y2];
            c[2]=b[6-x2-y2];
            if(k[3][0]=='+') c[3]=c[1]+c[2]; else c[3]=c[1]*c[2];
            res=min(res,c[3]);
        }
    }
    cout<<res<<endl;
    //getch();
}

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
set<pii> mys;
int n,a[maxn],mark[maxn],cs,cq,cd;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    reset(mark,0);
    FOR(i,1,n){
        scanf("%d",&a[i]);
        if(a[i]>0) mys.insert(pii(-a[i],i));
        else{
            FOR(v,1,3){
                if(mys.empty()) break;
                mark[mys.begin()->se]=v;
                mys.erase(mys.begin());
            }
            mys.clear();
        }
    }
    cs=cq=cd=0;
    FOR(i,1,n)
        if(a[i]>0){
            if(mark[i]==0) puts("pushFront"), ++cd;
            else if(mark[i]==1) puts("pushBack"), ++cd;
            else if(mark[i]==2) puts("pushQueue"), ++cq;
            else puts("pushStack"), ++cs;
        }else{
            int r=0;
            if(cd>0) ++r;
            if(cq>0) ++r;
            if(cs>0) ++r;
            printf("%d",r);
            if(cd>0) printf(" popBack"), --cd;
            if(cq>0) printf(" popQueue"), --cq;
            if(cs>0) printf(" popStack"), --cs;
            puts("");
            cd=cq=cs=0;
        }

    return 0;
}


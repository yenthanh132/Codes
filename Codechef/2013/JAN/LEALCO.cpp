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

int r[20],n,k,m,test,res,sum;

void duyet(int i){
    if(i>k){
        int maxv=0,c=0;
        FOR(j,i-k,i-1) 
            if(maxv<r[j]){
                maxv=r[j];
                c=1;
            }else if(maxv==r[j]) c++;
        if(c>=m) return;
    }
    if(i>n){
        res=min(res,sum);
        return;
    }
    REP(j,2){
        r[i]+=j;
        sum+=j;
        if(sum<res) duyet(i+1);
        r[i]-=j;
        sum-=j;
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&test);
    REP(index,test){
        scanf("%d%d%d",&n,&k,&m);
        FOR(i,1,n) scanf("%d",r+i);
        res=oo;
        sum=0;
        duyet(1);
        if(res!=oo) printf("%d\n",res); else puts("-1");
    }
    return 0;
}

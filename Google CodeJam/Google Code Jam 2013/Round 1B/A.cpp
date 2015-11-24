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

const int maxn=107;

int T,s,n,a[maxn];
int res;

int main(){
    freopen("A-large-practice.in","r",stdin);
    freopen("A-large-practice.out","w",stdout);
    scanf("%d",&T);
    REP(index,T){
        scanf("%d%d",&s,&n);
        FOR(i,1,n) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        res=oo;
        if(s==1){
            res=n;
            goto output;
        }
        FOR(v,0,n){
            int t=v;
            ll sum=s;
            FOR(i,1,n-v){
                while(sum<=a[i]){
                    sum=sum*2-1;
                    t++;
                }   
                sum+=a[i];
            }
            res=min(res,t);
        }
        output:
        printf("Case #%d: %d\n",index+1,res);
    }
    return 0;
}
           

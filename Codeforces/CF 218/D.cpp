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

const int maxn=200007;
int n, a[maxn],cap[maxn], m;
set<int> mys;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    scanf("%d",&m);
    
    reset(cap,0);
    FOR(i,1,n) mys.insert(i);    
    
    int k,x,y;
    set<int>::iterator it;
    REP(i,m){
        scanf("%d%d",&k,&x);
        if(k==1){
            scanf("%d",&y);
            while(y>0){
                it=mys.upper_bound(x-1);
                if(it==mys.end()) break;
                if(a[*it]-cap[*it]<=y){
                    y-=a[*it]-cap[*it];
                    cap[*it]=a[*it];
                    mys.erase(it);
                }else{
                    cap[*it]+=y;
                    y=0;
                    break;   
                }
            }
        }else{
            printf("%d\n",cap[x]);
        }   
    }
    
}

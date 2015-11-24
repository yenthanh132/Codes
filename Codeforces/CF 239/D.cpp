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

const int maxn=407;
const int maxv=maxn*maxn;

int a[maxn][maxn],L[maxn],R[maxn];
set<int> mark[maxv],mark2[maxv];
multiset<int> rbound;
int res,m,n;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&m,&n);
    FOR(i,1,m) FOR(j,1,n) scanf("%d",&a[i][j]);
    
    res=0;
    FOR(i1,1,m){
        FOR(j,1,n) L[j]=0, R[j]=n+1;
        FOR(i2,i1,m){
            FOR(j,1,n){
                int v=a[i2][j];
                set<int>::iterator it=mark[v].lower_bound(j);
                if(it!=mark[v].begin()){
                    --it;
                    L[j]=max(L[j],*it);
                }
                mark[v].insert(j);
            }
            FORD(j,n,1){
                int v=a[i2][j];
                set<int>::iterator it=mark2[v].lower_bound(j);
                if(it!=mark2[v].end()){
                    R[j]=min(R[j],*it);   
                }
                mark2[v].insert(j);
            }
            
            rbound.clear();
            int j1=0;
            int h=i2-i1+1;
            FOR(j,1,n){
                rbound.insert(R[j]);
                int tmp;
                while(j1<L[j] || (!rbound.empty() && j>=*rbound.begin())){
                    ++j1;
                    rbound.erase(rbound.find(R[j1]));
                }
                res=max(res,h*(j-j1));
            }
        }
        FOR(i2,i1,m) FOR(j,1,n){
            int v=a[i2][j];
            mark[v].clear();
            mark2[v].clear();
        }
    }    
    
    printf("%d\n",res);
    return 0;   
}

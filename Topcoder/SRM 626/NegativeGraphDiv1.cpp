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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll oo=(long long) 1e18 + 7;

struct NegativeGraphDiv1 {

    vector<int> from,to,weight;
    int n,m;
    vector<vector<ll> > f(int len){

        vector<vector<ll> >  res;
        res.resize(n+1);
        FOR(i,1,n) res[i].resize(n+1,oo);
        if(len==0){
            REP(i,m){
                int u=from[i], v=to[i], w=weight[i];
                res[u][v]=min(res[u][v],1ll*w);
            }
            FOR(u,1,n) res[u][u]=0;
            FOR(k,1,n) FOR(u,1,n) FOR(v,1,n) res[u][v]=min(res[u][v],res[u][k]+res[k][v]);
            return res;
        }

        if(len&1){
            vector<vector<ll> > tmp=f((len-1)/2);
            FOR(x,1,n) FOR(y,1,n){
                res[x][y]=tmp[x][y];
                REP(i,m){
                    int u=from[i], v=to[i], w=weight[i];
                    res[x][y]=min(res[x][y],tmp[x][u]-w+tmp[v][y]);
                }
            }
            return res;
        }else{
            vector<vector<ll> > tmp=f(len/2);

            FOR(x,1,n) FOR(y,1,n){
                res[x][y]=tmp[x][y];
                FOR(k,1,n)
                    res[x][y]=min(res[x][y],tmp[x][k]+tmp[k][y]);
            }
            return res;
        }

    }

	long long findMin(int N, vector <int> From, vector <int> To, vector <int> Weight, int charges) {
        from=From; to=To; weight=Weight;
        n=N; m=sz(from);
        vector<vector<ll> > res=f(charges);
        return res[1][n];
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor

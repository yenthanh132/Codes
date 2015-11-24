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

const int maxv=100000;

bool isprime[maxv+1];
int prime[maxv+1],val[maxv],s[maxv][6];

void init(){
    isprime[1]=0; isprime[2]=1;
    for(int i=4; i<=maxv; i+=2) prime[i]=2, isprime[i]=0;
    for(int i=3; i<=maxv; i+=2) isprime[i]=1;
    for(int i=3; i*i<=maxv; i+=2) if(isprime[i])
        for(int j=i*i; j<=maxv; j+=2*i){
            isprime[j]=0;   
            prime[j]=i;
        }
    
    set<int> list;
    FOR(i,0,1) FOR(j,1,5) s[i][j]=0;
    for(int i=2; i<=maxv; ++i){
        FOR(j,1,5) s[i][j]=s[i-1][j];
        if(isprime[i]) val[i]=1;
        else{
            int v=i;
            list.clear();
            while(!isprime[v]){
                list.insert(prime[v]);
                v/=prime[v];
            }
            list.insert(v);
            v=list.size();
            if(v<=5) val[i]=v;
        }
        s[i][val[i]]++;
    }
}

int main(){
    init();
    int q,x,y,k;
    scanf("%d",&q);
    REP(i,q){
        scanf("%d%d%d",&x,&y,&k);
        printf("%d\n",s[y][k]-s[x-1][k]);
    }
    return 0;
}

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

char s[maxn];
int n,myq[maxn],d[maxn];
bool free1[maxn];
vector<int> pos[10];

void bfs(){
    int first=1, last=1;
    myq[1]=1;
    reset(free1,1); free1[1]=0;
    d[1]=0;
    while(first<=last){
        int u=myq[first++];
        if(1<u && free1[u-1]){
            d[u-1]=d[u]+1;
            free1[u-1]=0;
            myq[++last]=u-1;
        }
        if(u<n && free1[u+1]){
            d[u+1]=d[u]+1;
            free1[u+1]=0;
            myq[++last]=u+1;
        }
        int v=s[u]-'0';
        REP(i,sz(pos[v])){
            if(free1[pos[v][i]]){
                d[pos[v][i]]=d[u]+1;
                myq[++last]=pos[v][i];
                free1[pos[v][i]]=0;
            }
        }
        pos[v].clear();
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%s",s+1);
    n=strlen(s+1);
    FOR(i,1,n) pos[s[i]-'0'].pb(i);
    bfs();
    printf("%d\n",d[n]);
}


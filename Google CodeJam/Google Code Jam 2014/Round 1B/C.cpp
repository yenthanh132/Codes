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

int test,n,m,per[maxn],mys[maxn],last;
bool a[maxn][maxn];
string code[maxn];

bool check(){
    mys[last=1]=per[1];
    FOR(i,2,n){
        bool found=0;
        while(last>0 && a[mys[last]][per[i]]==0) --last;
        if(last==0) return 0;
        mys[++last]=per[i];
    }
    return 1;
}

int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    scanf("%d",&test);
    FOR(tt,1,test){
        printf("Case #%d: ",tt);
        scanf("%d%d",&n,&m);
        FOR(i,1,n) cin>>code[i];
        int u,v;
        reset(a,0);
        FOR(i,1,m){
            scanf("%d%d",&u,&v);
            a[u][v]=a[v][u]=1;
        }              
        string best="";
        FOR(i,1,n) per[i]=i;
        do{
            if(check()){
                string tmp="";
                FOR(i,1,n) tmp+=code[per[i]];
                if(best=="" || tmp<best) best=tmp;  
            }
        }while(next_permutation(per+1,per+n+1));
        cout<<best<<endl;
    }
}

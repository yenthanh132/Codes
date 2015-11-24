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

const int maxn=57;

int n,test,a[maxn],b[maxn],mark[maxn];
double d[maxn],res,p[maxn];

void duyet(int i){
    if(i>n){  
        res+=d[n];
        return;   
    } 
    if(!mark[a[i]]){
        mark[a[i]]=1;
        d[i]=d[i-1]*p[i];
        duyet(i+1);
        mark[a[i]]=0;
    }
    if(!mark[b[i]]){
        mark[b[i]]=1;
        d[i]=d[i-1]*(1-p[i]);
        duyet(i+1);
        mark[b[i]]=0;
    }
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&test);
    int v;
    REP(tt,test){
        scanf("%d",&n);
        FOR(i,1,n){
            scanf("%d%d%d",&v,&a[i],&b[i]);
            p[i]=v/100.0;
        }
        res=0;
        if(n<=16){
            d[0]=1;
            reset(mark,0);
            duyet(1);   
        }
        printf("%0.12lf\n",res);
    }
    //getch();
    return 0;
}

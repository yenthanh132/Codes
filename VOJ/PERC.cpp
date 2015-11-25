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

const int maxn=2000007;

int a[maxn],n;
ll res;
map<int,int> factor;

void phantich(int v){
    int c;
    for(int i=2; i*i<=v; i++) if(v%i==0){
        c=0;
        while(v%i==0){
            c++;
            v/=i;
        }
        factor[i]=max(factor[i],c);
    }
    if(v>1) factor[v]=max(factor[v],1);
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    int j,c,next;
    res=1;
    FOR(i,1,n) if(a[i]){
        c=1;
        j=a[i]; a[i]=0;
        while(a[j]){
            c++;
            next=a[j];
            a[j]=0;
            j=next;
        }
        phantich(c);
    }
    for(map<int,int>::iterator it=factor.begin(); it!=factor.end(); it++){
        REP(j,it->se) res=(res*it->fi)%oo;
    }
    printf("%lld\n",res);
    //getch();
    return 0;
}

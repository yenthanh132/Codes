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


template<typename T>
void read(T& x){
    int c;
    bool isNega;
    isNega=0;
    while(!((x=getchar())>='-' && x<='9'));
    if(x=='-') isNega=true, x=0; else x-='0';
    while(((c=getchar())>='-' && c<='9')) x=10*x+(c-'0');
    if(isNega) x=-x;
}

const int maxn=100007;
int m,n,p,list[maxn],c;
bool a[maxn],b[maxn],mark[maxn];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    read(m); read(n); read(p);
    int v;
    c=0;
    FOR(i,1,m){
        read(v);
        if(!a[v]){
            a[v]=1;
            c++;
        }
    }
    m=c;
    FOR(i,1,n){
        read(v);
        b[v]=1;
    }
    int res=0,l=0;
    c=0;
    FOR(i,1,p){
        read(v);
        if(a[v] && !mark[v]){
            mark[v]=1;
            list[c++]=v;
        }else if(b[v]){
            REP(j,c) mark[list[j]]=0;
            c=0;
            l=i;
        }
        if(c==m) res=max(res,i-l);
    }
    
    printf("%d\n",res);
    
    //getch();
    return 0;
}

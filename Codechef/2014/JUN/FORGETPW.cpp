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

char s[1111111];
int to[256];

int main(){
    //freopen("input.txt","r",stdin);
    int T,n;
    char x[5],y[5];
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d",&n);
        reset(to,0);
        REP(i,n){
            scanf("%s%s",x,y);
            to[x[0]]=y[0];
        }
        scanf("%s",s);
        n=strlen(s);
        REP(i,n) if(to[s[i]]) s[i]=to[s[i]];
        int l=0, r=n-1;
        while(l<=r && s[l]=='0') ++l;
        bool found=0;
        REP(i,n) if(s[i]=='.') found=1;
        if(found){
            while(l<=r && s[r]=='0') --r;
            if(l<=r && s[r]=='.') --r;
        }
        if(l>r) puts("0");
        else{
            FOR(x,l,r) putchar(s[x]);
            puts("");
        }
    }
}

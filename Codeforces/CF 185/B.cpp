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

const int maxn=2007;

int b,d,m,n,delta[maxn],val[maxn];
char a[maxn],c[maxn];

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d\n",&b,&d);
    gets(a+1); m=strlen(a+1);
    gets(c+1); n=strlen(c+1);
    ll v;
    if(b<=2000){
        v=0;
        int p=1;
        REP(i,b)
            FOR(x,1,m) if(a[x]==c[p]){
                p++;
                if(p>n){
                    p=1;
                    v++;
                }
            }
        cout<<v/d<<endl;
    }else{
        val[0]=0;
        int p=1;
        FOR(i,1,2000){
            val[i]=val[i-1];
            FOR(x,1,m) if(a[x]==c[p]){
                p++;
                if(p>n){
                    p=1;
                    val[i]++;
                }
            }
        }
        FOR(i,1,2000) delta[i]=val[i]-val[i-1];
        int ck=-1;
        FOR(len,100,500){
            bool ok=1;
            REP(i,len) if(delta[2000-i]!=delta[2000-len-i]){
                ok=0;
                break;
            }
            if(ok){
                ck=len;
                break;
            }
        }
        ll sum=0;
        REP(i,ck) sum+=delta[2000-i];
        v=val[2000]+((b-2000)/ck)*sum;
        FOR(i,1,(b-2000)%ck) v+=delta[2000-ck+i];
        cout<<v/d<<endl;
    }
    
    //getch();
    return 0;
}
    

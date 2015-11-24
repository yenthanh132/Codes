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

const int maxn=10007;
int t,n,res,a[5];
ll gt[maxn],v,c[10];
char s[maxn];

ll pow(ll v, int n){
    if(n==0) return 1; else if(n==1) return v;
    ll t=pow(v,n/2); t=(t*t)%oo;
    if(n&1) return (t*v)%oo; else return t;
}

ll tohop(int k, int n){
    if(k>n) return 0;
    if(k==1) return n;
    ll v=1;
    REP(i,k) v=(v*(n-i))%oo;
    return (v*pow(gt[k],oo-2))%oo;
}

int countarr(int n){
    sort(a,a+n);
    int x=0,y;
    ll v=1;
    x=0;
    while(x<n){
        y=x;
        while(y<n-1 && a[y+1]==a[x]) y++;
        v=(v*tohop(y-x+1,c[a[x]]))%oo;
        x=y+1;
    }
    return v%oo;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d\n",&t);
    gt[0]=1; FOR(i,1,10000) gt[i]=(gt[i-1]*i)%oo;
    REP(index,t){
        gets(s);
        n=strlen(s);
        reset(c,0);
        REP(i,n) c[s[i]-48]++;
        res=0;
        REP(i,10) if(c[i]){
            if(i==9) res=(res+c[i])%oo;
            FOR(j,i,9) if(c[j]){
                if((i+j)%9==0 && i+j>0){
                    a[0]=i; a[1]=j;
                    res=(res+countarr(2))%oo;
                }
                FOR(k,j,9) if(c[k]){
                    if((i+j+k)%9==0 && i+j+k>0){
                        a[0]=i; a[1]=j; a[2]=k;
                        res=(res+countarr(3))%oo;
                    }    
                    FOR(l,k,9) if(c[l])
                        if((i+j+k+l)%9==0 && i+j+k+l>0){
                            a[0]=i; a[1]=j; a[2]=k; a[3]=l;
                            res=(res+countarr(4))%oo;
                        }
                }
            }
        }
            
        printf("%d\n",res);
    }
    //getch();
    return 0;
}

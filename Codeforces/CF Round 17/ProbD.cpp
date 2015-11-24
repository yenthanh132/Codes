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

char b[1000007],n[1000007];
int a,c;

int getmod(){
    ll a=0;
    int v,n=strlen(b),i=0,mul;
    while(n-i>9){
        v=0; REP(j,9) v=v*10+b[i+j]-48;
        a=(a*int(1e9)+v)%c;
        i+=9;
    }
    mul=1; v=0;
    REP(j,n-i){
        mul*=10;
        v=v*10+b[i+j]-48;
    }
    a=(a*mul+v)%c;
    return a;
}

void decn(){
    int m=strlen(n);
    REPD(i,m)
        if(n[i]=='0') n[i]='9';
        else{
            n[i]-=1;
            break;
        }
}

ll pow(ll a, int n){
    if(n==0) return 1;
    if(n==1) return a;
    ll t=pow(a,n/2);
    if(n&1) return(((t*t)%c)*a)%c; else return(t*t)%c;
}

ll bigpow(){
    ll mul=a,res=1;
    int m=strlen(n);
    REPD(i,m){
        res=(res*pow(mul,n[i]-48))%c;
        mul=pow(mul,10);
    }
    return(res%c);
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%s%s%d",&b,&n,&c);
    a=getmod();
    decn();
    ll v=bigpow();
    ll res=(v*a-v)%c; if(res<=0) res+=c;
    cout<<res;
    //getch();
    return 0;
}

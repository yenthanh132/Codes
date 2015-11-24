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
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxv=10000000;
const int maxn=670000;
const int maxk=1000007;

int isprime[maxv+1],minprime[maxv+1];
int cnt,list[maxn];
ll p[maxn],dem[maxv+1];
int n,a[maxk];

void init(){
    cnt=1;
    isprime[2]=1;
    for(int i=2; i<=maxv; i+=2) minprime[i]=cnt;
    for(int i=3; i<=maxv; i+=2) isprime[i]=1;
    for(int i=3; i*i<=maxv; i+=2) if(isprime[i]){
        minprime[i]=++cnt;
        for(int j=i*i; j<=maxv; j+=i*2){
            isprime[j]=0;
            minprime[j]=cnt;
        }
    }
    list[cnt=1]=2;
    for(int i=3; i<=maxv; i+=2) if(isprime[i]){
        list[++cnt]=i;
        minprime[i]=cnt;
    }
}

void build(){
    int m=n, pos=1;
    FOR(i,2,10000000){
        while(pos<=n && a[pos]<i){
            pos++;   
            m--;
        }
        if(m==0) break;
        dem[i]=m;
    }
    FORD(i,10000000,2){
        p[minprime[i]]+=dem[i];
        dem[i/list[minprime[i]]]+=dem[i];
    }
}

bool check(ll v){
    ll t;
    FOR(i,1,cnt) if(p[i]){
        ll p2=0;
        t=v;
        while(t>=list[i]){
            p2+=t/list[i];
            t/=list[i];   
        }   
        if(p2<p[i]) return 0;
    }
    return 1;
}

#include <conio.h>
int main(){
    init();
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    build(); 
    ll res=oo, left=1, right=oo, mid;
    while(left<=right){
        mid=(left+right)>>1;
        if(check(mid)){
            res=mid;
            right=mid-1;
        }else left=mid+1;
    }
    cout<<res<<endl;
    //getch();
    return 0;
}


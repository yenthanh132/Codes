#include <conio.h>
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

const int maxn=1000007;
ll m,n,x,y,k;
ll cnt[maxn][26];
char a[maxn],b[maxn],tmp[maxn];

ll gcd(ll a, ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

ll lcm(ll a, ll b){
    return (a/gcd(a,b))*b;
}

int main(){
    //freopen("test.txt","r",stdin);
    cin>>m>>n;
    scanf("%s",a+1); x=strlen(a+1);
    scanf("%s",b+1); y=strlen(b+1);
    if(x==y){
        ll res=0;
        FOR(i,1,x) res+=(a[i]!=b[i]);
        res*=m;
        cout<<res<<endl;     
    }else{
        k=lcm(x,y);
        if(x>y){
            FOR(i,1,y) tmp[i]=b[i];
            FOR(i,1,x) b[i]=a[i];
            FOR(i,1,y) a[i]=tmp[i];
            swap(x,y);  
            swap(m,n); 
        }
        reset(cnt,0);
        ll r=y/(k/x);
        FOR(i,1,y) cnt[(i-1)%r][b[i]-'a']++;
        ll res,dem=0;
        FOR(i,1,x) dem+=cnt[(i-1)%r][a[i]-'a'];
        res=(k-dem)*((m*x)/k);
        cout<<res<<endl;
    }
    //getch();
    return 0;
}

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

const int maxn=222222;
ll a,b;
int arr[maxn],cnt;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%I64d%I64d",&a,&b);
    if(b<=1){
        printf("%I64d\n",a*a-b*b);
        REP(i,a) printf("o");
        REP(i,b) printf("x");
        return 0;   
    }
    if(a==0){
        printf("%I64d\n",-b*b);
        REP(i,b) printf("x");   
        return 0;
    }
    
    ll res=-round(1e18);
    ll div,v,k;
    FOR(x,2,min(a+1,b)){
        if(b%x==0){
            v=b*b/x;
        }else{
            ll y=b/x;
            v=(y+1)*(y+1)*(b%x) + y*y*(x-b%x);
        }
        if(x>1) k = (x-2) + (a-x+2)*(a-x+2);
        else k=a*a;
        
        if(k-v>res){
            res=k-v;
            div=x;   
        }
    }
    
    cnt=div*2-1;
    for(int i=1; i<=cnt; i+=2) arr[i]=b/div;
    for(int i=1, r=b%div; i<=cnt && r>0; i+=2, --r) ++arr[i];
    for(int i=2; i<=cnt; i+=2) if(i==2) arr[i]=a-div+2; else arr[i]=1;
    
    printf("%I64d\n",res);
    FOR(i,1,cnt){
        REP(j,arr[i]) printf(i&1?"x":"o");   
    }
    return 0;    
}

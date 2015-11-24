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

int n,q;
ll a[100007],b[100007],c[100007];
ll R,p1,p2,MOD;


ll mul(ll a, ll b){
    if(b==0 || a==0) return 0;   
    if(b==1) return a;
    ll tmp=mul(a,b/2);
    tmp+=tmp;    
    if(b&1) tmp+=a;
    return tmp%MOD;
}

int main(){
    int test;
    freopen("input.txt","r",stdin);
    freopen("output3.txt","w",stdout);
    scanf("%d",&test);
    REP(tt,test){
        scanf("%d%d%I64d%I64d%I64d",&n,&q,&R,&p1,&p2);
        FOR(i,1,n) scanf("%I64d",&a[i]);
        FOR(i,1,n) a[i]=b[i]=c[i]=0;
        MOD=p1*p2;
        int type,s,d,x,y;
        
        REP(t,q){
            scanf("%d",&type);
            if(type==0){
                scanf("%d%d%d%d",&s,&d,&x,&y);   
                ll t=1,td=0;
                FOR(i,x,y){
                    a[i] = (a[i] + mul(t,s+td)) % MOD; 
                     b[i] = (b[i] + mul(t,s+td)) % p1;    
                     c[i] = (c[i] + mul(t,s+td)) % p2;               
                    t=mul(t,R);  
                    td=(td+d)%MOD;
                }
               
                
            }else if(type==1){
                scanf("%d%d",&x,&s);
                
            }else{
                
                scanf("%d%d",&x,&y);
                ll sb=0,sc=0,sa=0;
                FOR(i,x,y){
                    sa=(sa+a[i])%MOD;
                    sb=(sb+b[i])%p1;
                    sc=(sc+c[i])%p2;
                }
                cout<<sb<<' '<<sc<<' '<<sa<<endl;
            }
        }
           
    }
    return 0;
}

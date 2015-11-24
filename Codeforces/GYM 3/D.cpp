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

const int maxn=1007;

struct team{
    int k,da,db;
}a[maxn];

int n,ca,cb;

bool cmp(const team &a, const team &b){
    return a.da-a.db > b.da-b.db;   
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d",&n,&ca,&cb);
    while(n){
        FOR(i,1,n) scanf("%d%d%d",&a[i].k,&a[i].da,&a[i].db);
        int res=0,sa=0,sb=0;
        FOR(i,1,n){
            res+=a[i].da*a[i].k;
            sa+=a[i].k;
        }
        sort(a+1,a+n+1,cmp);
        FOR(i,1,n){
            if(a[i].da-a[i].db<=0 && sa<=ca) break;
            if(a[i].da-a[i].db>0 && sb<cb){
                if(a[i].k<cb-sb){
                    res-=(a[i].da-a[i].db)*a[i].k;
                    sb+=a[i].k;
                    sa-=a[i].k;
                }else{
                    res-=(a[i].da-a[i].db)*(cb-sb);
                    sa-=cb-sb;
                    sb=cb;
                    break;
                }
            }else if(a[i].da-a[i].db<=0 && sa>ca){
                if(a[i].k<sa-ca){
                    res-=(a[i].da-a[i].db)*a[i].k;
                    sa-=a[i].k;
                    sb+=a[i].k;
                }else{
                    res-=(a[i].da-a[i].db)*(sa-ca);
                    sb+=sa-ca;
                    sa=ca;
                }
            }
        }
        
        cout<<res<<endl;      
                
        
        
        scanf("%d%d%d",&n,&ca,&cb);
    }
    
    //getch();
    return 0;
}
    
        

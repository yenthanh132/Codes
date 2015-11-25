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

ll kwh2bill(ll v){
    ll ans=0;
    if(v>100) ans+=200ll*100; else ans+=200ll*v;
    if(v>10000) ans+=300ll*9900; else ans+=300ll*max(v-100,0ll);
    if(v>1000000) ans+=500ll*990000; else ans+=500ll*max(v-10000,0ll);
    ans+=700ll*max(v-1000000,0ll);
    return ans;
}

ll bill2kwh(ll v){
    if(v>200ll*100+300ll*9900+500ll*990000) return (v-200ll*100-300ll*9900-500ll*990000)/700+1000000;
    if(v>200ll*100+300ll*9900) return (v-200ll*100-300ll*9900)/500+10000;
    if(v>200ll*100) return (v-200ll*100)/300+100;
    return v/200;
}

ll x,y;
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>x>>y;
    ll sum=bill2kwh(x);
    ll left,right,mid,s1,s2;
    left=0; right=sum/2;
    while(left<=right){
        mid=(left+right)/2;
        s1=kwh2bill(mid); s2=kwh2bill(sum-mid);
        if(s2-s1==y){
            cout<<s1<<endl;
            break;
        }else if(s2-s1>y) left=mid+1;
        else right=mid-1;
    }
    //getch();
    return 0;
    
}

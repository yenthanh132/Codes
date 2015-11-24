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

int m,n,s,t;
ll res,v;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>m>>n>>s;
    res=0;
    int w,h,w2,h2,l,leftS;
    FOR(i,0,(m-1)/2) FOR(j,0,(n-1)/2){
        h=(i*2+1); w=(j*2+1);
        t=w*h;
        if(t>s) break;
        if(t==s) res+=(ll(i+1)*(j+1)*2-1)*(m-h+1)*(n-w+1);
        else{
            leftS=s-t;
            if(leftS&1) continue;
            leftS/=2;
            FOR(k,0,m) if(k!=i)
                if(k<i){
                    h2=k*2+1;
                    if(leftS%h2!=0) continue;
                    l=leftS/h2+j;
                    w2=l*2+1;
                    h2=max(h2,h); w2=max(w2,w);
                    res+=ll(max(m-h2+1,0))*max(n-w2+1,0);
                }else{
                    h2=k-i;
                    if(leftS%h2!=0) continue;
                    l=leftS/h2;
                    if((l-1)&1) continue;
                    l=(l-1)/2;
                    if(l>=j) continue;
                    h2=k*2+1;
                    w2=l*2+1;
                    h2=max(h2,h); w2=max(w2,w);
                    res+=ll(max(m-h2+1,0))*max(n-w2+1,0);
                }
        }
    }
    cout<<res<<endl;
    //getch();
    return 0;
}

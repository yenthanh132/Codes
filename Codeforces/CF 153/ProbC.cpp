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

int solve(ll a, ll b, int k){
    int d[20];
    REP(i,20) d[i]=oo;
    d[a-b]=0;
    queue<ll> myqueue;
    myqueue.push(a);
    ll u;
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        if(u-1>=b && d[u-1-b]>d[u-b]+1){
            d[u-1-b]=d[u-b]+1;
            myqueue.push(u-1);
        }
        FOR(x,2,k)
            if(u-u%x>=b && d[u-u%x-b]>d[u-b]+1){
                d[u-u%x-b]=d[u-b]+1;
                myqueue.push(u-u%x);
            }
    }
    return d[0];
}
        
ll cal(ll a, ll b, int k){
    ll res=0;
    while(a>b){
        if(a%k==0){
            a--;
            res++;
        }else{
            if(a/k==b/k){
                res+=solve(a,b,k);
                a=b;
                break;
            }else{
                if(a%k!=k-1){
                    res++;
                    a-=a%k;
                }else{
                    res+=2*((a-b)/k);
                    a-=((a-b)/k)*k;
                }
            }
        }
    }
    return res;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    ll a,b,res;
    int k,d[1007];
    cin>>a>>b>>k;
    
    res=1000000000000000007ll;
    queue<ll> myqueue;
    d[500]=0;
    REP(i,500) d[i]=oo;
    myqueue.push(a);
    ll u;
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        if(u>=b) res=min(res,cal(u,b,k)+d[u-a+500]);
        if(d[u-a+500]==12) continue;
        if(u-1>=b && d[u-a+500-1]>d[u-a+500]+1){
            d[u-a+500-1]=d[u-a+500]+1;
            myqueue.push(u-1);
        }
        FOR(x,2,k)
            if(u-u%x>=b && d[u-a+500 - u%x]>=d[u-a+500]+1){
                d[u-a+500 - u%x]=d[u-a+500]+1;
                myqueue.push(u-u%x);
            }
    }
    
    cout<<res<<endl;
    //getch();
    return 0;
}
            
        

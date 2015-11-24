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

const int maxn=50007;
struct work{int t,s,p,id;} a[maxn];
int n;
ll endtime,ans[maxn];
vector<int> listp,list1,listt;

bool cmpwork(const work &a, const work &b){
    return a.t<b.t;
}

void init_listp(){
    if(list1.empty()){
        listp.pb(1);
        return;
    }
    if(list1[0]>1) listp.pb(1);
    REP(i,sz(list1)-1) if(list1[i]+1<list1[i+1]) listp.pb(list1[i]+1);
    if(list1.back()<1000000000) listp.pb(1000000000);
}

//----------------------
struct classcmp{
    bool operator()(const work &a, const work &b) const{
        return a.p>b.p;
    }
};

set<work,classcmp> myset;

int check(int pos){
    int pp=listp[pos];
    int x=1;
    ll t=listt[0];
    work node;
    myset.clear();
    REP(i,sz(listt)){
        while(t<listt[i] && !myset.empty()){
            node=*myset.begin();
            myset.erase(myset.begin());
            if(node.s+t<=listt[i]){
                t+=node.s;
                ans[node.id]=t;
                if(pp==node.p){
                    if(t<endtime) return -1;
                    else if(t>endtime) return 1;
                }
            }else{
                node.s-=listt[i]-t;
                t=listt[i];
                myset.insert(node);
            }
        }
        while(x<=n && a[x].t<=listt[i]){
            node=a[x];
            if(node.p==-1) node.p=pp;
            myset.insert(node);
            x++;
        }
        t=max(t,1ll*listt[i]);
    }
    while(!myset.empty()){
        node=*myset.begin();
        myset.erase(myset.begin());
        t+=node.s;
        ans[node.id]=t;
        if(pp==node.p){
            if(t<endtime) return -1;
            else if(t>endtime) return 1;
        }
    }
    return 0;
}
        

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d%d%d",&a[i].t,&a[i].s,&a[i].p); 
        if(a[i].p!=-1) list1.pb(a[i].p);
        listt.pb(a[i].t);
        a[i].id=i;
    }
    scanf("%I64d",&endtime);
    sort(a+1,a+n+1,cmpwork);
    sort(list1.begin(),list1.end());
    sort(listt.begin(),listt.end());
    listt.resize(unique(listt.begin(),listt.end())-listt.begin());
    init_listp();
    

    
    int l=0, r=sz(listp)-1, mid, res, val;   
    while(l<=r){
        mid=(l+r)/2;
        val=check(mid);
        if(val==0){
            res=listp[mid];
            break;
        }else if(val<0) r=mid-1; else l=mid+1;
    }
    
    printf("%d\n",res);
    FOR(i,1,n) printf("%I64d ",ans[i]);
    puts("");
            
    return 0;   
}

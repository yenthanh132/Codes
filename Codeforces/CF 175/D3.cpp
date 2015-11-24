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

const int maxn=20;

int n,n1,n2,d[maxn],c[maxn];
bool mark[maxn],free1[maxn];
multiset<pii> mys;
ll res;

void duyet1(int i){
    if(i>n1){
        reset(free1,1);
        FOR(j,1,n1){
            c[j]=(j-1+d[j]-1)%n+1;
            if(!free1[c[j]]) return;
            free1[c[j]]=0;
        }
        int id=0,id2=0;
        FOR(j,1,n1) id+=(1<<(d[j]-1));
        FOR(j,1,n1) id2+=(1<<(c[j]-1));
        mys.insert(pii(id,id2));
        return;   
    }
    FOR(v,1,n) if(!mark[v]){
        if(i==1) cout<<v<<endl;
        d[i]=v;
        mark[v]=1;
        duyet1(i+1);
        mark[v]=0;
    }
}

void duyet2(int i){
    if(i>n2){
        reset(free1,1);
        FOR(j,1,n2){
            c[j]=(j+n1-1+d[j]-1)%n+1;
            if(!free1[c[j]]) return;
            free1[c[j]]=0;
        }
        int id=0,id2=0;
        FOR(j,1,n2) id+=(1<<(d[j]-1));
        FOR(j,1,n2) id2+=(1<<(c[j]-1));
        id^=((1<<n)-1);
        id2^=((1<<n)-1);
        res=(res+mys.count(pii(id,id2)))%oo;
        return;
    }
    FOR(v,1,n) if(!mark[v]){
        if(i==1) cout<<v<<endl;
        d[i]=v;
        mark[v]=1;
        duyet2(i+1);
        mark[v]=0;
    }
}

#include <conio.h>
int main(){
    //freopen("outt.txt","w",stdout);
    cin>>n;
    n1=n/2;
    n2=n-n1;
    
    duyet1(1);
    //for(multiset<pii>::iterator it=mys.begin(); it!=mys.end(); it++)
        //cout<<it->fi<<' '<<it->se<<endl;
        
    res=0;
    duyet2(1);
    ll gt=1;
    FOR(j,1,n) gt=(gt*j)%oo;
    res=(res*gt)%oo;
    
    cout<<res<<endl;
    
    //getch();
}

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

const int maxn=100007;

int n,q,stand[maxn],match[maxn];
int BIT[maxn];
set<int> left_set,right_set;
char s[maxn];

void update(int x,int v){
    for(int i=x; i<=n; i+=i&(-i)) BIT[i]+=v;
}

int count(int x){
    int res=0;
    for(int i=x; i; i-=i&(-i)) res+=BIT[i];
    return res;
}

int add(int x, int y){
    update(x,1); update(y,1);   
}

void del(int x, int y){
    update(x,-1); update(y,-1);
}

int getleft_set(int x){
    if(left_set.empty()) return oo;
    set<int>::iterator it;
    it=left_set.lower_bound(x+1);
    if(it==left_set.begin()) return oo;
    it--;
    return *it;
}

int getright_set(int x){
    if(right_set.empty()) return -oo;
    set<int>::iterator it;
    it=right_set.upper_bound(x-1);
    if(it==right_set.end()) return -oo;
    return *it;
}

int query(int l, int r){
    int res=count(r)-count(l-1);
    int u,v;
    u=getleft_set(l);
    v=getright_set(l);
    if(u<v && match[u]==v && match[v]==u && u<l && l<=v && v<=r) res--;
    u=getleft_set(r);
    v=getright_set(r);
    if(u<v && match[u]==v && match[v]==u && r<v && l<=u && u<=r) res--;
    return res/2;
}

void toggle1(int x){
    int u,v;
    if(stand[x]){
        stand[x]=0;
        if(s[x]=='>') left_set.erase(left_set.find(x));
        else right_set.erase(right_set.find(x));
        if(match[x]){
            u=x;
            v=match[x];
            if(u>v) swap(u,v);
            del(u,v);
            match[u]=0; match[v]=0;
        }
        u=getleft_set(x); 
        v=getright_set(x);
        if(u<=v && match[u]==0 && match[v]==0){
            match[u]=v;
            match[v]=u;
            add(u,v);
        }
    }else{
        stand[x]=1;
        u=getleft_set(x); v=getright_set(x);
        if(u<=v && match[u]==v && match[v]==u){
            match[u]=0;
            match[v]=0;
            del(u,v);
        }
        if(s[x]=='>') left_set.insert(x);
        else right_set.insert(x);
        u=getleft_set(x); v=getright_set(x);
        if(u<=v && match[u]==0 && match[v]==0){
            match[u]=v;
            match[v]=u;
            add(u,v);
        }
    }   
}

void toggle2(int x){
    int u,v;
    if(s[x]=='>'){
        left_set.erase(left_set.find(x));
        right_set.insert(x);
        s[x]='<';
    }else{
        right_set.erase(right_set.find(x));
        left_set.insert(x);
        s[x]='>';
    }
    if(match[x]){
        u=x;
        v=match[x];
        if(u>v) swap(u,v);
        del(u,v);
        match[u]=0; match[v]=0;
    }
    u=getleft_set(x); v=getright_set(x);
    if(u<=v && match[u]==0 && match[v]==0){
        match[u]=v;
        match[v]=u;
        add(u,v);
    }
}



#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    int T;
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d%d",&n,&q);
        scanf("%s",s+1);
        FOR(i,1,n){
            stand[i]=1;
            match[i]=0;
        }
        reset(BIT,0);
        left_set.clear(); right_set.clear();
        FOR(i,1,n){
            if(i<n && s[i]=='>' && s[i+1]=='<'){
                add(i,i+1);
                match[i]=i+1;
                match[i+1]=i;
            }
            if(s[i]=='>') left_set.insert(i);
            else right_set.insert(i);
        }
        //FOR(i,1,n) cout<<sz(BIT[i])<<endl;
        int k,x,y;
        REP(i,q){
            scanf("%d%d",&k,&x);
            if(k==1) toggle1(x);
            else if(k==2) toggle2(x);
            else{
                scanf("%d",&y);
                printf("%d\n",query(x,y));
            }
        }
        
    }
    
    getch();
    return 0;
}

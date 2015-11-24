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

const int maxn=407;

//=================================


const int MAXN=maxn*maxn*30;


struct FastFlow{

    struct edge{
        int x,y,c,f;
    }e[MAXN];

    int head[MAXN],next[MAXN],m,n,st,fi;
    queue<int> myq;
    int current[MAXN], exceed[MAXN], h[MAXN], counth[MAXN];

    void initGraph(int N, int s, int f){
        n=N;
        reset(head,-1);
        m=0;
        st=s;
        fi=f;
    }

    int push(int u, int v, int w) {
        e[m].x = u; e[m].y = v; e[m].c = w; e[m].f = 0;
        next[m] = head[u]; head[u] = m++;
        e[m].x = v; e[m].y = u; e[m].c = e[m].f = 0;
        next[m] = head[v]; head[v] = m++;
    }

    void init()
    {
        while(!myq.empty()) myq.pop();
        FOR(u, 1, n)
        {
            current[u] = head[u];
            h[u] = 1;
        }
        h[st] = n;
        h[fi] = 0;
        reset(exceed, 0);
        reset(counth, 0);
        counth[1] = n - 2;
        counth[0] = 1;
        counth[n] = 1;
        for (int i = head[st]; i != -1; i = next[i])
        {
            e[i].f = e[i].c;
            e[i ^ 1].f = -e[i].f;
            exceed[st] -= e[i].c;
            exceed[e[i].y] += e[i].c;
        }
        FOR(u, 1, n) if(u != st && u != fi && exceed[u] > 0) myq.push(u);
    }
    void pushE(int i)
    {
        int delta = min(exceed[e[i].x], e[i].c - e[i].f);
        e[i].f += delta;
        e[i ^ 1].f -= delta;
        exceed[e[i].x] -= delta;
        exceed[e[i].y] += delta;
    }
    void seth(int u, int newh)
    {
        counth[h[u]]--;
        h[u]=newh;
        counth[h[u]]++;
    }
    void perform_gap(int gap)
    {
        if (0 < gap && gap < n && counth[gap] == 0)
            FOR(u, 1, n) if(u != st && gap < h[u] && h[u] <= n)
            {
                seth(u, n + 1);
                current[u] = head[u];
            }
    }
    void lift(int u)
    {
        int minh = 2*n;
        for (int i = head[u]; i != -1; i = next[i])
            if (e[i].c > e[i].f) minh = min(minh, h[e[i].y]);
        int old = h[u];
        seth(u, minh + 1);
        perform_gap(old);
    }
    void FIFOPreflowPush()
    {

        while(!myq.empty())
        {
            int z = myq.front();
            myq.pop();
            for (; current[z] != -1; current[z] = next[current[z]])
            {
                edge &ed = e[current[z]];
                if (ed.c > ed.f && h[z] > h[ed.y])
                {
                    bool needqueue = (ed.y != fi && ed.y != st && exceed[ed.y] == 0);
                    pushE(current[z]);
                    if (needqueue) myq.push(ed.y);
                    if (exceed[z] == 0) break;
                }
            }
            if (exceed[z] > 0)
            {
                lift(z);
                current[z] = head[z];
                myq.push(z);
            }

        }
    }

} myflow;
//==================================

int a[maxn],b[maxn],res,n;
vector<pii> l1,l2;
set<int> mys;


int gcd(int a, int b){
    if(b==0) return a;
    if(a<b) return gcd(b,a);
    return gcd(b,a%b);
}

map<int,int> mm;

int main(){
    //freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    REP(tt,t){
        scanf("%d",&n);

        res=0;
        FOR(i,1,n) scanf("%d",&a[i]);
        FOR(i,1,n) scanf("%d",&b[i]);

        l1.clear(); l2.clear();
        mm.clear();
        FOR(i,1,n) FOR(j,1,n) if(a[i]<b[j]){
            int d=gcd(a[i],b[j]);
            if(d>1) ++mm[d];
        }
        for(map<int,int>::iterator it = mm.begin(); it!=mm.end(); ++it) l1.pb(*it);
        mm.clear();
        FOR(i,1,n) FOR(j,1,n) if(a[i]>b[j]){
            int d=gcd(a[i],b[j]);
            if(d>1) ++mm[d];
        }
        for(map<int,int>::iterator it = mm.begin(); it!=mm.end(); ++it) l2.pb(*it);

        mm.clear(); mys.clear();
        int cnt=0;
        REP(i,sz(l1)){
            int v=l1[i].fi;
            for(int k=2; k*k<=v; ++k) if(v%k==0){
                mys.insert(k);
                while(v%k==0) v/=k;
            }
            if(v>1) mys.insert(v);
        }
        REP(i,sz(l2)){
            int v=l2[i].fi;
            for(int k=2; k*k<=v; ++k) if(v%k==0){
                if(mys.count(k) && mm[k]==0) mm[k]=++cnt;
                while(v%k==0) v/=k;
            }
            if(mys.count(v) && mm[v]==0) mm[v]=++cnt;
        }

        myflow.initGraph(2+sz(l1)+sz(l2)+cnt,1,2);
        REP(i,sz(l1)){
            int u=i+3;
            myflow.push(1,u,l1[i].se);
            int v=l1[i].fi;
            for(int k=2; k*k<=v; ++k) if(v%k==0){
                if(mm.count(k)) myflow.push(u,mm[k]+2+sz(l1)+sz(l2),oo);
                while(v%k==0) v/=k;
            }
            if(mm.count(v)) myflow.push(u,mm[v]+2+sz(l1)+sz(l2),oo);
        }
        REP(i,sz(l2)){
            int u=i+sz(l1)+3;
            myflow.push(u,2,l2[i].se);
            int v=l2[i].fi;
            for(int k=2; k*k<=v; ++k) if(v%k==0){
                if(mm.count(k)) myflow.push(mm[k]+2+sz(l1)+sz(l2),u,oo);
                while(v%k==0) v/=k;
            }
            if(mm.count(v))  myflow.push(mm[v]+2+sz(l1)+sz(l2),u,oo);
        }
        myflow.init();
        myflow.FIFOPreflowPush();
        cout<<res+myflow.exceed[2]<<endl;

    }
}

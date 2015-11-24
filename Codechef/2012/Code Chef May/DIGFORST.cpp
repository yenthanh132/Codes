#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxv 50400
#define oo 1000000007

using namespace std;

int res;

//dijkstra
int d[maxv],n,num[100],a[100][100],ds[8];
bool free1[maxv],mark[8];
// HEAP

struct hnode{int v,m3,m4,m6,m7;} h[maxv];
int pos[maxv], nheap;

void update(int v){
    int c,p;
    c=pos[v];
    if (c==0){nheap++; c=nheap;}
    p=c/2;
    while (p>0 && d[h[p].v]>d[v]){
        h[c]=h[p];
        pos[h[c].v]=c;
        c=p; p=c/2;
    }
    pos[v]=c; 
    h[c].v=v;
}

int pop(){
    int r,c,v,vv;
    vv=h[1].v; v=h[nheap].v; nheap--;
    r=1;
    while (r*2<=nheap){
        c=r*2;
        if (c<nheap && d[h[c+1].v]<d[h[c].v]) c++;
        if (d[v]<=d[h[c].v]) break;
        h[r]=h[c]; pos[h[r].v]=r;
        r=c;
    }
    pos[v]=r;
    h[r].v=v;
    return vv;
}

int hnode2int(hnode p){return p.v*504 + p.m3*168 + p.m4*42 + p.m6*7 + p.m7;}
hnode int2hnode(int v){
    hnode p;
    p.v=v/504; v%=504; 
    p.m3=v/168; v%=168;
    p.m4=v/42; v%=42;
    p.m6=v/7; v%=7; 
    p.m7=v;
    return p;
}

void keepresult(const int i){
    if (i>7){
        hnode p; p.v=n-1; p.m3=ds[3]; p.m4=ds[4]; p.m6=ds[6]; p.m7=ds[7];
        res=min(res,d[hnode2int(p)]);
        return;
    }
    ds[i]=0; keepresult(i+1);
    if (!mark[i] && i!=5)
       for(int j=1;j<i;j++) {ds[i]=j; keepresult(i+1);}
}

void solve(){
    if (!mark[num[0]] || (mark[2] && num[n-1]%2!=0) || (mark[5] && num[n-1]%5!=0)) return;
    memset(free1,true,sizeof(free1));
    memset(pos,0,sizeof(pos)); nheap=0;
    int u,v,k;
    hnode p,q;
    for(u=0; u<maxv; u++) d[u]=oo;
    p.v=0;
    p.m3=num[0]%3;
    p.m4=num[0]%4;
    p.m6=num[0]%6; 
    p.m7=num[0]%7; 
    u=hnode2int(p);
    d[u]=num[0];
    update(u);
    while (nheap){
        u=pop(); p=int2hnode(u);
        free1[u]=false;
        for(v=0;v<n;v++) if (a[p.v][v] && mark[num[v]]){
            q.v=v;
            q.m3=(p.m3*10+num[v])%3;
            q.m4=(p.m4*10+num[v])%4;
            q.m6=(p.m6*10+num[v])%6;
            q.m7=(p.m7*10+num[v])%7;
            k=hnode2int(q);
            if (free1[k] && d[k]>d[u]+num[v]){
                d[k]=d[u]+num[v];
                update(k);
            }
        }
    }
    keepresult(3);
}

void duyet(const int i){
    if (i>7){solve(); return;}
    for (int j=0;j<=1;j++){mark[i]=j; duyet(i+1);}
}

int main(){
    freopen("test.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>n;
    while (n){
        for (int i=0; i<n;i++) cin>>num[i];
        for (int i=0; i<n;i++) for (int j=0; j<n;j++) cin>>a[i][j];
        res=oo; memset(mark,false,sizeof(mark)); mark[1]=true;
        duyet(2);
        if (res!=oo) cout<<res; else cout<<-1; cout<<endl;
        cin>>n;        
    }
    return 0;
}

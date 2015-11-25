#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <string.h>
#define maxn 100007
#define oo 1000000007

using namespace std;
struct node{
      int v,w;
      node* next;
      }* a[maxn];

int n,k,minedge[maxn];
long long res;

bool free1[maxn], mark[maxn];  

void push(int u, int v, int w)
{
     node* t = new node;
     t->v = v;
     t->w = w;
     t->next = a[u];
     a[u]=t;
}
         
void dfs(int u){
    free1[u]=false;
    long long sum=0;
    int maxv=0,count=0;
    node* t = a[u];
    while (t!=NULL){
        if (free1[t->v]){
            dfs(t->v);
            if (minedge[t->v]!=0){
                count++;
                minedge[t->v]=min(minedge[t->v],t->w);
                if (maxv<minedge[t->v]) maxv=maxv=minedge[t->v];
                sum+=minedge[t->v];
            }
        }
        t=t->next;
    }
    if (mark[u]){
        minedge[u]=oo;
        res+=sum;
    }
    else if (count>0){
        minedge[u]=maxv;
        res+=sum-maxv;
    }
    else minedge[u]=0;
}

int main(){
        freopen("test.txt","r",stdin);
        freopen("out.txt","w",stdout);
        cin >> n >> k;
        
        for (int i=1; i<=n;i++){
            a[i]=new node;
            a[i]=NULL;
        }
        
        for (int i=1; i<n;i++){
            int u,v,w;
            cin >> u >> v >> w;
            push(u,v,w); push(v,u,w);
        }       
        
        memset(mark,false,sizeof(mark));
        memset(free1,true,sizeof(free1));
        
        for (int i=1; i<=k; i++){ int u; cin >> u; mark[u]=true;}     
        
        res=0;
        dfs(2);
        cout << res;
        return 0;
}

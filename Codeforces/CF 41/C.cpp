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

int a[10];
int d[11][11][11][11];
struct node{
    int a[6];
    node(){};
    node(int a1, int a2, int a3, int a4){
        a[1]=a1;
        a[2]=a2;
        a[3]=a3;
        a[4]=a4;
    }
};
queue<node> myq;

int bigpos(){
    int u=-1;
    FOR(i,1,4) if(a[i]>10 && (u==-1 || a[i]>a[u])) u=i;
    return u;
}

void div(int pos){
    if(pos==0) pos=4;
    if(pos==5) pos=1;
    printf("/%d\n",pos);
    //FOR(i,1,4) cout<<a[i]<<' '; cout<<" => ";
    a[pos]/=2;
    if(pos<4) a[pos+1]/=2; else a[1]/=2;
    //FOR(i,1,4) cout<<a[i]<<' '; cout<<endl;
}

void Plus(int pos){
    if(pos==0) pos=4;
    if(pos==5) pos=1;
    printf("+%d\n",pos);
    //FOR(i,1,4) cout<<a[i]<<' '; cout<<" => ";
    a[pos]++;
    if(pos<4) a[pos+1]++; else a[1]++;
    //FOR(i,1,4) cout<<a[i]<<' '; cout<<endl;
}

bool ok(node t){
    FOR(i,1,4) if(t.a[i]>10 || t.a[i]<1) return 0;
    return d[t.a[1]][t.a[2]][t.a[3]][t.a[4]]==0;
}

void DoPlus(node &t, int pos){
    t.a[pos]--;
    if(pos<4) t.a[pos+1]--;
    else t.a[1]--;
}

void DoDiv(node &t, int pos){
    t.a[pos]*=2;
    if(pos<4) t.a[pos+1]*=2;
    else t.a[1]*=2;
}

void init(){
    reset(d,0);
    d[1][1][1][1]=7;
    myq.push(node(1,1,1,1));
    node u,v;
    while(!myq.empty()){
        u=myq.front(); myq.pop();
        u.a[5]=u.a[1];
        FOR(i,1,4){
            v=u;
            DoPlus(v,i);
            if(ok(v)){
                d[v.a[1]][v.a[2]][v.a[3]][v.a[4]]=i;
                myq.push(v);
            }
            v=u;
            DoDiv(v,i);
            if(ok(v)){
                d[v.a[1]][v.a[2]][v.a[3]][v.a[4]]=-i;
                myq.push(v);
            }
        }
    }
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    init();
    
    FOR(i,1,4) cin>>a[i];
    int p;
    while((p=bigpos())!=-1){
        a[0]=a[4]; a[5]=a[1];
        if(a[p]%2==0){
            if(a[p-1]%2==0 && a[p+1]%2==0){
                if(a[p-1]>a[p+1]) div(p-1); else div(p);
            }else if(a[p-1]%2==0) div(p-1);
            else if(a[p+1]%2==0) div(p);
            else if(a[p-1]>a[p+1]) Plus(p-1); else Plus(p);
        }else{
            if(a[p-1]&1 && a[p+1]&1){
                if(a[p-1]>a[p+1]) Plus(p-1); else Plus(p);
            }else if(a[p-1]&1) Plus(p-1);
            else if(a[p+1]&1) Plus(p);
            else if(a[p-1]>a[p+1]) Plus(p-1); else Plus(p);
        }
    }
    
    //FOR(i,1,4) cout<<a[i]<<' '; cout<<endl;
    while(a[1]!=1 || a[2]!=1 || a[3]!=1 || a[4]!=1){
        int v=d[a[1]][a[2]][a[3]][a[4]];
        if(v>0) Plus(v); else div(-v);
    }
    
    //getch();
    return 0;
}
                

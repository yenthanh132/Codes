#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#define lim 0.000001

using namespace std;

struct node{float v; int stt;} a[201];

int ds[201],c[201],p[201][201],n,m,cnt,mm;
double r[201],t[201];
bool free1[201];

bool done(){
    for(int i=0;i<n;i++) if (r[i]<0.90 && abs(r[i]-0.9)>lim)  return false;
    return true;
}

float value(int i){
    float v=0;
    for(int j=0;j<n;j++){
        t[j]=1-(1-r[j])*(1-(double)p[j][i]/100);
        if (r[j]<0.90 && abs(r[j]-0.9)>lim) v+=t[j]-r[j];
    }
    return v;
}

bool mycompare(node a,node b){ return (a.v>b.v); }

void init(){
    int i;
    mm=0;
    for(i=0;i<m;i++) if (free1[i]){
        a[++mm].v=value(i)/c[i];
        a[mm].stt=i;
    }
    sort(a+1,a+mm+1,mycompare);
}
    
void apply(int i){
    for(int j=0;j<n;j++) r[j]=1-(1-r[j])*(1-(double)p[j][i]/100);
}

void solve(){
    cnt=0; memset(free1,true,sizeof(free1));
    int i,j;
    for(i=0;i<n;i++) r[i]=0;
    while (!done()){
        init();
        ds[++cnt]=a[1].stt+1;
        apply(a[1].stt);
        free1[a[1].stt]=false;
    }
    sort(ds+1,ds+cnt+1);
    cout<<cnt<<endl;
    for(i=1;i<=cnt;i++) cout<<ds[i]<<' ';
    cout<<endl;
}
             
int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int test;
    cin>>test;
    for(int index=0;index<test;index++){
        cin>>n>>m;
        for(int i=0;i<m;i++) cin>>c[i];
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>p[i][j];
        solve();
    }
}

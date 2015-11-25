#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int g[50],d[50],sum;
bool free1[50];

void duyet(int i){
    int j;
    for (j=d[i-1]+1;j<=sum/2;j++){
        d[i]=j;
        sum-=j;
        duyet(i+1);
        sum+=j;
    }
    d[i]=sum; 
    if (i>1 && d[i]>d[i-1]){
        int v;
        v=g[d[1]];
        for (j=2; j<=i; j++)  v^=g[d[j]];
        free1[v]=false;
    }
}       

void buildgrundy(){
    g[0]=0; g[1]=0; g[2]=0;
    int i,j;
    for (i=3; i<=50; i++){
        memset(free1,true,sizeof(free1));
        sum=i; d[0]=0; duyet(1);
        for (j=0;(j<=50) && (!free1[j]);j++);
        g[i]=j;
    }
}

int main(){
    buildgrundy();
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        int n,grundy;
        cin >> n;
        grundy=0;
        for (int j=0; j<n; j++){int v; cin >> v; grundy^=g[v];}
        if (grundy!=0) cout << "ALICE\n"; else cout << "BOB\n";
    }
    return 0;
}

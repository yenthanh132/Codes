#include <iostream>
#include <stdio.h>
#include <string.h>
#include <deque>
#include <algorithm>
#define maxn 16001
#define maxk 101

using namespace std;

typedef pair<int,int> ii;

int n,k,f[maxn][maxk];
struct node{int s,l,p;}a[maxk];

bool mycmp(node a,node b){return (a.s<b.s);}

void optimize(){
    memset(f,0,sizeof(f));
    int i,j;
    deque<ii> q;
    for(i=1;i<=k;i++){
        q.clear();
        for (j=1;j<a[i].s;j++) f[j][i]=max(f[j-1][i],f[j][i-1]);
        for(j=max(a[i].s-a[i].l+1,1);j<=a[i].s;j++){
            while (q.size()>0 && f[j-1][i-1]+(a[i].s-j+1)*a[i].p>q.back().first) q.pop_back();
            q.push_back(ii(f[j-1][i-1]+(a[i].s-j+1)*a[i].p,j));
        }
        for(j=a[i].s;j<=min(a[i].s+a[i].l-1,n);j++){
            while (q.front().second<j-a[i].l+1) q.pop_front();
            f[j][i]=max(f[j][i-1],max(f[j-1][i],q.front().first+(j-a[i].s)*a[i].p));
        }
        for (j=a[i].s+a[i].l;j<=n;j++) f[j][i]=max(f[j-1][i],f[j][i-1]);
    }
}

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=k;i++) cin>>a[i].l>>a[i].p>>a[i].s;
    sort(a,a+k,mycmp);
    optimize();
    cout<<f[n][k];
}

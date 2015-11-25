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

struct point{
    int x,y,id;
    bool operator<(const point &a)const{
        return x<a.x || (x==a.x && y<a.y);
    }
} a[maxn],tmp[maxn];
int n,lab[maxn],cnt,C;

int getroot(int u){
    if(lab[u]<0) return u;
    lab[u]=getroot(lab[u]);
    return lab[u];
}

void dsu(int u, int v){
    int r1=getroot(u), r2=getroot(v);
    if(r1==r2) return;
    if(lab[r1]<lab[r2]){
        lab[r1]+=lab[r2];
        lab[r2]=r1;
    }else{
        lab[r2]+=lab[r1];
        lab[r1]=r2;
    }
    cnt--;
}

void mergesort(int l, int r){
    if(l>=r) return;
    int mid=(l+r)/2;
    int i=l, j=mid+1, p=l;
    mergesort(l,mid); mergesort(mid+1,r);
    deque<int> dl,dr;
    while(i<=mid || j<=r)
        if(j>r || (i<=mid && a[i].y<a[j].y)){
            while(!dr.empty() && a[i].y - C > a[dr.front()].y) dr.pop_front();
            if(!dr.empty() && a[i].x + C >= a[dr.front()].x) dsu(a[i].id,a[dr.front()].id);
            while(!dl.empty() && a[i].x >= a[dl.back()].x) dl.pop_back();
            dl.push_back(i);
            tmp[p++]=a[i++];
        }else{
            while(!dl.empty() && a[j].y - C > a[dl.front()].y) dl.pop_front();
            if(!dl.empty() && a[j].x - C <= a[dl.front()].x) dsu(a[j].id,a[dl.front()].id);
            while(!dr.empty() && a[j].x <= a[dr.back()].x) dr.pop_back();
            dr.push_back(j);
            tmp[p++]=a[j++];
        }
    FOR(x,l,r) a[x]=tmp[x];
}
 
//#include <conio.h>                      
int main(){
    //freopen("test.txt","r",stdin);
    int x,y;
    scanf("%d%d",&n,&C);
    FOR(i,1,n){
        scanf("%d%d",&x,&y);
        a[i].x=x+y;
        a[i].y=x-y;
        a[i].id=i;
    }
    sort(a+1,a+n+1);
    fill(lab+1,lab+n+1,-1);
    cnt=n;
    mergesort(1,n);
    int maxv=0;
    FOR(i,1,n) maxv=max(maxv,-lab[i]);
    cout<<cnt<<' '<<maxv<<endl;
    
    //getch();
    return 0;
}

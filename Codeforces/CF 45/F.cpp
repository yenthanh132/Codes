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

const int maxn=500007;

int n,m,W;
ll w[maxn],sumw[maxn],sums[maxn];
int c[maxn],a[maxn],s[maxn];
int id[maxn];
ll need;

ll res=0;
double res2=0;

bool cmp(const int &i, const int &j){
    return w[i]*s[j]>w[j]*s[i];   
}

void add(int i){
    if(need>w[i]) res+=s[i], need-=w[i];
    else{
        res+=(s[i]*need)/w[i];
        res2+=double((s[i]*need)%w[i])/w[i];
        need=0;
    }    
}

void qsort(int l, int r){
    if(need==0 || l>r) return;
    if(l==r){
        add(id[l]);
        return;
    }
    sumw[l-1]=sums[l-1]=0;
    FOR(z,l,r){
        sumw[z]=sumw[z-1]+w[id[z]];       
        sums[z]=sums[z-1]+s[id[z]];
    }
    if(sumw[r]<=need){
        need-=sumw[r];
        res+=sums[r];
        return;
    }
                
    int i=l, j=r;
    int k=id[(l+r)/2];
    do{
        while(cmp(id[i],k)) ++i;
        while(cmp(k,id[j])) --j;
        if(i<=j){
            if(i<j) swap(id[i],id[j]);
            ++i;
            --j;
        }
    }while(i<=j);   
    qsort(l,j); if(j+1<i) add(id[j+1]); qsort(i,r);
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);    
    scanf("%d%d%d",&n,&m,&W);
    FOR(i,1,m) scanf("%d",&w[i]);
    FOR(i,1,m) scanf("%d",&c[i]);
    FOR(i,1,m) scanf("%d",&a[i]);
    FOR(i,1,m) s[i]=c[i];
    FOR(i,1,m) id[i]=i;
    FOR(i,1,n){
        need=W;
        qsort(1,m);             
        res+=int(res2);
        res2-=int(res2);
        FOR(i,1,m) s[i]-=a[i];
    }
    char buf[20];
    sprintf(buf,"%0.20lf",res2);
    printf("%I64d%s\n",res,buf+1);
    //getch();
    return 0;
}

    

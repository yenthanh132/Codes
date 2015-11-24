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

int n,m;
ll p[maxn][7],s[maxn][7],a[maxn],IT[maxn*4][6];
int IT2[maxn*4];
char buf[5];

void initIT(int i, int l, int r){
    IT2[i]=-1;
    if(l==r){
        FOR(j,0,5) IT[i][j]=(a[l]*p[l][j])%oo;
        return;
    }
    int mid=(l+r)>>1;
    initIT(i*2,l,mid); initIT(i*2+1,mid+1,r);
    FOR(j,0,5) IT[i][j]=(IT[i*2][j]+IT[i*2+1][j])%oo;
}

void lazyupdate(int& i, int& l, int& r){
    if(IT2[i]==-1) return;
    if(l<r) IT2[i*2]=IT2[i*2+1]=IT2[i];
    FOR(j,0,5) IT[i][j]=(IT2[i]*(s[r][j]-s[l-1][j]+oo))%oo;
    IT2[i]=-1;
}

void updateIT(int i, int l, int r, int& s, int& f, int& v){
    lazyupdate(i,l,r);
    if(r<s || l>f) return;
    if(s<=l && r<=f){
        IT2[i]=v;
        lazyupdate(i,l,r);
        return;
    }
    int mid=(l+r)>>1;
    updateIT(i*2,l,mid,s,f,v); updateIT(i*2+1,mid+1,r,s,f,v);
    FOR(j,0,5) IT[i][j]=(IT[i*2][j]+IT[i*2+1][j])%oo;
}

ll getIT(int i, int l, int r, int& s, int& f, int& k){
    lazyupdate(i,l,r);
    if(r<s || l>f) return 0;
    if(s<=l && r<=f){
        int L=s-1;
        if(k==0) return IT[i][0];
        if(k==1) return (IT[i][1]-p[L][1]*IT[i][0]+oo)%oo;
        if(k==2) return (IT[i][2]-2*p[L][1]%oo*IT[i][1]+p[L][2]*IT[i][0]+oo)%oo;
        if(k==3) return (IT[i][3]-3*p[L][1]%oo*IT[i][2]+3*p[L][2]%oo*IT[i][1]-p[L][3]*IT[i][0]+oo)%oo;
        if(k==4) return (IT[i][4]-4*p[L][1]%oo*IT[i][3]+6*p[L][2]%oo*IT[i][2]-4*p[L][3]%oo*IT[i][1]+p[L][4]*IT[i][0]+oo)%oo;
        if(k==5) return (IT[i][5]-5*p[L][1]%oo*IT[i][4]+10*p[L][2]%oo*IT[i][3]-10*p[L][3]%oo*IT[i][2]+5*p[L][4]%oo*IT[i][1]-p[L][5]*IT[i][0]+oo)%oo;
    }
    int mid=(l+r)>>1;
    return (getIT(i*2,l,mid,s,f,k)+getIT(i*2+1,mid+1,r,s,f,k))%oo;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%I64d",&a[i]);
    
    FOR(i,1,n){
        p[i][0]=1; 
        FOR(j,1,5) p[i][j]=(p[i][j-1]*i)%oo;
        FOR(j,0,5) s[i][j]=(s[i-1][j]+p[i][j])%oo;
    }
    initIT(1,1,n);
    int x,y,z;
    FOR(i,1,m){
        scanf("%s%d%d%d",buf,&x,&y,&z);
        if(buf[0]=='=') updateIT(1,1,n,x,y,z);
        else printf("%d\n",(getIT(1,1,n,x,y,z)+oo)%oo);
    }
    
    //getch();
    return 0;
}

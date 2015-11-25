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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii,int> iii;

#define maxn 100001

struct nodeIT{int quad[4]; bool rX, rY;} IT[maxn*4];
pii point[maxn];
int n,q;

int goc(int x, int y){
    if(x>0 && y>0) return 0;
    else if(x<0 && y>0) return 1;
    else if(x<0 && y<0) return 2;
    else return 3;
}

void initIT(int i, int l, int r){
    if(l==r){
        IT[i].quad[goc(point[l].fi,point[l].se)]=1;
        return;
    }
    int mid=(l+r)/2;
    initIT(i*2,l,mid); initIT(i*2+1,mid+1,r);
    REP(j,4) IT[i].quad[j]=IT[i*2].quad[j]+IT[i*2+1].quad[j];
}

void lazyupdate(int i, int l, int r){
    if(IT[i].rX){
        swap(IT[i].quad[0],IT[i].quad[3]);
        swap(IT[i].quad[1],IT[i].quad[2]);
        IT[i].rX=0;
        if(l<r){
            IT[i*2].rX=!IT[i*2].rX;
            IT[i*2+1].rX=!IT[i*2+1].rX;
        }
    }
    if(IT[i].rY){
        swap(IT[i].quad[0],IT[i].quad[1]);
        swap(IT[i].quad[2],IT[i].quad[3]);
        IT[i].rY=0;
        if(l<r){
            IT[i*2].rY=!IT[i*2].rY;
            IT[i*2+1].rY=!IT[i*2+1].rY;
        }
    }
}

void Reflect(int i, int l, int r,const int &s,const int &f,const int &v){
    lazyupdate(i,l,r);
    if(r<s || l>f) return;
    if(s<=l && r<=f){
        if(v==1) IT[i].rX = !IT[i].rX; else IT[i].rY=!IT[i].rY;
        lazyupdate(i,l,r);
        return;
    }
    int mid=(l+r)/2;
    Reflect(i*2,l,mid,s,f,v); Reflect(i*2+1,mid+1,r,s,f,v);
    REP(j,4) IT[i].quad[j]=IT[i*2].quad[j]+IT[i*2+1].quad[j];
}

int quadres[4];
void GetIT(int i, int l, int r, const int &s, const int &f){
    lazyupdate(i,l,r);
    if(r<s || l>f) return;
    if(s<=l && r<=f){
        REP(j,4) quadres[j]+=IT[i].quad[j];
        return;
    }
    int mid=(l+r)/2;
    GetIT(i*2,l,mid,s,f); GetIT(i*2+1,mid+1,r,s,f);
    REP(j,4) IT[i].quad[j]=IT[i*2].quad[j]+IT[i*2+1].quad[j];
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d\n",&n);
    FOR(i,1,n) scanf("%d%d\n",&point[i].fi,&point[i].se);
    initIT(1,1,n);
    scanf("%d\n",&q);
    char ch; 
    int s,f,v;
    REP(i,q){
        scanf("%c%d%d\n",&ch,&s,&f);
        if(ch=='C'){
            reset(quadres,0);
            GetIT(1,1,n,s,f);
            printf("%d %d %d %d\n",quadres[0],quadres[1],quadres[2],quadres[3]);
        }else{
            v=(ch=='X')?1:2;
            Reflect(1,1,n,s,f,v);
        }
    }
    //getch();
    return 0;
}
    
    

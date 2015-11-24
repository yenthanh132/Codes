#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;

int l,x,y,z,n;
int a[maxn];
bool foundX, foundY, foundZ;
set<int> mys;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d%d",&n,&l,&x,&y);
    z=x+y;
    foundX = foundY = foundZ = 0;
    int pz;
    for(int i=1; i<=n; ++i){
        scanf("%d",&a[i]);
        mys.insert(a[i]);
    }
    for(int i=1; i<=n; ++i){
        if(mys.find(a[i]-x)!=mys.end()) foundX=1;
        if(mys.find(a[i]-y)!=mys.end()) foundY=1;
        if(mys.find(a[i]-x-y)!=mys.end()){
            foundZ = 1;
            pz=a[i]-y;
        }
        if(mys.find(a[i]+(y-x))!=mys.end() && a[i]-x>=0){
            foundZ=1;
            pz=a[i]-x;
        }
        if(mys.find(a[i]-(y-x))!=mys.end() && a[i]+x<=l){
            foundZ=1;
            pz=a[i]+x;
        }
    }

    if(foundX && foundY){
        puts("0");
    }else if(foundX || foundY){
        puts("1");
        if(foundX) printf("%d",y);
        else printf("%d",x);
    }else if(foundZ){
        puts("1");
        printf("%d",pz);
    }else{
        puts("2");
        printf("%d %d",x,y);
    }

    return 0;

}


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

const int maxn=200007;

int list[maxn],a[maxn],n,m,cnt,d,pos[maxn];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int dis=0,x,k,v,left,right,mid,ans;
    cnt=0;
    FOR(i,1,n){
        scanf("%d%d",&x,&k);
        FOR(j,1,k) scanf("%d",&list[j]), list[j]-=dis;
        sort(list+1,list+k+1);
        FOR(j,1,k) if(list[j]>=0) a[++cnt]=list[j];
        dis+=x;
    }
    int res=oo,maxval=-1;
    pos[d=1]=1;
    FOR(i,2,cnt){
        if(a[i]>=a[pos[d]]){
            d++;
            pos[d]=i;
        }else if(a[i]<a[pos[1]]) pos[1]=i;
        else{
            left=1; right=d;
            while(left<=right){
                mid=(left+right)>>1;
                if(a[pos[mid]]<=a[i]){
                    ans=mid+1;
                    left=mid+1;
                }else right=mid-1;
            }
            pos[ans]=i;
        }
        if(d>=m) x=m; else x=d;
        if(maxval<x){
            maxval=x;
            res=a[pos[x]]+dis;
        }else if(maxval==x)
            res=min(res,a[pos[x]]+dis);
    }
    printf("%d\n",res);
    //getch();
    return 0;
}
            
        
    

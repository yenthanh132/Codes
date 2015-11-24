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

int x[maxn],n;
double pos[4];

bool check(int len){
    int i=1;
    REP(step,3){
        int j=i;
        while(j<n && x[j+1]-x[i]<=len) j++;
        pos[step]=1.0*(x[j]+x[i])/2;   
        i=j+1;
        if(i>n){
            FOR(k,step+1,2) pos[k]=pos[k-1];
            break;   
        }
    }
    if(i>n) return 1;
    else return 0;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&x[i]);
    sort(x+1,x+n+1);
    
    int l,r,mid,res;
    if(!check(0)){
        l=1; r=1000000000;
        while(l<=r){
            mid=(l+r)/2;
            if(check(mid)){
                r=mid-1;   
                res=mid;
            }
            else l=mid+1;
        }
    }else res=0;
    check(res);
    printf("%0.6lf\n%0.6lf %0.6lf %0.6lf\n",1.0*res/2,pos[0],pos[1],pos[2]);
    
    //getch();
    return 0;
}

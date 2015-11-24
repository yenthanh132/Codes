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

int d[maxn],a[maxn],n,m;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    d[m=1]=a[1];
    FOR(i,2,n)
        if(a[i]<d[1]) d[1]=a[i];
        else if(a[i]>d[m]) d[++m]=a[i];
        else{
            int l=1, r=m, mid,res;
            while(l<=r){
                mid=(l+r)/2;
                if(a[i]<d[mid]){
                    res=mid;
                    r=mid-1;
                }else l=mid+1;
            }
            d[res]=a[i];
        }
    cout<<m<<endl;
    //getch();
    return 0;
}

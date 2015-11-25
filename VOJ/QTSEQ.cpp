#include <iostream>
#include <algorithm>
#include <cstdio>
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

#define maxn 1000005

int i,n,a[maxn],minc,maxc;
double sum1,sum2,mins,maxs,res=-1000000000000000007ll,resc;

inline double myabs(double a){return(a<0?-a:a);}

inline void update_max(double& a,double& b,double c, double d){
    if (a<c){
        a=c;
        b=d;
    }else if(a==c) b+=d;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d\n",&n);
    for(i=1;i<=n;i++) scanf("%d",a+i);
    for(i=2, sum2=0;i<=n;i++) sum2+=a[i];
    sum1=mins=maxs=a[1]; minc=maxc=1;
    for(i=2;i<=n;i++){
        update_max(res,resc,myabs(sum2-mins),minc);
        if (maxs!=mins) update_max(res,resc,myabs(sum2-maxs),maxc);
        sum1+=a[i];
        sum2-=a[i];
        if (mins>sum1) mins=sum1, minc=1; else if (mins==sum1) minc++;
        if (maxs<sum1) maxs=sum1, maxc=1; else if (maxs==sum1) maxc++;
    }
    cout<<ll(res)<<" "<<ll(resc)<<endl;
    //getch();
    return 0;
}

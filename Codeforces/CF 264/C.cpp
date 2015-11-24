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
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=2007;

int a[maxn][maxn],n;
ll sum1[maxn*2],sum2[maxn*2];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j){
        scanf("%d",&a[i][j]);
        sum1[i+j]+=a[i][j];
        sum2[i-j+n]+=a[i][j];
    }
    ll res1 = -1, res2=-1;
    int x1,y1,x2,y2;
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j){
        if((i+j)%2==0){
            if(res1 < sum1[i+j] + sum2[i-j+n] - a[i][j]){
                res1 = sum1[i+j] + sum2[i-j+n] - a[i][j];
                x1=i; y1=j;
            }
        }else{
            if(res2 < sum1[i+j] + sum2[i-j+n] - a[i][j]){
                res2 = sum1[i+j] + sum2[i-j+n] - a[i][j];
                x2=i; y2=j;
            }
        }
    }
    cout<<res1+res2<<endl;
    cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
    return 0;
}

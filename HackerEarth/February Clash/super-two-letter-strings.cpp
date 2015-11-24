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
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int f[2][10001],n,t,p;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&p);
        f[0][0]=1;
        for(int i=1; i<=n; ++i){
            f[0][i]=(f[0][i-1]+f[1][i-1])%oo;
            f[1][i]=0;
            for(int j=1; j<p; ++j) if(i-j>0) f[1][i] = (f[1][i] + f[0][i-j])%oo;
        }
        printf("%d\n",(f[0][n]+f[1][n])%oo);
    }
}


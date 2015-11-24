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

const int maxn=1111;

int a[maxn][maxn],n,k,d;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&k,&d);
    int val = 1;
    for(int i=0; i<d; ++i){
        val*=k;
        if(val>=n) break;
    }
    if(val<n){
        puts("-1");
        return 0;
    }

    for(int i=0; i<n; ++i){
        int v = i;
        for(int j=0; j<d; ++j) a[j][i]=v%k, v/=k;
    }
    for(int i=0; i<d; ++i){
        for(int j=0; j<n; ++j) printf("%d ",a[i][j]+1);
        puts("");
    }
    return 0;
}

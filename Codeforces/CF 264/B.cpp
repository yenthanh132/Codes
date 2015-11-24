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

const int maxn=100007;

int a[maxn],n;

bool check(int v){
    for(int i=1; i<=n; ++i){
        v-=a[i]-a[i-1];
        if(v<0) return 0;
    }
    return 1;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i){
        scanf("%d",&a[i]);
    }
    int l=0, r=oo, mid, res=oo;
    while(l<=r){
        mid = (l+r)/2;
        if(check(mid)){
            res= mid;
            r=mid-1;
        }else l=mid+1;
    }
    cout<<res<<endl;
}

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

int n,m,k,a[1007];


int main(){
    //freopen("input.txt","r",stdin);
    cin>>n>>m>>k;
    for(int i=1; i<=m+1; ++i) cin>>a[i];
    int res=0;
    for(int i=1; i<=m; ++i){
        int c=0;
        for(int j=0; j<n; ++j) c+=(a[i]>>j&1)^(a[m+1]>>j&1);
        if(c<=k) ++res;
    }
    cout<<res<<endl;
}

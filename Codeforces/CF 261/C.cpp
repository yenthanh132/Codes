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

const int maxn=1007;

int arr[maxn][maxn];

int main(){
    int n,k,d;
    cin>>n>>k>>d;
    reset(arr,0);
    ll cnt = 1;
    for(int i=0; i<d; ++i){
        cnt*=k;
        if(cnt>=n) break;
    }
    if(cnt<n){
        puts("-1");
        return 0;
    }

    for(int i=1; i<=n; ++i){
        int v=i-1;
        for(int j=1; j<=d; ++j){
            arr[i][j]=v%k;
            v/=k;
        }
    }
    for(int j=1; j<=d; ++j){
        for(int i=1; i<=n; ++i) printf("%d ",arr[i][j]+1);
        puts("");
    }

    return 0;
}

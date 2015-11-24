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
typedef unsigned long long ll;

const int maxn=2007;

ll f[maxn][(maxn>>6)+1];
ll one=1;
int n;
char s[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i){
        scanf("%s",s+1);
        for(int j=1; j<=n; ++j) if(s[j]=='1') f[i][j>>6] |= one<<(j&63);
    }

    int res=0;
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(i!=j)
        if(!(f[i][j>>6] & (one<<(j&63)))){
            for(int k=0; k <= (n>>6); ++k)
                if(f[i][k]&f[j][k]){
                    ++res;
                    break;
                }
        }
    cout<<res<<endl;
    return 0;
}

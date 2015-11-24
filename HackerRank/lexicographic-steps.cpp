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

int T,m,n,k;
int C[22][22];
char s[22];

int main(){
    //freopen("input.txt","r",stdin);

    C[0][0]=1;
    for(int i=1; i<=20; ++i){
        C[i][0]=1;
        for(int j=1; j<=i; ++j) C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    scanf("%d",&T);
    for(int tt=0; tt<T; ++tt){
        scanf("%d%d%d",&m,&n,&k);
        for(int i=1; i<=m+n; ++i) s[i]='H';
        for(int r=n-1; r>=0; --r){
            int v = 0;
            for(int i=r+1; i<=m+n; ++i){
                v = C[i-1][r];
                if(v<=k){
                    k-=v;
                }else{
                    s[i]='V';
                    break;
                }
            }
        }
        for(int i=m+n; i>=1; --i) putchar(s[i]); puts("");
    }
    return 0;
}


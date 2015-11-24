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

using namespace std;

const int maxn=57;

int y[maxn],n,T;
double c[maxn][maxn];
double frac[maxn];

int main(){
    //freopen("input.txt","r",stdin);

    c[0][0]=1;
    for(int i=1; i<=50; ++i){
        c[i][0]=1;
        for(int j=1; j<=i; ++j) c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
    frac[0]=1;
    for(int i=1; i<=50; ++i) frac[i]=frac[i-1]*i;

    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) scanf("%d",&y[i]);
        sort(y+1,y+n+1);
        double res=0;
        int cnt=0;
        for(int i=1; i<=n; ++i){
            while(y[cnt+1]<y[i]) ++cnt;
            for(int v=0; v<=cnt; ++v){
                int left = n - cnt - 1;
                double tmp ;
                if(left>0){
                    tmp = c[cnt][v] * frac[v] * (v+1) * (n-(v+2) + 1) * left * frac[n-(v+2)];
                    tmp += c[cnt][v] * frac[v] * (v+1) * frac[n-(v+1)];
                    res+=tmp/frac[n];
                }else{
                    tmp = c[cnt][v] * frac[v] * (v+1) * frac[n-(v+1)];
                    res+=tmp/frac[n];
                }
            }
        }
        printf("%0.2lf\n",res);
    }

    return 0;
}

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

int main(){
    //freopen("input.txt","r",stdin);
    double X,Y,r;
    int Xt,Yt;
    double rt;
    int N;
    while(scanf("%d%d%d%lf",&Xt,&Yt,&N,&rt)!=EOF,Xt>0){

        r=rt/100/12+1;

        X=Xt; Y=Yt;
        N*=12;

        if(r==1){
            if(X-Y*N<=1e-8) puts("YES"); else puts("NO");
            continue;
        }

        if(N<=24){
            for(int i=0; i<N; ++i) X=X*r-Y;
            if(X<=1e-8) puts("YES"); else puts("NO");
            continue;
        }

        double val = X*pow(r,N) - Y*(pow(r,N)-1)/(r-1);
        if(val<=1e-8) puts("YES"); else puts("NO");
    }
    return 0;
}

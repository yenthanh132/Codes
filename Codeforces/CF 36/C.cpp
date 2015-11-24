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
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=3007;
const double eps=1e-9;
int n;
double h[maxn],r[maxn],R[maxn],base[maxn];

bool equal(double a, double b){
    return fabs(a-b)<eps;
}

double geth(int i, int j){
    double len1,len2,h1,h2;
    len1=(R[j]-r[j])/2;
    len2=(R[i]-r[i])/2;
    h1=h[j]; h2=h[i];
    double res=base[j];
        if(equal(r[i],R[j]) || r[i]>R[j]) res+=h[j];
        else if(equal(len1/h1,len2/h2)){
            if(r[i]>r[j]){
                res+=max(h[j]*(r[i]-r[j])/(R[j]-r[j]),0.0);
            }
        }else if(len1/h1<len2/h2){
            if(R[i]<=R[j]) res+=max(h[j]*(R[i]-r[j])/(R[j]-r[j])-h[i],0.0);
            else
            res+=max(h[j] - h[i]*(R[j]-r[i])/(R[i]-r[i]),0.0);   
        }else{
            if(r[i]>r[j]){
                res+=max(h[j]*(r[i]-r[j])/(R[j]-r[j]),0.0);
            }
        }
    return res;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    scanf("%d",&n);
    FOR(i,1,n) scanf("%lf%lf%lf",&h[i],&r[i],&R[i]);
    double res,len1,len2,h1,h2;
    base[1]=0;
    FOR(i,2,n){
        base[i]=0;
        FORD(j,i-1,1) base[i]=max(base[i],geth(i,j));
    }
    res=base[1]+h[1];
    FOR(i,2,n) res=max(res,base[i]+h[i]);
    printf("%0.12lf\n",res);
    return 0;
}
                
            

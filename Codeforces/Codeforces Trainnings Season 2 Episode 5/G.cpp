#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=107;

char s[maxn][maxn];
double x[maxn][maxn];
int h,w;

double calc(int c){
    reset(x,0);
    if(s[1][c]=='*') return 0;
    x[1][c]=1;
    double res = 0;
    for(int i=1; i<=h; ++i){
        for(int j=1; j<=w; ++j) if(x[i][j]>0){
            if('1'<=s[i][j] && s[i][j]<='9') res+=x[i][j]*(s[i][j]-'0');
            else if(i<h){
                if(s[i+1][j]=='*'){
                    if(j>1) x[i+1][j-1]+=x[i][j]/2;
                    if(j<w) x[i+1][j+1]+=x[i][j]/2;
                }else{
                    x[i+1][j]+=x[i][j];
                }
            }
        }
    }
    return res;
}

int main(){
    //freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&h,&w);
        for(int i=1; i<=h; ++i) scanf("%s",s[i]+1);
        double res= 0;
        for(int i=1; i<=w; ++i) res=max(res,calc(i));
        printf("%0.9lf\n",res);
    }
}


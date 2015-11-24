#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef vector< vector<double> > Matrix;

const int maxn=100007;

Matrix create(int m, int n){
    return vector< vector<double> > (m, vector<double>(n, 0) );
}

Matrix mul(Matrix a, Matrix b){
    int m=sz(a), n=sz(a[0]), p=sz(b[0]);
    Matrix c = create(m,p);
    for(int i=0; i<m; ++i) for(int j=0; j<p; ++j){
        c[i][j]=0;
        for(int k=0; k<n; ++k) c[i][j] += a[i][k]*b[k][j];
    }
    return c;
}

Matrix myPow(Matrix &base, int n){
    if(n==1) return base;
    Matrix t=myPow(base,n/2);
    t=mul(t,t);
    if(n&1) return mul(t,base);
    return t;
}

int n,k,T,len;
double ans[maxn];
char S[4],s[maxn][4];
set<int> mys;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        scanf("%s",S); len=strlen(S);
        Matrix arr = create(26,26);
        for(int i=0; i<26; ++i) for(int j=0; j<26; ++j) scanf("%lf",&arr[j][i]);
        for(int i=0; i<n; ++i) scanf("%s",s[i]), ans[i]=1;
        for(int j=0; j<len; ++j){
            Matrix x = create(26,1);
            x[S[j]-'a'][0]=1;
            Matrix ret = myPow(arr, k);
            x=mul(ret,x);
            for(int i=0; i<n; ++i){
                if(strlen(s[i])==len){
                    ans[i]*=x[s[i][j]-'a'][0];
                }
            }
        }
        mys.clear();
        double res = 0;
        for(int i=0; i<n; ++i)
            if(strlen(s[i])==len){
                int v=0;
                for(int j=0; j<len; ++j) v=v*26+s[i][j]-'a';
                if(mys.count(v)) continue;
                res += ans[i];
                mys.insert(v);
            }
        printf("%0.9f\n",res);
    }
}


#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) 1ll*(x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int x[5],y[5],a[5],b[5];
int n;

void rotate(int a, int b, int x, int y, int &X, int &Y){
    x-=a; y-=b;
    X=a-y;
    Y=b+x;
}

void rotate_k(int a, int b, int x, int y, int &X, int &Y, int r){
    X=x; Y=y;
    for(int i=0; i<r; ++i){
        rotate(a,b,x,y,X,Y);
        x=X; y=Y;
    }
}

bool check(int *i, int *j){
    vector<ll> d;
    for(int k=1; k<4; ++k) for(int k2=k+1; k2<=4; ++k2){
        d.pb(sqr(i[k]-i[k2])+sqr(j[k]-j[k2]));
    }
    sort(d.begin(), d.end());
    return (d[0]>0 && d[0]==d[3] && d[4]==d[5] && d[0]*2==d[5]);

}

int main(){
    //freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0; i<n; ++i){
        for(int j=1; j<=4; ++j) cin>>x[j]>>y[j]>>a[j]>>b[j];
        int res = oo;
        for(int r1=0; r1<4; ++r1) for(int r2=0; r2<4; ++r2) for(int r3=0; r3<4; ++r3) for(int r4=0; r4<4; ++r4){
            int i[5],j[5],r[5];
            r[1]=r1; r[2]=r2; r[3]=r3; r[4]=r4;
            for(int k=1; k<=4; ++k)
                rotate_k(a[k],b[k],x[k],y[k],i[k],j[k],r[k]);
            if(check(i,j)) res=min(res,r1+r2+r3+r4);
        }
        if(res==oo) res=-1;
        printf("%d\n",res);
    }
}


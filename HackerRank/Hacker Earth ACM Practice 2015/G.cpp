#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int T,n,k;

int C[2222][2222];

int main(){
    C[0][0]=1;
    for(int i=1; i<=2000; ++i){
        C[i][0]=1;
        for(int j=1; j<=i; ++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%oo;
    }

//    freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&k,&T);
    int sum=0;
    for(int i=0; i<k; ++i){
        int v;
        scanf("%d",&v);
        sum+=v;
    }

    int x=abs(T-sum);
    if(x>k || abs(k-x)%2==1){
        puts("0");
        return 0;
    }

    cout<<C[k][(k-x)/2]<<endl;
}


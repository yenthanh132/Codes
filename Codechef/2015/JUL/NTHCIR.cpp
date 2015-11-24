#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

double R[2111];

double calR(int N){
    if(N<=4) return R[N];
    double A = -2*R[1] + 2*R[2];
    double i = N;
    return R[4] + (i-4)*(R[4]-R[3]) + (i-4)*(i-3)/2 * A;
}

int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int T,N,P,M,B;
    cin>>T>>N>>P>>M>>B;
    for(int i=1; i<=4; ++i) cin>>R[i], R[i]=1/R[i];

    //Descartes 's theorem
    /*
        for(int i=5; i<=2000; ++i) R[i] = -2*R[1] + 2*R[2] + 2*R[i-1] - R[i-2];
        We have R[i] = A + 2*R[i-1] - R[i-2] ; A = -2*R[1] + 2*R[2]
            <=> (R[i] - R[i-1]) = A + (R[i-1] - R[i-2])
            <=> S[i] = A + S[i-1]
             => S[i] = A*(i-4) + S[4]
             => R[i] = R[i-1] + (i-4)*A + R[4]-R[3] = R[4] + (i-4)*(R[4]-R[3]) + (i-4)*(i-3)/2*A
    */

    double res = 0;
    while(T--){
        N = 1ll*P*N%M + B;
        res += 1/calR(N);
    }

    printf("%0.6f\n",res);

}


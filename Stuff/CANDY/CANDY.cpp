//#include <bits/stdc++.h>
//#define pb push_back
//#define sqr(x) (x)*(x)
//#define sz(a) int(a.size())
//#define reset(a,b) memset(a,b,sizeof(a))
//#define oo 1000000007
//
//using namespace std;
//
//typedef pair<int,int> pii;
//typedef long long ll;
//
//const int maxn=107;
//
//int dp[3][maxn][maxn];
//int dp2[maxn];
//string s;
//int T,n;
//
//int val(char s){
//    if(s=='D') return 0;
//    if(s=='X') return 1;
//    return 2;
//}
//
//bool f(int v, int l, int r){
//    if(l==r) return (val(s[l])==v);
//    if(dp[v][l][r]!=-1) return dp[v][l][r];
//    int &res = dp[v][l][r];
//    res=0;
//    for(int v1=0; v1<3; ++v1) if(v1!=v)
//        for(int v2=0; v2<3; ++v2) if(v2!=v && v2!=v1)
//            for(int k=l; k<r; ++k)
//                if(f(v1,l,k) && f(v2,k+1,r)){
//                    res=1;
//                    return 1;
//                }
//    return res;
//}
//
//bool can_reduce(int l, int r){
//    --l; --r;
//    return f(0,l,r) || f(1,l,r) || f(2,l,r);
//}
//
//int solve(){
//    reset(dp,-1);
//    dp2[0]=0;
//    for(int i=1; i<=n; ++i){
//        dp2[i]=oo;
//        for(int j=1; j<=i; ++j) if(can_reduce(j,i))
//            dp2[i]=min(dp2[i],dp2[j-1]+1);
//    }
//    return n-dp2[n];
//}
//
//int main(){
//    freopen("input.txt","r",stdin);
//    cin>>T;
//    while(T--){
//        cin>>n;
//        cin>>s;
//        cout<<solve()<<endl;
//    }
//}
//

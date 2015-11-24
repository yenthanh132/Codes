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
//const int maxn=5555;
//
//int n,v[maxn],p[maxn],d[maxn];
//
//int main(){
//    freopen("input.txt","r",stdin);
//    scanf("%d",&n);
//    for(int i=1; i<=n; ++i) scanf("%d%d%d",&v[i],&d[i],&p[i]);
//    vector<int> res,lst;
//    queue<int> myq;
//    for(int i=1; i<=n; ++i){
//        if(p[i]>=0){
//            while(!myq.empty()) myq.pop();
//            res.pb(i);
//            int val=v[i];
//            for(int j=i+1; j<=n && val>0; ++j) if(p[j]>=0){
//                p[j] -= val;
//                --val;
//                if(p[j]<0) myq.push(j);
//            }
//            while(!myq.empty()){
//                int u=myq.front(); myq.pop();
//                int val=d[u];
//                for(int j=u+1; j<=n; ++j) if(p[j]>=0){
//                    p[j] -= val;
//                    if(p[j]<0) myq.push(j);
//                }
//            }
//        }
//    }
//    printf("%d\n",sz(res));
//    for(int i=0; i<sz(res); ++i) printf("%d ",res[i]);
//}
//

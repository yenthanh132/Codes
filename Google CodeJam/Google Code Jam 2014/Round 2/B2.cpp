//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//#include <cstdlib>
//#include <vector>
//#include <cstring>
//#include <string>
//#include <cmath>
//#include <ctime>
//#include <utility>
//#include <map>
//#include <set>
//#include <queue>
//#include <stack>
//#include <sstream>
//#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
//#define FORD(a,b,c) for (int a=b;a>=c;a--)
//#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
//#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
//#define pb push_back
//#define mp make_pair
//#define fi first
//#define se second
//#define sz(a) int(a.size())
//#define reset(a,b) memset(a,b,sizeof(a))
//#define oo 1000000007
//
//using namespace std;
//
//typedef long long ll;
//typedef pair<int, int> pii;
//
//int a[11],n,t,per[11],res,b[11],v[11];
//
//bool ok(){
//FOR(i,1,n) v[i]=a[per[i]];
//    int i=1;
//    while(i+1<=n && v[i+1]>v[i]) ++i;
//    int j=n;
//    while(j-1>=1 && v[j-1]>=v[j]) --j;
//    return i==j;
//}
//
//int pos(int v){
//    FOR(i,1,n) if(b[i]==v) return i;
//}
//
//int dis(){
//FOR(i,1,n) b[i]=a[i];
//    int res=0;
//    FOR(i,1,n){
//        if(b[i]!=v[i]){
//            int p=pos(v[i]);
//            FORD(x,p-1,i){
//                swap(b[x],b[x+1]);
//                ++res;
//            }
//        }
//    }
//    return res;
//}
//
//int main(){
//freopen("input.txt","r",stdin);
////    freopen("B-small-attempt2.in","r",stdin);
////freopen("B-small-attempt2.out","w",stdout);
//    cin>>t;
//    FOR(tt,1,t){
//        cin>>n;
//        FOR(i,1,n) cin>>a[i];
//        FOR(i,1,n) per[i]=i;
//        int res=oo;
//        do{
//            if(ok()){
//                int va=dis();
//                if(va<res){
//                    FOR(i,1,n) cout<<b[i]<<' '; cout<<endl;
//                    }
//                res=min(res,va);
//
//            }
//        }while(next_permutation(per+1,per+n+1));
//        printf("Case #%d: %d\n",tt,res);
//    }
//}
//

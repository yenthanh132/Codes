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
//const int maxn=100007;
//
//int BIT[maxn];
//
//ll fac[maxn];
//
//void update(int i, int n, int v){
//    for( ; i<=n; i+=i&(-i)) BIT[i]+=v;
//}
//
//int get(int i){
//    int r=0;
//    for( ; i; i-=i&(-i)) r+=BIT[i];
//    return r;
//}
//
//ll getIndex(vector<int> a){
//    int n=sz(a);
//    for(int i=1; i<=n; ++i) BIT[i]=0;
//    ll res=0;
//    for(int i=1; i<=n; ++i){
//        int c=(a[i-1]-1) - get(a[i-1]-1);
//        res = (res + fac[n-i]*c)%oo;
//        update(a[i-1],n,1);
//    }
//    return res;
//}
//
//
//set< vector<int> > mys;
//
//vector<int> rotateVector(int i, int k, vector<int> &a){
//
//    vector<int> t;
//    for(int j=0; j<sz(a); ++j){
//        int pos=j;
//        if(i<=j && j<i+k){
//            if(j==i) pos=i+k-1;
//            else --pos;
//        }
//        t.pb(a[pos]);
//    }
//
//
//    return t;
//}
//
//queue< vector<int> > myq;
//
//int n,k;
//int main(){
//////test generator
//
////    freopen("input.txt","w",stdout);
////    int TT=100;
////    cout<<TT<<endl;
////    while(TT--){
////        int n=rand()%(5-2+1)+2;
////        int k=rand()%(n-2+1)+2;
////        cout<<n<<' '<<k<<endl;
////        int a[11];
////        for(int i=1; i<=n; ++i){
////            a[i]=i;
////        }
////        for(int i=1; i<n; ++i){
////            int u=rand()%n+1;
////            int v=rand()%n+1;
////            swap(a[u],a[v]);
////        }
////        for(int i=1; i<=n; ++i) cout<<a[i]<<' '; cout<<endl;
////        for(int i=1; i<=n; ++i){
////            a[i]=i;
////        }
////        for(int i=1; i<n; ++i){
////            int u=rand()%n+1;
////            int v=rand()%n+1;
////            swap(a[u],a[v]);
////        }
////        for(int i=1; i<=n; ++i) cout<<a[i]<<' '; cout<<endl;
////    }
////    return 0;
//////=======================
//
//    fac[0]=1;
//    for(int i=1; i<=100000; ++i) fac[i]=fac[i-1]*i%oo;
//
//    freopen("input.txt","r",stdin);
//    freopen("output2.txt","w",stdout);
//
//    int T;
//    cin>>T;
//    while(T--){
//        cin>>n>>k;
//        vector<int> t;
//        for(int i=0; i<n; ++i){
//            int v;
//            cin>>v;
//            t.pb(v);
//        }
//        vector<int> f;
//        for(int i=0; i<n; ++i){
//            int v;
//            cin>>v;
//            f.pb(v);
//        }
//        mys.clear();
//        mys.insert(t); myq.push(t);
//        while(!myq.empty()){
//            vector<int> u = myq.front(); myq.pop();
//            for(int i=0; i<=n-k; ++i){
//                vector<int> v = rotateVector(i,k,u);
//                if(mys.count(v)) continue;
//                mys.insert(v);
//                myq.push(v);
//            }
//        }
//
//
//        int idx=0;
//        bool found=0;
//        for(set< vector<int> >::iterator it = mys.begin(); it != mys.end(); ++it){
//            vector<int> t = *it;
////            for(int i=0; i<n; ++i) cout<<t[i]<<' '; cout<<": "<<idx<<" : "<<getIndex(t)<<endl;
//            ++idx;
//            if(t==f){
//                cout<<idx<<endl;
//                found=1;
//                break;
//            }
//        }
//        if(!found)
//            cout<<-1<<endl;
//    }
//}
//
//

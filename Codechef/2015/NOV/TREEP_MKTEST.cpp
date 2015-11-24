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
//double randf() {
//    double base = 0.1;
//    double res = 0;
//    for (int i = 0; i < 15; i++) {
//        res += base * (rand() % 10);
//        base /= 10;
//    }
//    return res;
//}
//
//int randi(int n) {
//    return (int)floor(randf() * n);
//}
//
//int top[111111];
//
//int main(){
//ios::sync_with_stdio(0);
//srand(time(NULL));
//    freopen("input.txt","w",stdout);
//    cout<<10<<endl;
//    for(int tt=1; tt<=10; ++tt){
//        int n=50000,q=50000;
//        cout<<n<<endl;
//        for(int i=1; i<=n-1; ++i){
//            if(rand()%10000==0)
//                top[i+1]=randi(i)+1;
//            else
//                top[i+1] = i;
//            cout<<top[i+1]<<' '<<i+1<<' '<<char(rand()%26 + 'a')<<endl;
//        }
//        cout<<q<<endl;
//        for(int i=1; i<=q; ++i){
//            int t=rand()%1;
//            if(t==0){
//                int u=randi(n)+1;
//                int v=randi(n)+1;
//                while(v==u) v=randi(n)+1;
//                cout<<1<<' '<<u<<' '<<v<<endl;
//            }else{
//                int u=randi(n)+1;
//                while(u==1) u=randi(n)+1;;
//                cout<<2<<' '<<u<<' '<<top[u]<<' '<<char(rand()%26 + 'a')<<endl;
//            }
//        }
//    }
//}
//

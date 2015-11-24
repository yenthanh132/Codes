#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define sz(a) int(a.size())
#define sqr(x) (x)*(x)
#define reset(a, b) memset(a, b, sizeof(a))
#define oo 1000000007

typedef pair<int, int> pii;
typedef long long ll;

const int base=73471;

ll getHash(vector<int> &v){
    ll res=0;
    for(int i=0; i<sz(v); ++i) res=res*base+v[i];
    return res;
}

vector< vector<int> > myq[2];
map<ll, double> dp[2];

double calculate(int n, double p){
    if(n==1) return 1;
    vector<int> t; t.pb(1);
    myq[0].pb(t);
    dp[0][getHash(t)]=1;
    int flag=0;
    for(int i=2; i<=n; ++i){
        flag^=1;
        myq[flag].clear();
        dp[flag].clear();
        for(int j = 0; j<sz(myq[flag^1]); ++j){
            vector<int> &d = myq[flag^1][j];
            double cur = dp[flag^1][getHash(d)];
            int c = sz(d);

            vector< vector<int> > myq_x[2];
            map<ll, double> dp_x[2];
            vector<int> t2; t2.pb(1);
            dp_x[0][getHash(t2)]=cur;
            myq_x[0].pb(t);
            int flag2=0;
            for(int x=0; x<c; ++x){
                flag2^=1;
                myq_x[flag2].clear();
                dp_x[flag2].clear();
                for(int y=0; y<sz(myq_x[flag2^1]); ++y){
                    vector<int> d_x = myq_x[flag2^1][y];
                    double cur_x = dp_x[flag2^1][getHash(d_x)];
                    double pp = pow(1-p,d[x]);
                    //choose x
                    d_x[0]+=d[x];
                    ll h=getHash(d_x);
                    if(!dp_x[flag2].count(h)){
                        dp_x[flag2][h] = cur_x * (1-pp);
                        myq_x[flag2].pb(d_x);
                    }else{
                        dp_x[flag2][h] += cur_x * (1-pp);
                    }

                    //not choose x
                    d_x[0]-=d[x];
                    d_x.pb(d[x]);
                    sort(d_x.begin()+1,d_x.end());
                    h=getHash(d_x);
                     if(!dp_x[flag2].count(h)){
                        dp_x[flag2][h] = cur_x * pp;
                        myq_x[flag2].pb(d_x);
                    }else{
                        dp_x[flag2][h] += cur_x * pp;
                    }
                }
            }
            for(int y=0; y<sz(myq_x[flag2]); ++y){
                vector<int> &d_x = myq_x[flag2][y];
                double cur_x = dp_x[flag2][getHash(d_x)];
                sort(d_x.begin(),d_x.end());
                ll h=getHash(d_x);
                if(!dp[flag].count(h)){
                    dp[flag][h] = cur_x;
                    myq[flag].pb(d_x);
                }else{
                    dp[flag][h] += cur_x;
                }
            }


//            for(int bit=0; bit < (1<<c); ++bit){
//                double res=cur;
//                vector<int> d2;
//                int sum=1;
//                for(int b=0; b<c; ++b){
//                    if(bit>>b&1){
//                        sum += d[b];
//                        res *= 1 - pow(1-p, d[b]);
//                    }else{
//                        d2.pb(d[b]);
//                        res *= pow(1-p, d[b]);
//                    }
//                }
//                d2.pb(sum);
//                sort(d2.begin(),d2.end());
//                ll h = getHash(d2);
//                if(!dp[flag].count(h)){
//                    dp[flag][h] = res;
//                    myq[flag].pb(d2);
//                }else{
//                    dp[flag][h] += res;
//                }
//            }
        }
    }
    t.clear();
    t.pb(n);
    return dp[flag][getHash(t)];
}

int main() {
//    freopen("input.txt", "r", stdin);
    int n;
    double p;
    cin>>n>>p;
    printf("%0.9f\n",calculate(n,p));
    return 0;
}


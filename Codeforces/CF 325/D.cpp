#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int n,c,state,c2;
int a[30][3],val[3];
map<pii,int> data, stateData;
int p3[15];

void update(pii &pv, int cost, int state){
    if(data.count(pv) && data[pv] < cost){
        data[pv] = max(data[pv], cost);
        stateData[pv] = state;
    }
    else{
        data[pv]=cost;
        stateData[pv]=state;
    }
}

void gen(int i){
    if(i>c){
        int cost = val[0];
        pii pv = pii(val[1]-val[0], val[2]-val[0]);
        update(pv,cost,state);
        return;
    }
    int cnt=0;
    for(int x=0; x<2; ++x) for(int y=x+1; y<3; ++y){
        state = state*3 + cnt++;
        val[x] += a[i][x];
        val[y] += a[i][y];
        gen(i+1);
        state /= 3;
        val[x] -= a[i][x];
        val[y] -= a[i][y];
    }
}

int best;
int rstate1,rstate2;

void cal(int i){
    if(i>c2){
        int cost = val[0];
        pii pv = pii(val[0]-val[1], val[0]-val[2]);
        if(data.count(pv)){
            int cost2 = data[pv];
            if(cost + cost2 > best){
                best = cost + cost2;
                rstate1 = stateData[pv];
                rstate2 = state;
            }
        }
        return;
    }
    int cnt=0;
    for(int x=0; x<2; ++x) for(int y=x+1; y<3; ++y){
        state = state*3 + cnt++;
        val[x] += a[i][x];
        val[y] += a[i][y];
        cal(i+1);
        state /= 3;
        val[x] -= a[i][x];
        val[y] -= a[i][y];
    }
}

string denote(int v){
    if(v==0) return "LM";
    if(v==1) return "LW";
    return "MW";
}

int main(){
//    freopen("input.txt","r",stdin);
    p3[0]=1;
    for(int i=1; i<15; ++i) p3[i]=p3[i-1]*3;
    cin>>n;
    c=n/2; c2=n-c;
    for(int i=1; i<=c; ++i) cin>>a[i][0]>>a[i][1]>>a[i][2];
    state=0;
    reset(val,0);
    gen(1);

    for(int i=1; i<=c2; ++i) cin>>a[i][0]>>a[i][1]>>a[i][2];

    state=0;
    best=-oo;
    reset(val,0);
    cal(1);

    if(best==-oo) cout<<"Impossible"<<endl;
    else{
        vector<string> ans;
        for(int i=0; i<c2; ++i){
            int v=rstate2%3;
            rstate2/=3;
            ans.pb(denote(v));
        }

        for(int i=0; i<c; ++i){
            int v=rstate1%3;
            rstate1/=3;
            ans.pb(denote(v));
        }

        for(int i=sz(ans)-1; i>=0; --i) cout<<ans[i]<<endl;
    }
}

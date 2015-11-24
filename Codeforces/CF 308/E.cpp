#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

vector<char> opr;
vector<ll> mys;
int prior(char ch){
    if(ch=='+') return 1;
    if(ch=='*') return 2;
    return 0;
}

void pushNum(ll num){
    mys.pb(num);
}

void pushOpr(char ch){
    ll b=mys.back(); mys.pop_back();
    ll a=mys.back(); mys.pop_back();
    if(ch=='+') mys.pb(a+b);
    else mys.pb(a*b);
}

ll cal(string s){
    mys.clear(); opr.clear();
    int n=sz(s);
    for(int i=0; i<n; ++i)
        if(s[i]=='(') opr.pb('(');
        else if(s[i]==')'){
            while(opr.back()!='('){
                pushOpr(opr.back());
                opr.pop_back();
            }
            opr.pop_back();
        }else if(s[i]=='+' || s[i]=='*'){
            while(!opr.empty() && prior(opr.back())>=prior(s[i])){
                pushOpr(opr.back());
                opr.pop_back();
            }
            opr.pb(s[i]);
        }else{
            pushNum(s[i]-'0');
        }


    while(!opr.empty()){
        pushOpr(opr.back());
        opr.pop_back();
    }
    return mys.back();
}

string data;
vector<int> posL, posR;

int main(){
//    freopen("input.txt","r",stdin);
    cin>>data;
    posL.pb(0); posR.pb(sz(data)-1);
    for(int i=1; i<sz(data); i+=2) if(data[i]=='*'){
        posR.pb(i-1); posL.pb(i+1);
    }
    ll res=cal(data);
    for(int i=0; i<sz(posL); ++i) for(int j=0; j<sz(posR); ++j){
        int x=posL[i], y=posR[j];
        if(x>y) continue;
        string sdata=data;
        sdata.insert(y+1,")");
        sdata.insert(x,"(");
//        cout<<sdata<<endl;
        res=max(res,cal(sdata));
    }
    cout<<res<<endl;
}


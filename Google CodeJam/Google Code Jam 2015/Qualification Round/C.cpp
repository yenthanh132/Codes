#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const string prod [4][4] = { {"1", "i", "j", "k"},
                             {"i","-1", "k","-j"},
                             {"j","-k","-1", "i"},
                             {"k", "j","-i","-1"} };

int id(string ch){
    if(ch=="1") return 0;
    if(ch=="i") return 1;
    if(ch=="j") return 2;
    return 3;
}

string mul(string a, string b){
    int sign=1;
    if(sz(a)>1){
        a.erase(0,1);
        sign*=-1;
    }
    if(sz(b)>1){
        b.erase(0,1);
        sign*=-1;
    }
    string res = prod[id(a)][id(b)];
    if(sign==-1){
        if(sz(res)==1) res="-"+res;
        else res.erase(0,1);
    }
    return res;
}

const int maxn=10007;
int T;
ll x,n,iLeft,iRight;
char s[maxn];
string all;

int main(){
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        scanf("%lld%lld",&n,&x);
        scanf("%s",s+1);
        all = "1";
        for(int i=1; i<=n; ++i) all = mul(all, string() + s[i]);
        string total = "1";
        for(int j=0; j<x%4; ++j) total = mul(total, all);
        bool res = 0;
        if(total=="-1"){
            iLeft=n*x+1;
            iRight=0;
            string val="1";
            for(int i=1; i<=n; ++i){
                val = mul(val, string() + s[i]);
                if(val=="i"){
                    iLeft=min(iLeft, i*1ll);
                }else{
                    string tmp = val;
                    for(int j=1; j<4; ++j){
                        tmp=mul(all,tmp);
                        if(tmp=="i"){
                            iLeft=min(iLeft,i+n*j);
                            break;
                        }
                    }
                }
            }

            val="1";
            for(int i=n; i>=1; --i){
                val = mul(string() + s[i], val);
                if(val=="k"){
                    iRight=max(iRight,i + n*(x-1));
                }else{
                    string tmp = val;
                    for(int j=1; j<4; ++j){
                        tmp = mul(tmp, all);
                        if(tmp=="k"){
                            iRight=max(iRight,i + n*(x-j-1));
                            break;
                        }
                    }
                }
            }

            if(iLeft<iRight){
                res = 1;
                //cout<<iLeft<<' '<<iRight<<endl;
            }
        }

        printf("Case #%d: ",tt);
        if(res) puts("YES");
        else puts("NO");
    }
}


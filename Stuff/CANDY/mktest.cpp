#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int T = 10;
const int minN = 100;
const int maxN = 100;
const int CLEN = 100;

int rint(int l, int r){
    return rand()%(r-l+1)+l;
}

string ch(int v){
    if(v==0) return "D";
    if(v==1) return "X";
    return "V";
}

int gen(int x){
    stringstream ss;
    ss<<x;
    string s = ss.str() + ".in";
    freopen(s.c_str(),"w",stdout);
    cout<<T<<endl;
    for(int i=1; i<=T; ++i){
        int n=rint(minN,maxN);
        cout<<n<<endl;
        int l=0;
        while(l<n){
            int left=n-l;
            int x=rint(1,CLEN);
            if(x>left) x=left;
            int v=rand()%3;
            for(int r=0; r<x; ++r){
                ++l;
                cout<<ch(v);
            }
        }
        cout<<endl;
    }
}

int main(){
    srand(time(NULL));
    for(int i=90; i<100; ++i) gen(i);

}

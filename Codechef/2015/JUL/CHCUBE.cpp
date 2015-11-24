#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

string s[7];
const int val[]={1,1,2,2,3,3};

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        for(int i=0; i<6; ++i) cin>>s[i];
        bool found=0;
        for(int i=0; i<6; ++i) for(int j=i+1; j<6; ++j) for(int k=j+1; k<6; ++k) if(val[i]!=val[j] && val[i]!=val[k] && val[j]!=val[k])
            if(s[i]==s[j] && s[j]==s[k])
                found=1;
        if(found) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}


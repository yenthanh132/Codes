#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

string S[3]={"qwertyuiop",
        "asdfghjkl;",
        "zxcvbnm,./"};

char shift(char ch, bool left){
    for(int i=0; i<3; ++i) for(int j=0; j<sz(S[i]); ++j) if(S[i][j]==ch) return (left?S[i][j-1]:S[i][j+1]);
}

int main(){
    //freopen("input.txt","r",stdin);

    string dir;
    cin>>dir;
    string val;
    cin>>val;
    for(int i=0; i<sz(val); ++i) val[i]=shift(val[i],dir=="R");
    cout<<val<<endl;
}

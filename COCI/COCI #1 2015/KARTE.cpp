#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

bool mark[4][13];

int get(char ch){
    if(ch=='P') return 0;
    if(ch=='K') return 1;
    if(ch=='H') return 2;
    return 3;
}

string s;

int main(){
//    freopen("input.txt","r",stdin);
    cin>>s;
    bool ok=1;
    reset(mark,0);
    for(int i=0; i<sz(s); i+=3){
        int x=get(s[i]);
        int y=(s[i+1]-'0')*10+s[i+2]-'0';
        --y;
        if(mark[x][y]){
            ok=0;
            break;
        }
        mark[x][y]=1;
    }
    if(!ok) cout<<"GRESKA"<<endl;
    else{
        for(int i=0; i<4; ++i){
            int c=13;
            for(int j=0; j<13; ++j) c-=mark[i][j];
            cout<<c<<' ';
        }
    }
}


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int cnt;
int cube[30][30][30];
int n;

int count1(int x,int z){
    int res=0;
    FOR(y,1,20) res+=cube[x][y][z];
    return res;   
}

int count2(int y, int z){
    int res=0;
    FOR(x,1,20) res+=cube[x][y][z];
    return res;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    int v;
    
    bool first=1;
    while(n){
        if(first)
            first=0;
        else cout<<endl<<endl;
        reset(cube,0);
        FOR(i,1,n){
            cnt=0;
            cin>>v;
            while(v){
                ++cnt;
                FOR(z,1,v) cube[i][cnt][z]=1;
                cin>>v;
            }
        }
    
        //left rotation
        FOR(z,1,20){
            if(count1(1,z)==0) break;
            FOR(x,1,20){
                v=count1(x,z);
                if(!v) break;
                if(x!=1) cout<<' ';
                cout<<v;
            }
            cout<<endl;
        }
        
        cout<<endl;
        
        //right rotation
        FOR(y,1,20){
            if(count2(y,1)==0) break;
            FOR(z,1,20){
                v=count2(y,z);
                if(!v) break;
                if(z!=1) cout<<' ';
                cout<<v;
            }
            cout<<endl;
        }
        cin>>n;
    }
        
    //getch();
    return 0;
}

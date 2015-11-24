#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

char arr[5][20];

int main(){
    int k;
    cin>>k;
    cout<<"+------------------------+"<<endl;
    for(int i=1; i<=4; ++i) for(int j=1; j<=11; ++j) arr[i][j]='#';
    for(int j=1; j<=11; ++j){
        if(j==1){
            for(int i=1; i<=4 && k>0; ++i){
                --k;
                arr[i][j]='O';
            }
        }else{
            for(int i=1; i<=3 && k>0; ++i){
                --k;
                arr[i][j]='O';
            }
        }
    }
    for(int i=1; i<=4; ++i){
        if(i!=3){
            int ii=i;
            if(ii>3) --ii;
            printf("|");
            for(int j=1; j<=11; ++j){
                if(j==1 && ii==3) printf("%c.",arr[4][1]);
                else printf("%c.",arr[ii][j]);
            }
            printf("|%c|",(i==1)?'D':'.');
            if(i==1 || i==4) printf(")");
        }else{
            printf("|%c.......................|",arr[3][1]);
        }
        puts("");
    }
    cout<<"+------------------------+";

}


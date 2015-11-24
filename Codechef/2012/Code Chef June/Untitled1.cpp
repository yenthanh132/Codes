/* Writen by Filip Hlasek 2012 */
#include <iostream>
#include <cstdio>

#include <cstdlib>

#include <vector>

#include <queue>

#include <stack>

#include <set>

#include <map>

#include <string>

#include <algorithm>

#include <cmath>

#include <cstring>

 

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)

#define FORD(i,a,b) for(int i=(a);i>=(b);i--)

#define REP(i,b) for(int i=0;i<b;i++)

 

using namespace std;

 

#define MOD 100000007

int power(int base, long long exponent){

  int result = 1, m = base;

  while(exponent){

    if(exponent&1) result = ((long long)result*m)%MOD;

    m = ((long long)m*m)%MOD;

    exponent /= 2;

  }

  return result;

}

 

int initTax,slot1,slot2,K,N;

int begin[111];

 

long long tmp[111][111];

int res[111][111], m[111][111];

 
#include <conio.h>
int main(int argc, char *argv[]){
    freopen("test.txt","r",stdin);

  int T;

  scanf("%d",&T);

  while(T--){

    scanf("%d%d%d%d%d",&initTax,&slot1,&slot2,&K,&N);

    begin[1] = initTax;

    int last = 1;

    REP(i,slot1){ begin[last+1] = (begin[last] + 1) % MOD; last++; } 

    REP(i,slot2){ begin[last+1] = (begin[last] * 2) % MOD; last++; }

    //FOR(i,1,last) printf("%d\n",begin[i]);

    if(N <= slot1 + slot2 + 1){ printf("%d\n",begin[N]); continue; }

    REP(i,K) REP(j,K) res[i][j] = (i == j);

    REP(i,K) REP(j,K) m[i][j] = ((i == j+1) || j == K-1);

    int exponent = N - (slot1 + slot2 + 1);

    while(exponent){

      if(exponent&1){

        REP(i,K) REP(j,K){

          tmp[i][j] = 0;

          REP(k,K) tmp[i][j] += (long long)res[i][k] * m[k][j];

        }

        REP(i,K) REP(j,K) res[i][j] = tmp[i][j] % (MOD - 1);

      }

      REP(i,K) REP(j,K){

        tmp[i][j] = 0;

        REP(k,K) tmp[i][j] += (long long)m[i][k] * m[k][j];

      }

      REP(i,K) REP(j,K) m[i][j] = tmp[i][j] % (MOD - 1);

      exponent /= 2;

    }

    /*

    REP(i,K){

      REP(j,K) printf(",%d",res[i][j]);

      printf("\n");

    }

    */

    int ans = 1;
    REP(i,K) cout<<res[i][K-1]<< " ";
    cout<<endl;
    REP(i,K) ans = ((long long)ans * power(begin[slot1+slot2+1-K+i+1],res[i][K-1])) % MOD;

    printf("%d\n",ans);

  }
getch();
  return 0;

}

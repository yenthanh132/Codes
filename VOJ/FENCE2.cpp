
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <complex>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

typedef long long int LL;
typedef complex<long long int> CL;
typedef long double LD;

#define MAX (305)

LD one = (LD)1.0;

int N;
CL arr[MAX]; //coordinates
int ind[MAX][2*MAX]; //sorted list of other coordinates around this point
int lkp[MAX][MAX]; //where in a list a given point occurs
int tar[MAX]; //dummy array for sorting

CL srt;

int dp[MAX][2*MAX];
bool mem[MAX][2*MAX];

int next[MAX][MAX];
/* pre-computed list of points
 * next[i][j] is the point that makes the smallest counter-clockwise angle with 
 * line IJ when measured about the point j
 */

bool ok(int i,int j,int k){ //returns true if k is strictly to the left of line IJ
	return imag(conj(arr[j]-arr[i])*(arr[k]-arr[i]))>0;
}

bool ok2(int i,int j){ //returns true if i has height at least that of j
	return imag(arr[j]) >= imag(arr[i]);
}

int nxt(int p3,int p2){
  //finds the next point after p2 (in counterclockwise order about p3)
	int ans = 0;
	while(ans<N-1&&ok(p2,p3,ind[p3][ans])) ans++;
	while(ans<2*N-2&&!ok(p2,p3,ind[p3][ans])) ans++;
	if(ans==2*N-2) return -1;
	else return ind[p3][ans];
}

bool opt=0;

int rec(int p1,int p2,int p3){
	if(p3==p1) return 2; //stop if we get back to our starting point
	if(mem[p2][p3]) return dp[p2][p3];
	int v1=ok2(p1,p3)?1+rec(p1,p3,next[p3][p2]):0;
	int v2=lkp[p2][p3]<2*N-3?rec(p1,p2,ind[p2][lkp[p2][p3]+1]):0;
	dp[p2][p3]=max(v1,v2);
	mem[p2][p3]=1;
	return dp[p2][p3];
}

inline LD f(CL z){
	return atan2(one*(imag(z)-imag(srt)),one*(real(z)-real(srt)));
  //compares based on the angle that z makes with respect the point we are
}

bool cmp(int i,int j){
	return f(arr[i]) < f(arr[j]);
}
int main(){
	//FILE *fout = fopen("","w");
    cin>>N;
	LL x,y;
	for(int i=0;i<N;i++){
		cin>>x>>y;
		arr[i]=CL(x,y);
	}

	for(int i=0;i<N;i++){
		srt = CL(real(arr[i]),imag(arr[i]));
		for(int j=0;j<i;j++) tar[j]=j;
		for(int j=i+1;j<N;j++) tar[j-1]=j;
		sort(tar,tar+(N-1),cmp); //sort the points based on angle about point i

    //fill in indexing and look-up tables
		for(int j=0;j<N-1;j++){
			ind[i][j]=tar[j];
			lkp[i][tar[j]]=j;
		}
		for(int j=N-1;j<2*N-2;j++)
			ind[i][j]=ind[i][j-N+1];
	}

  //pre-compute some more values we'll need
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)
		if(i!=j) next[i][j]=nxt(i,j);

	int best = 0;
	for(int i=2;i<N;i++){ //loop through all possible first two points
		for(int a=0;a<N;a++)
      for(int b=0;b<2*N;b++)
        mem[a][b]=0; //initialize memoization array
		
    for(int j=0;j<N;j++){
			if(i==j) continue;
			if(ok2(i,j)&&next[j][i]!=-1)
         /* check to see if we can actually build a convex polygon
          * starting with i and j that has I as the bottom point
          */
				best = max(best,rec(i,j,next[j][i]));
			
		}
	}

	printf("%d\n",best);
	return 0;
}

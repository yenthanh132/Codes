#pragma comment(linker,"/STACK:134217728")

 

#include <iostream>

#include <cstdio>

#include <vector>

#include <map>

#include <set>

#include <queue>

#include <algorithm>

#include <cstring>

#include <string>

using namespace std;

 

char s[100005];

int a[100005], c4[100005], c7[100005];

 #include <conio.h>

int main(){

 



	freopen("test.txt","r",stdin);

	//freopen("output.txt","w",stdout);

	

	int t;

	scanf("%d\n",&t);

 

	while (t--){

		gets(s);

		int n=strlen(s);

		a[n]=0;

		int ms=0;

		for (int i=n-1; i>=0; --i){

			int k=(s[i]=='4'?1:-1);

			ms=max(k,ms+k);

			a[i]=max(ms,a[i+1]);

		}

 

		for (int i=0; i<n; ++i)

			if (s[i]=='4'){

				c4[i]=(i==0?0:c4[i-1])+1;

			} else {

				c4[i]=(i==0?0:c4[i-1]);

			}

		c7[n]=0;

		for (int i=n-1; i>=0; --i)

			if (s[i]=='7'){

				c7[i]=c7[i+1]+1;

			} else {

				c7[i]=c7[i+1];

			}

		int res, tmp=0;

		for (int i=0; i<n; ++i)

			if (s[i]=='4') ++tmp;

		res=max(tmp,n-tmp);

		for (int i=0; i<n; ++i)

			if (s[i]=='7'){

				res=max(res,c4[i]+c7[i]+a[i]);

			}

			printf("%d\n",res);

	}

    getch();

	return 0;

} 

/*input
4 20
10 17
3 17
5 8
9 3
*/


// In the name of Allah, the Most Gracious, the Most Merciful.



#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef float fl;

#define endl '\n'
#define dbg2a(x,y,z) cerr << #x << '[' << y << "][" << z << "] = " << x[y][z] << '\n';
#define Inf 2e9
#define ub(x,y,z) (upper_bound(x,x+y,z) - x)
#define lb(x,y,z) (lower_bound(x,x+y,z) - x)
#define fast ios::sync_with_stdio(false)
#define pb(x) push_back(x)
#define len(x) ((int)(x).size())
int scale(char c) {if(c<='9'&&c>='0')return c-'0';if(c<='Z'&&c>='A')return c-'A'+1;return c-'a'+1;} 

/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/
 
/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/

int dp[1004][1004];

int main()
{
	int items,weight;
	cin >> items >> weight;
	int wt[items+4],val[items+4];
	for(int i=1;i<=items;++i) {
		cin >> wt[i] >> val[i];
	}
	int i,w;
	for(i=0;i<=items;i++) {
		for(w = 0; w <= weight;w++) {
			if(i==0 || w==0) dp[i][w] = 0;
			else if(wt[i] <= w) {
				dp[i][w] = max(val[i] + dp[i-1][w-wt[i]],dp[i-1][w]);
			} else dp[i][w] = dp[i-1][w];
		}
	}
	cout<<dp[items][weight]<<endl;
	return 0;
}
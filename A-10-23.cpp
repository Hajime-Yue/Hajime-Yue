/*
 ──────────────────────────────────────
 ─▄▄▄───────────▄▄▄▄▄▄▄────────────────
 █▀░▀█──────▄▀▀▀░░░░░░░▀▀▄▄────────────
 █░░░░█───▄▀░░░░░░░░░░░░░░░▀▄───────▄▄▄
 █▄░░░▀▄▄▀░░██░░░░░░░░░░░░░░▀█────█▀▀░█
 ─█░░░░█▀░░░▀░░░░░░░░██░░░░░░▀█─▄█░░░░█
 ─▀█░░▄█░░░░░░░▄▄▄░░░░▀░░░░░░░███░░░░█▀
 ──█▄░█░░░░░▄███████▄░░░░░░░░░█▀░░░░▄▀─
 ──▀█░█░░░░▄██████████░░░░░░░▄█░░░░▄▀──
 ───███░░░░███████████░░░░░░▄█░░░░█▀───
 ────█░░░░░██████████▀░░░░░░█░░░░█▀────
 ────█░░░░░░▀███████▀░░░░░░░█▄▄▄▀──────
 ────█░░░░░░░░▀▀▀▀░░░░░░░░░░░▀█────────
 ────█░░░░░░░░░░░░░░░░░░░░░░░░█────────
 ────█░░░░░░░░░░░░░░░░░░░░░░░░█────────
 ────█░░░░░░░░░░░░░░░░░░░░░░░░█────────
 ──────────────────────────────────────
 */
#include <bits/stdc++.h>
#define int long long 
#define ii pair<int, int>
#define jj pair<int, pair< int , int > >

using namespace std ;
const int oo = 1e18;
struct Tnode
{
	int f,s;
};
void TIME();
 
int n;
Tnode A[1010][1010];
int Dp[1010][1010];
int Dp1[1010][1010];
 
int solve(int i, int j);
int solve1(int i , int j);
int chia2(int a);
int chia5(int a);
 
 
main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);
 
 	freopen("A.inp","r",stdin);
	freopen("A.out","w",stdout);

	cin >> n ;
 	int a;
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= n ; j ++)
		{
			cin >> a;
			A[i][j].f = chia2(a);
			A[i][j].s = chia5(a);
		}
	}
 
	int Ans , Ans1;
	memset(Dp,-1,sizeof(Dp));
	memset(Dp1,-1,sizeof(Dp1));
	Ans = solve(1,1);
	Ans1 = solve1(1,1);
	//cout << Ans <<" "<< Ans1 << endl;
	cout << min (Ans, Ans1) << endl;
	int i = 1 ; 
	int j = 1 ;
	if(Ans > Ans1)
	{
		
		while(i != n || j != n)
		{
			
			if(Ans1 - A[i][j].s == solve1(i+1,j))
			{
				Ans1 -= A[i][j].s;
				cout << "D";
				i ++;
				//cout << i <<" "<< j << endl;
				continue;
			}
			if(Ans1 - A[i][j].s == solve1(i,j+1))
			{
				Ans1 -= A[i][j].s;
				cout << "R";
				j ++;
				//cout << i <<" "<< j << endl;
				
				continue;
			}
			//cout << i << " " << j << endl;
		}
	}
	else
	{
		while(i != n || j != n)
		{
			//cout << i <<' '<< j << endl;
			if(Ans - A[i][j].f == solve(i+1,j))
			{
				Ans -= A[i][j].f;
				cout << "D";
				i ++;
				//cout << i <<" "<< j << endl;
				continue;
 
			}
			if(Ans - A[i][j].f == solve(i,j+1))
			{
				Ans -= A[i][j].f;
				cout << "R";
				j ++;
				//cout << i <<" "<< j << endl;
				continue;
 
			}
		}
	}
	return 0;
}
 
void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}
 
int solve(int i , int j)
{
	//cout << A[i][j].f;
	if(i > n || j > n)
	{
		return oo;
	}
	if(i == n && j == n)
	{
		return A[i][j].f;
	}	
	if(Dp[i][j] != -1)
	{
		return Dp[i][j];
	}
 
	int Cur = oo;
 
	Cur = min(solve(i + 1, j) + A[i][j].f , Cur);
	Cur = min(solve(i , j + 1) + A[i][j].f , Cur);
 
	//cout << Cur << endl;
	return  Dp[i][j] = Cur;
}
int solve1(int i , int j)
{
	if(i > n || j > n)
	{
		return oo;
	}
	if(i == n && j == n)
	{
		return A[i][j].s;
	}	
	if(Dp1[i][j] != -1)
	{
		return Dp1[i][j];
	}
 
	int Cur = oo;
 
		Cur = min(solve1(i + 1, j) + A[i][j].s , Cur);
		Cur = min(solve1(i , j + 1) + A[i][j].s , Cur);
 
	return  Dp1[i][j] = Cur;
}
int chia2(int a)
{
	int Res = 0;
	while(a % 2 == 0)
	{
		Res ++;
		a /= 2;
	}
	return Res;
}
int chia5(int a)
{
	int Res = 0;
	while(a % 5 == 0)
	{
		Res ++;
		a /= 5;
	}
	return Res;
}
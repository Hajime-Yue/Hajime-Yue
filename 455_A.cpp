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
#define f first
#define s second
using namespace std ;

void TIME();
int n;
int Dp[100010][2];
int A[100010];
int TS[100010];
std::vector<int> B;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; ////cout.tie(0);

	freopen("455_A.inp","r",stdin);
	freopen("455_A.out","w",stdout);

	cin >> n ;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> A[i];
		if(TS[A[i]] == 0)
		{
			//////cout <<".";
			B.push_back(A[i]);
		}
		TS[A[i]] ++;
	}
	B.push_back(0);
	sort(B.begin(), B.end());
	for(int i = 0 ; i < B.size() ; i ++)
	{
		//cout << B[i] <<" ";
	}
	//cout << endl;
	Dp[1][0] = 0;
	Dp[1][1] = TS[B[1]] * B[1];
	//cout << Dp[1][1] << endl;
	for(int i = 2 ; i < B.size() ; i ++)
	{

		//cout << B[i] <<" "<< TS[B[i]] << endl;
		if(B[i] - B[i-1] == 1)
		{
			//cout <<".";
			Dp[i][0] =  max(Dp[i-1][1],Dp[i-1][0]);
			Dp[i][1] = Dp[i-1][0] + B[i] * TS[B[i]];
		}
		else
		{
			//cout <<",";
			Dp[i][0] = max(Dp[i-1][1],Dp[i-1][0]);
			Dp[i][1] = max(Dp[i-1][1],Dp[i-1][0]) + B[i] * TS[B[i]];
		}
		//cout << Dp[i][0] <<"-"<<Dp[i][1] << endl;
	}
	//////cout << endl;
	cout << max(Dp[B.size()-1][0], Dp[B.size()-1][1]);

	return 0;
}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}
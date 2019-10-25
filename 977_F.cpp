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

int n ; 
int A[200010];
map<int, int> Dp;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("977_F.inp","r",stdin);
	freopen("977_F.out","w",stdout);

	cin >> n ;
	int a;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a;
		A[i] = a;
		Dp[a] = Dp[a-1] + 1;
	}

	int Ans = 0;
	int Op1;
	for(int i = 1 ; i <= n ; i ++)
	{
		Ans = max(Ans, Dp[A[i]]);
		if(Dp[A[i]] == Ans)
		{
			Op1 = A[i];
		}
	}
	int Start = Op1 - Ans + 1;
	std::vector<int> Anss;
	cout << Ans << '\n';
	for(int i = 1 ; i <= n ; i ++)
	{
		if(A[i] == Start)
		{
			cout << i <<" ";
			Start ++;
		}
	}
	return 0;
}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}
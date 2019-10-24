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
const int mod = 1000000007;
void TIME();

int Dp[1000010];
int n ;
int A[100010];
std::vector<int
> Chia;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("1061_C.inp","r",stdin);
	freopen("1061_C.out","w",stdout);

	cin >> n ;
	for(int  i =1 ; i <= n ; i ++)
	{
		cin >> A[i];
	}

	Dp[0] = 1;
	for(int i = 1 ; i <= n ; i ++)
	{
		Chia.clear();
		for(int j = 1 ; j <= sqrt(A[i]) ; j ++)
		{
			if(A[i] % j == 0)
			{
				Chia.push_back(j);
				if(A[i] / j != j)
				{
					Chia.push_back(A[i]/j);
				}	
			}
		}
		sort(Chia.begin(), Chia.end());
		for(int j = Chia.size()-1 ; j >= 0 ; j --)
		{
			Dp[Chia[j]] = (Dp[Chia[j]] + Dp[Chia[j] - 1]) % mod;
		}
	}

	int Ans = 0 ;
	for(int i = 1 ; i <= n ; i ++)
	{
		Ans = (Ans + Dp[i]) % mod;
	}
	cout << Ans;
	return 0;
}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}
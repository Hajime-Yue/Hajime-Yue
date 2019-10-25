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
const int oo = 1e18;
void TIME();

int n, m, k;
int c[110];
int p[110][110];
int Dp[110][110][110];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("711_C.inp","r",stdin);
	freopen("711_C.out","w",stdout);

	cin >> n >> m >> k;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> c[i];
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= m ; j ++)
		{
			cin >> p[i][j]; 
		}
	}
	for(int i = 0 ; i <= n ; i ++)
	{
		for(int j = 0 ; j <= m ; j ++)
		{
			for(int op = 0 ; op <= n ; op ++)
			{
				Dp[i][j][op] = oo;
			}
		}
	}
	if(c[1] == 0)
	{
		for(int i = 1 ; i <= m ; i ++)
		{
			Dp[1][i][1] = p[1][i];
		}
	}
	else
	{
		Dp[1][c[1]][1] = 0;
	}

	for(int i = 2 ; i <= n ; i ++)
	{
		if(c[i] != 0)
		{
				for(int o = 1; o <= n ; o ++)
				{
					if(Dp[i-1][c[i]][o] != oo)
					{
						Dp[i][c[i]][o] = min(Dp[i][c[i]][o], Dp[i-1][c[i]][o]);
					}
					for(int j = 1 ; j <= m ; j ++)
					{
						if(j == c[i])
						{
							continue;
						}
						if(Dp[i-1][j][o-1] == oo)
						{
							continue;
						}
						Dp[i][c[i]][o] = min(Dp[i][c[i]][o], Dp[i-1][j][o-1]);
					}
				}	
		}
		else
		{
			for(int o = 1 ; o <= m ; o ++)
			{
				for(int nc = 1 ; nc <= m ; nc ++)
				{
						for(int j = 1 ; j <= n ; j ++)
						{
							if(o == nc)
							{
								if(Dp[i-1][o][j] == oo)
								{
									continue;
								}
								Dp[i][o][j] = min(Dp[i][o][j], Dp[i-1][o][j] + p[i][o]);
							}
							else
							{
								if(Dp[i-1][o][j-1] == oo)
								{
									continue;
								}
								Dp[i][nc][j] = min(Dp[i][nc][j], Dp[i-1][o][j-1] + p[i][nc]);
							}
						}	
						

				}
			}
		}
	}
	// for(int i = 1 ; i <= n ; i ++)
	// {
	// 	cout << i <<"." << endl;
	// 	for(int j = 1 ; j <= m ; j ++)
	// 	{
	// 		for(int op = 1 ; op <= m ; op ++)
	// 		{
	// 			cout << Dp[i][j][op] << ' ';
	// 		}
	// 		cout << endl;
	// 	}
	// 	cout << endl;
	// }
	int Ans = oo;
	for(int i = 1 ; i <= m ; i ++)
	{
		//cout << Dp[n][i][k] << endl;
		Ans = min(Ans, Dp[n][i][k]);
	}
	if(Ans == oo)
	{
		cout << -1;
	}
	else
	{
		cout << Ans;
	}
	return 0;


}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}
// IDEA:
// From constraints we can guess it is
// a dynamic programming problem

// dp[curr_player][curr_turns_left][curr_num],
// means if both players play optimally who is the winner
// with curr_player starting and with curr_turns_left and
// and starting with curr_num

// curr_player can choose from any one of four paths
// but he will choose path which will make him win
// if no path is winning then curr_player is bound to loose
// ROHIT will play in such a way so as to make the final number
// strictly greater than given number
// PICHU will play in such a way so as to make the final number
// strictly less than or equal to given number

// in the solution below
// 1 denotes "Rohit" and 0 denotes "Pichu"

// think of the solution in bottom up approach
// it will be eaisier to digest
// first calculate base case what if no of turns = 0
// then calculate for no of turns = 1
// then calculate for no of turns = 2
// and so on and on till you finally calculate
// for given n turns given in the problem

// our answer is stores in dp[1][t][n] == 1 means
// rohit will win else pichu (dp[1][t][n] == 0)
// dp[1][t][n] means
// who will win if rohit starts with t turns left
// and starting number is n

// look at the implementation below for better clarity

#include <bits/stdc++.h>
using namespace std;

int dp[2][101][10000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--)
    {
        // n - curr_num when rohit starts
        // t - turns left when rohit starts
        int n, t;
        cin >> n >> t;

        // ct - curr_starting_turns
        // cn - curr_starting_num
        // cp - current player
        for (int ct = 0; ct <= t; ct++)
        {
            for (int cn = 0; cn < 10000; cn++)
            {
                for (int p = 0; p < 2; p++)
                {
                    if (ct == 0)
                    {
                        // calculating for turns left = 0
                        // if cn > n rohit wins else pichu
                        dp[p][ct][cn] = (cn > n) ? 1 : 0;
                    }
                    else
                    {
                        // calculating for turns left = ct

                        // assuming current player has no winning move
                        dp[p][ct][cn] = !p;
                        for (int mul = 10; mul <= 10000; mul *= 10)
                        {
                            int d = cn % mul / (mul / 10);
                            int nn = cn - d * (mul / 10);
                            d = (d + 1) % 10;
                            nn += d * (mul / 10);
                            if (dp[!p][ct - 1][nn] == p)
                            {
                                // if current player has
                                // winning move then
                                // make him winner and break out
                                // of the loop
                                dp[p][ct][cn] = p;
                                break;
                            }
                        }
                    }
                }
            }
        }

        cout << (dp[1][t][n] == 1 ? "Rohit" : "Pichu") << '\n';
    }

    return 0;
}
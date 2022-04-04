// IDEA:
// First find nearest sprinkler distance for each plant
// Then answer is longest of all of those distances 

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  cin >> tc;

  while (tc--) {
    // pn - no of plants
    // sn - no of sprinklers
    int pn, sn;
    cin >> pn >> sn;

    // p - plants array
    // s- sprinkler array
    vector<int> p(pn), s(sn);
    for (int i = 0; i < pn; i++) {
      cin >> p[i];
    }
    for (int i = 0; i < sn; i++) {
      cin >> s[i];
    }
    
    // we are sorting both plant positions and sprinklers 
    // to find nearest sprinkler for each plant  
    sort(p.begin(), p.end());
    sort(s.begin(), s.end());

    // nls - nearest-left-sprinkler array 
    // (stores position of immediate left sprinkler position for
    // each plant if exists else store negative infinity)
    
    // nrs - nearest-right-sprinkler
    // (stores position of immediate right sprinkler position for
    // each plant if exists else store positive infinity)
    
    vector<int> nls(pn), nrs(pn);
    {
      int j = 0;
      for (int i = 0; i < pn; i++) {
        if (p[i] < s[j]) {
          // mark negative infinity if there is no left sprinkler
          nls[i] = -1e9;
          continue;
        }
        // move until we find closest left sprinkler 
        // to the current plant
        while (j + 1 < sn and s[j + 1] <= p[i]) {
          j++;
        }
        // storing the nearest left sprinkler coordinates
        nls[i] = s[j];
      }
    }
    {
      int j = sn - 1;
      for (int i = pn - 1; i >= 0; i--) {
        if (s[j] < p[i]) {
          // mark positive infinity if there is no right sprinkler
          nrs[i] = 1e9;
          continue;
        }
        // move until we find closest right sprinkler 
        // to the current plant
        while (j - 1 >= 0 and p[i] <= s[j - 1]) {
          j--;
        }
        // storing the nearest right sprinkler coordinates
        nrs[i] = s[j];
      }
    }

    int ans = 0;
    for (int i = 0; i < pn; i++) {
      // checking if distance of nearest sprinkler is greater than 
      // our answer if yes we update our ans
      ans = max(ans, min(p[i] - nls[i], nrs[i] - p[i]));
    }
    cout << ans << '\n';
  } 

  return 0;
}







// IDEA: 
// There are no cycles in the graph as
// all n nodes are connected by n - 1 edges 
// as a single component or unit
// if there is even one cycle it is impossible to 
// connect all n nodes with n - 1 edges.
// Shortest path is nothing but simple path from 
// one node to another node. 
// Even distance is only possible if you connect 
// either two nodes at even positions or 
// two nodes at odd positions. This you can prove by simple observation.
// Basically use dfs or bfs to get the count
// And then find the answer using nC2 = n * (n - 1) / 2 formula
// for even_nodes_count and odd_nodes_count and add to get answer
// use long long to ensure no overflow. 

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	// g - graph
	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		// storing neighbours
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
	}

	// x = 0 implies level or depth is even
	// x = 1 implies level or depth is odd 
	// oc - count of nodes present at odd levels or depths
	// ec - count of nodes present at even levels or depths
	queue<pair<int, int>> q; // pair<node, node's parent>
	q.push({0, -1});
	int x = 0, oc = 0, ec = 0;
	while (!q.empty()) {
		x ^= 1; // taking xor to toggle between 0 and 1
		if (x == 1) {
			oc += q.size();
		} else { 
			ec += q.size();
		}

		int s = q.size();
		while (s--) {
			pair<int, int> pii = q.front();
			q.pop();
			int curr = pii.first;
			int par = pii.second;
			for (int adj : g[curr]) {
				if (adj == par) {
					continue;
				}
				q.push({adj, curr});
			}
		}
	}

	long long ans = 1ll * oc * (oc - 1) / 2 + 1ll * ec * (ec - 1) / 2;
	cout << ans << '\n';

	return 0;
}















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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        // n - curr_num when rohit starts
        // t - turns left when rohit starts 
        int n, t;
        cin >> n >> t;

        // ct - curr_starting_turns
        // cn - curr_starting_num
        // cp - current player
        for (int ct = 0; ct <= t; ct++) {
            for (int cn = 0; cn < 10000; cn++) {
                for (int p = 0; p < 2; p++) {
                    if (ct == 0) {
                        // calculating for turns left = 0
                        // if cn > n rohit wins else pichu
                        dp[p][ct][cn] = (cn > n) ? 1 : 0;
                    } else {
                        // calculating for turns left = ct

                        // assuming current player has no winning move
                        dp[p][ct][cn] = !p;
                        for (int mul = 10; mul <= 10000; mul *= 10) {
                            int d = cn % mul / (mul / 10);
                            int nn = cn - d * (mul / 10);
                            d = (d + 1) % 10;
                            nn += d * (mul / 10);
                            if (dp[!p][ct - 1][nn] == p) {
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
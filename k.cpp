#include <iostream>
#include <vector>

int main() {
  int n_size;
  int m_size;
  std::cin >> n_size >> m_size;

  std::vector<int> cost(n_size);
  std::vector<int> weight(n_size);
  std::vector<std::vector<int>> dp(n_size + 1, std::vector<int>(m_size + 1));

  for (int i = 0; i < n_size; ++i) {
    std::cin >> weight[i];
  }
  for (int i = 0; i < n_size; ++i) {
    std::cin >> cost[i];
  }

  for (int i = 1; i <= n_size; ++i) {
    for (int j = 1; j <= m_size; ++j) {
      if (j >= weight[i - 1]) {
        dp[i][j] =
            std::max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + cost[i - 1]);
        continue;
      }
      dp[i][j] = dp[i - 1][j];
    }
  }
  std::vector<int> ans;
  int it_1 = n_size;
  int it_2 = m_size;
  while (dp[it_1][it_2] != 0) {
    if (dp[it_1][it_2] == dp[it_1 - 1][it_2]) {
      it_1--;
    } else {
      ans.push_back(it_1);
      it_1--;
      it_2 -= weight[it_1];
    }
  }
  for (int i = 0; i < (int)ans.size(); i++) {
    std::cout << ans[i] << '\n';
  }

  return 0;
}

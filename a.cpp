#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
int main() {
  int32_t size_arr;
  std::cin >> size_arr;
  std::vector<int32_t> arr(size_arr);
  for (size_t i = 0; i < (size_t)size_arr; i++) {
    std::cin >> arr[i];
  }
  std::reverse(arr.begin(), arr.end());

  std::vector<int32_t> dp(size_arr + 1, INT_MAX);
  std::vector<int32_t> pr(size_arr + 1, -1);
  std::vector<int32_t> pos(size_arr + 1, 0);

  int32_t res = 0;
  dp[0] = -INT_MAX;
  pos[0] = -1;
  for (size_t i = 0; i < (size_t)size_arr; i++) {
    size_t best_j = std::upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
    if (arr[i] > dp[best_j - 1] && arr[i] < dp[best_j]) {
      dp[best_j] = arr[i];
      pr[i] = pos[best_j - 1];
      pos[best_j] = i;
      res = std::max(res, (int32_t)best_j);
    }
  }
  std::cout << res << '\n';
  int32_t vert = pos[res];
  std::vector<int32_t> ans;
  while (true) {
    if (vert == -1) {
      break;
    }
    ans.push_back(size_arr - vert);
    vert = pr[vert];
  }
  for (size_t i = 0; i < (size_t)ans.size(); i++) {
    std::cout << ans[i] << ' ';
  }
  return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>
const long long kInf = 1e9;
const int kRight = 1e5;
long long HeightMax(int count_plane, int count_att) {
  long long res = 0;
  long long pw = 1;
  for (int i = 1; i <= count_plane; i++) {
    pw = (pw * count_att) / i;
    res += pw;
    if (res > kInf) {
      return kInf;
    }
    count_att--;
  }
  return res + 1;
}
int main() {
  long long h_house;
  long long count_plane;
  std::cin >> h_house >> count_plane;

  int left = -1;
  int right = kRight;
  while (right - left > 1) {
    int mid = (right + left) / 2;
    if (HeightMax(count_plane, mid) >= h_house) {
      right = mid;
    } else {
      left = mid;
    }
  }

  if (right >= h_house || (count_plane == 0 && h_house != 1)) {
    std::cout << -1;
    return 0;
  }
  std::cout << right << '\n';
  return 0;
}

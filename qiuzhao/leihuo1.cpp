
//
// Created by Administrator on 2019/9/15.
//

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct rectangle {
  float w, h;
  rectangle(float w, float h) : w(w), h(h) {}
};

bool cmp(const rectangle &a, const rectangle &b) {
  float area_a = a.w * a.h;
  float area_b = b.w * b.h;
  if (area_a < area_b) {
    return true;
  } else if (area_a > area_b) {
    return false;
  } else {
    float ratio_a = min(a.h / a.w, a.w / a.h);
    float ratio_b = min(b.h / b.w, b.w / b.h);
    if (ratio_a > ratio_b) {
      return true;
    } else if (ratio_a < ratio_b) {
      return false;
    } else {
      return a.w < b.w;
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<rectangle> rec;
  for (int i = 0; i < n; ++i) {
    float w, h;
    cin >> w >> h;
    rec.emplace_back(w, h);
  }

  sort(rec.begin(), rec.end(), cmp);
  for (int i = 0; i < n; ++i) {
    cout << rec[i].w << " " << rec[i].h << " ";
  }
  return 0;
}
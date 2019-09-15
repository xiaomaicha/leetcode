//
// Created by Administrator on 2019/4/14.
//

#include <iostream>
#include <vector>

using namespace std;

bool vertifysequencebst(vector<int>::iterator left, vector<int>::iterator right) {
  if (left == right)
    return false;
  int root = *(right - 1);

  auto it1 = left;
  for (; it1 != right - 1; it1++) {
    if (*it1 > root)
      break;
  };
  auto it2 = it1;
  for (; it2 != right - 1; it2++) {
    if (*it2 < root)
      return false;
  }

  bool bleft = true;
  if (it1 != left)
    bleft = vertifysequencebst(left, it1);

  bool bright = true;
  if (it1 != right - 1)
    bright = vertifysequencebst(it1, right - 1);

  return (bleft && bright);
};

bool vertifysequencebst_2(vector<int> &vec, int left, int right) {
  int root = vec[right];

  int i = left;
  for (; i < right; ++i) {
    if (vec[i] > root)
      break;
  }
  int j = i;
  for (; j < right; ++j) {
    if (vec[j] < root)
      return false;
  }

  bool b_left = true;
  if (i > left)
    b_left = vertifysequencebst_2(vec, left, i - 1);
  bool b_right = true;
  if (i < right)
    b_right = vertifysequencebst_2(vec, i, right - 1);
  return (b_left && b_right);
}

int main() {
  vector<int> seq1 = {4, 8, 6, 12, 16, 14, 10};;
  bool bseq1 = vertifysequencebst(seq1.begin(), seq1.end());
  bseq1 = vertifysequencebst_2(seq1, 0, seq1.size() - 1);
  cout << bseq1 << endl;

  vector<int> seq2 = {4, 6, 7, 5};;
  bool bseq2 = vertifysequencebst(seq2.begin(), seq2.end());
  bseq2 = vertifysequencebst_2(seq2, 0, seq2.size() - 1);

  cout << bseq2 << endl;

  vector<int> seq3 = {7, 4, 6, 5};;
  bool bseq3 = vertifysequencebst(seq3.begin(), seq3.end());
  bseq3 = vertifysequencebst_2(seq3, 0, seq3.size() - 1);
  cout << bseq3 << endl;

  return 0;
}


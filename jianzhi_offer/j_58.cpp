
//
// Created by Administrator on 2019/8/17.
//

#include <string>
#include <iostream>

using namespace std;

void reverse_string(string &str) {
  if(str.size() <= 1)
    return;
  int low = 0, high = str.size() - 1;
  while (low < high) {
    char temp = str[low];
    str[low] = str[high];
    str[high] = temp;
    ++low;
    --high;
  }
}

string reverse_sentence(string &sentence) {
  if (sentence.size() <= 1)
    return sentence;
  string res;
  reverse_string(sentence);

  int low = 0;
  for (int i = 0; i < sentence.size(); ++i) {
    if (sentence[i] == ' ') {
      string temp = sentence.substr(low, i - low);
      reverse_string(temp);
      res += temp;
      res += " ";
      low = i + 1;
    }
  }
  string temp = sentence.substr(low, sentence.size());
  reverse_string(temp);
  res +=temp;
  return res;
}

int main() {
  string sentence = "my name is wuqi.";
  auto res = reverse_sentence(sentence);
  cout<<"res: "<<res<<endl;
  return 0;
}
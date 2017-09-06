#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <climits>
#include <sstream>

using namespace std;
typedef unsigned long long ull;
string num;
int num_size;

bool check_if_sorted() {
  char prev = num[0];
  for(auto i = 1; i <= num_size; ++i){
    if(num[i] < prev)
      return false;
    prev = num[i];
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  int t;
  freopen("test.in", "r", stdin);
  cin >> t;
  ofstream fout ("test.out");
  for(int k = 1; k <= t; ++k){
    cin >> num;
    num_size = (int)num.size() - 1;
    while(!check_if_sorted()){
      char last = num[num_size];
      if(last == '0'){
        num[num_size] = '9';
        char second_last = num[num_size - 1];
        if(second_last == '1'){
          num[num_size - 1] = '0';
        } else if(second_last == '0'){
        } else {
          num[num_size - 1]--;
        }
        num_size--;
      } else {
        num[num_size] = last - 1;
      }
      // cout << num << endl;
    }
    num.erase(0, min(num.find_first_not_of('0'), num.size()-1));
    fout << "Case #" << k << ": " << num << endl;
  }
  fout.close();
  return 0;
}

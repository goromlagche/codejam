#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int t;
  freopen("test.in", "r", stdin);
  cin >> t;
  string line;
  getline(cin, line);
  ofstream fout("test.out");
  for(int z = 1; z <= t; ++z){
    int k, c = 0;

    getline(cin, line);
    size_t ofs_front = line.find(' ');
    string cakes = line.substr(0, ofs_front);
    stringstream ss(line.substr(ofs_front));
    ss >> k;
    int size_s = (int)cakes.size();
    string sol(size_s, '+');

    for(int i = 0; i != size_s; ++i){
      char elem = cakes[i];
      if((elem == '-') && (i+(k-1) < size_s)){
        // flip
        for(int j = i; j <= i+(k-1); ++j){
          if(cakes[j] == '+'){
            cakes[j] = '-';
          }
          else{
            cakes[j] = '+';
          }
        }
        c++;
      }
    }

    fout << "Case #" << z << ": ";
    if(cakes == sol)
      fout << c << endl;
    else
      fout << "IMPOSSIBLE" << endl;
  }
  fout.close();
  return 0;
}

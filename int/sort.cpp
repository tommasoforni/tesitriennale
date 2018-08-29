#include<vector>
#include<algorithm>
#include<iostream>
#include<fstream>
using namespace std;


struct mypair {
  double x,y;
};

bool comp( const mypair & p1, const mypair & p2){
  return ( p1.x < p2.x);
}

int main (int argc, char** argv) {
  ifstream file(argv[1]);
  vector<mypair> p;
  mypair temp;
  while(file >> temp.x) {
    file  >> temp.y;
    p.push_back(temp);
  }

  sort(p.begin(),p.end(),comp);
  file.close();
  ofstream file1(argv[1]);
  for (auto & el : p) {
    file1 << el.x <<"\t" << el.y <<endl;
  }
  file1.close();
  return 0;
}

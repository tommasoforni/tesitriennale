#include<vector>
#include<algorithm>
#include<iostream>
#include<fstream>
using namespace std;


struct mypair {
  double x,y;
};

bool comp( const mypair & p1, const mypair & p2){
  return ( p1.y < p2.y);
}

double vertex( mypair & p1, mypair & p2, mypair & p3){
  double x1=p1.x, y1=p1.y;
  double x2=p2.x, y2=p2.y;
  double x3=p3.x, y3=p3.y;

  return -((-(x2*y1/(x1-x2)/(x1-x3))-(x3*y1/(x1-x2)/(x1-x3))-(x1*y2/(x2-x1)/(x2-x3))-(x3*y2/(x2-x1)/(x2-x3))-(x1*y3/(x3-x1)/(x3-x2))-(x2*y3/(x3-x1)/(x3-x2)))/((2*y1/(x1-x2)/(x1-x3))+(2*y2/(x2-x1)/(x2-x3))+(2*y3/(x3-x1)/(x3-x2))));
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
  mypair p1 = *(p.end()-1);
  mypair p2 = *(p.end()-2);
  mypair p3 = *(p.end()-3);
  cout << vertex(p1,p2,p3) <<endl;
  return 0;
}

#include<iostream>
#include<fstream>
using namespace std;

int main (int argc, char** argv)
{
  ifstream file(argv[1]);
  double x,x2;
  double y,y2;
  double sum = 0.;
  file >> x;
  file >> y;
  
  while(file >> x2)
  {
    file >> y2;
    sum += (1e9)*(x2-x)*(y+y2)/2. ;
    x = x2;
    y = y2;
  }

  cout << sum <<endl;
  return 0;
}

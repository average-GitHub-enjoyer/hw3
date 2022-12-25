#include "bmstu_vector.hpp"

int main(){
  bmstu::vector<int> a;
  a.push_back(1);
  a.push_back(2);
  // a.push_back(3);
  // a.push_back(4);

  for(auto i : a)
    std::cout << i << std::endl;
}

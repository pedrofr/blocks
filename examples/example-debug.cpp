#include <blk.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
  
  blk::Expr e1 = blk::text("a");
  blk::Expr e2 = blk::text("b");

  std::cout << (((e1+e2)/(e2+e2+e1))/e1) << std::endl;
   
  return 0;
}

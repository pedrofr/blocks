#include <blk.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
  blk::Expr e = blk::debug('a',7,4,3,1);
  std::cout <<
    blk::move_ref(e,2,0) << std::endl <<
    e << std::endl;
  return 0;
}

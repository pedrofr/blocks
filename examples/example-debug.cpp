#include <blk.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
  blk::Expr e1 = blk::debug('a',7,4,3,1);
  blk::Expr e2 = blk::debug('b',4,8,2,2);
  
  std::cout << blk::over(blk::move_ref(e1,1,3),e2) << std::endl
	    << std::endl;
  return 0;
}

#include <blk.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
  
  blk::Expr e1 = blk::debug('a',7,4,3,1);
  blk::Expr e2 = blk::debug('b',4,8,2,2);
  
  blk::Expr o = blk::over(e1,e2);
  
  std::cout << "width: " << o->getWidth() << std::endl
	    << "height: " << o->getHeight() << std::endl
	    << "ref_w: " << o->getRefWidth() << std::endl
	    << "ref_h: " << o->getRefHeight() << std::endl;
  
  std::cout << e1 << std::endl
	    << e2 << std::endl
	    << o <<  std::endl;

  std::cout << blk::beside(e1,e2) << std::endl
	    << blk::over(blk::move_ref(e1,1,3),e2) << std::endl
	    << std::endl;
   
  return 0;
}

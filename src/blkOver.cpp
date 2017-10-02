#include <blkOver.hpp>

blk::Expr blk::over(blk::Expr above, blk::Expr under) {
  int height = above->getHeight() + under->getHeight();
  int ref_h = above->getRefHeight();
  int ref_w = max(above->getRefWidth(), under->getRefWidth());
  int width = ref_w + max(above->getWidth() - above->getRefWidth(), under->getWidth() - under->getRefWidth()) - 1;
  
  return Expr(new Over(above, under, widht, height, ref_w, ref_h));
}

blk::Over::Over(blk::Expr above, blk::Expr under, int width, iht height, int ref_w, int ref_h)
  : Block(width, height, ref_w, ref_h),
    above_(above),
    under_(under)
{}

void blk::Over::printInBoundsLine(std::ostream& os, int i) const {
  //    std::cout <<
  //    getRefWidth() << std::endl <<
  //    getRefHeight() << std::endl;
  Block::call_printInBoundsLine(subBlock_, os, i);
}

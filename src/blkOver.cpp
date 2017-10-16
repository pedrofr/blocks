#include <blkOver.hpp>

blk::Expr blk::over(blk::Expr above, blk::Expr below) {
  int height = above->getHeight() + below->getHeight();
  int ref_h = above->getRefHeight();
  int ref_w = std::max(above->getRefWidth(), below->getRefWidth());
  int width = ref_w + std::max(above->getWidth() - above->getRefWidth(), below->getWidth() - below->getRefWidth());
  
  return Expr(new Over(above, below, width, height, ref_w, ref_h));
}

blk::Over::Over(blk::Expr above, blk::Expr below, int width, int height, int ref_w, int ref_h)
  : Block(width, height, ref_w, ref_h),
    above_(above),
    below_(below),
    interface_line(above_->getHeight() - getRefHeight())
{}

void blk::Over::printInBoundsLine(std::ostream& os, int i) const {
  //    std::cout <<
  //    getRefWidth() << std::endl <<
  //    getRefHeight() << std::endl;

  if (i < interface_line) {
    for (int j = 0; j < getRefWidth() - above_->getRefWidth(); j++) {
      os << blk::Block::fill;
    }

    Block::call_printInBoundsLine(above_, os, i);
    
    for (int j = getRefWidth() + (above_->getWidth() - above_->getRefWidth()); j < getWidth(); j++) {
      os << blk::Block::fill;
    }
  } else {    
    for (int j = 0; j < getRefWidth() - below_->getRefWidth(); j++) {
      os << blk::Block::fill;
    }

    int i_below = i - (interface_line + below_->getRefHeight());

    Block::call_printInBoundsLine(below_, os, i_below);
    
    for (int j = getRefWidth() + (below_->getWidth() - below_->getRefWidth()); j < getWidth(); j++) {
      os << blk::Block::fill;
    }    
  }
}

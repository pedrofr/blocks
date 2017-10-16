#include <blkBeside.hpp>

blk::Expr blk::beside(blk::Expr left, blk::Expr right) {
  int width = left->getWidth() + right->getWidth();
  int ref_w = left->getRefWidth();
  int ref_h = std::max(left->getRefHeight(), right->getRefHeight());
  int height = ref_h + std::max(left->getHeight() - left->getRefHeight(), right->getHeight() - right->getRefHeight());
  
  return Expr(new Beside(left, right, width, height, ref_w, ref_h));
}

blk::Beside::Beside(blk::Expr left, blk::Expr right, int width, int height, int ref_w, int ref_h)
  : Block(width, height, ref_w, ref_h),
    left_(left),
    right_(right)
{}

void blk::Beside::printInBoundsLine(std::ostream& os, int i) const {
  blk::Block::call_printLine(left_, os, i);
  blk::Block::call_printLine(right_, os, i);
}

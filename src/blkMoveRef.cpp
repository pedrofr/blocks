#include <blkMoveRef.hpp>

blk::Expr blk::move_ref(blk::Expr subBlock, int new_wr, int new_hr) {
  return Expr(new MoveRef(subBlock, new_wr, new_hr));
}

blk::MoveRef::MoveRef(blk::Expr subBlock, int new_wr, int new_hr)
  : Block(subBlock->getWidth(), subBlock->getHeight(), new_wr, new_hr),
    subBlock_(subBlock) {
  std::cout <<
    getRefWidth() << std::endl <<
    getRefHeight() << std::endl;
    }

void blk::MoveRef::printInBoundsLine(std::ostream& os, int i) const {
  //  std::cout <<
  //  getRefWidth() << std::endl <<
  //  getRefHeight() << std::endl;
  Block::call_printInBoundsLine(subBlock_, os, i + getRefHeight() - subBlock_->getRefHeight());
}

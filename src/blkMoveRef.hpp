#pragma once

#include <blkBlock.hpp>

namespace blk {

  //
  Expr move_ref(Expr subBlock, int new_wr, int new_hr);
  
  class MoveRef : public Block {
  private:
    Expr subBlock_;

    friend Expr move_ref(Expr subBlock, int new_wr, int new_hr);

    MoveRef(Expr subBlock, int new_wr, int new_h);

  public:

    MoveRef()                              = delete;
    MoveRef(const MoveRef& cpy)            = delete;
    MoveRef(MoveRef&& cpy)                 = delete;
    MoveRef& operator=(const MoveRef& cpy) = delete;
    MoveRef& operator=(MoveRef&& cpy)      = delete;
    virtual ~MoveRef() {}
    
  protected:

    virtual void printInBoundsLine(std::ostream& os, int i) const override;
  };
}

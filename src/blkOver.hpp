#pragma once

#include <blkBlock.hpp>

namespace blk {


  Expr over(Expr above, Expr below);

  class Over : public Block {
  private:
    Expr above_;
    Expr below_;
    int interface_line;

    friend Expr over(Expr above, Expr below);

    Over(Expr above, Expr below, int width, int height, int ref_w, int ref_h);

  public:
    Over()                              = delete;
    Over(const Over& cpy)            = delete;
    Over(Over&& cpy)                 = delete;
    Over& operator=(const Over& cpy) = delete;
    Over& operator=(Over&& cpy)      = delete;
    virtual ~Over() {}

  protected:
    virtual void printInBoundsLine(std::ostream& os, int i) const override;
  };
  
}

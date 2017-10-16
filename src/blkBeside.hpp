#pragma once

#include <blkBlock.hpp>

namespace blk {

  Expr beside(Expr left, Expr right);

  class Beside : public Block {
  private:
    Expr left_;
    Expr right_;

    friend Expr beside(Expr left, Expr right);

    Beside(Expr left, Expr right, int width, int height, int ref_w, int ref_h);

  public:
    Beside()                           = delete;
    Beside(const Beside& cpy)            = delete;
    Beside(Beside&& cpy)                 = delete;
    Beside& operator=(const Beside& cpy) = delete;
    Beside& operator=(Beside&& cpy)      = delete;
    virtual ~Beside() {}

  protected:
    virtual void printInBoundsLine(std::ostream& os, int i) const override;
  };
  
}

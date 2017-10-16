#pragma once

#include <blkBlock.hpp>
#include <string>

namespace blk {

  // This factory creates an expression... which is a text block.
  Expr text(std::string string);

  class Text : public Block {
  private:
    
    std::string s;

    friend Expr text(std::string string);

    Text(std::string string);

  public:

    Text()                            = delete;
    Text(const Text& cpy)            = delete;
    Text(Text&& cpy)                 = delete;
    Text& operator=(const Text& cpy) = delete;
    Text& operator=(Text&& cpy)      = delete;
    virtual ~Text() {}

  protected:

    virtual void printInBoundsLine(std::ostream& os, int i) const override;
  };
  
}

#include <blkText.hpp>
#include <string>

blk::Expr blk::text(std::string string) {
  return Expr(new Text(string));
}

blk::Text::Text(std::string string)
  : Block(string.length(),1,0,0),
    s(string){}


void blk::Text::printInBoundsLine(std::ostream& os, int i) const {
  os << s;
}

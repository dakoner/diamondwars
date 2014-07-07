#ifndef _COLOR_H_
#define _COLOR_H_

class Color {
public:
  Color(): _r(0), _g(0), _b(0) {
  }
  Color(unsigned char r, unsigned char g, unsigned char b): _r(r), _g(g), _b(b) {
  }
  unsigned char r() { return _r; }
  unsigned char g() { return _g; }
  unsigned char b() { return _b; }

private:  
  unsigned char _r, _g, _b; 
};

#endif

// // pointers to base class
// #include <iostream>
// using namespace std;

// class Polygon {
//   protected:
//     int width, height;
//   public:
//     void set_values (int a, int b)
//       { width=a; height=b; }
// };

// class Rectangle: public Polygon {
//   public:
//     int area()
//       { return width*height; }
// };

// class Triangle: public Polygon {
//   public:
//     int area()
//       { return width*height/2; }
// };

// int main () {
//   Rectangle rect;
//   Triangle trgl;
//   Polygon * ppoly1 = &rect;
//   Polygon * ppoly2 = &trgl;
//   ppoly1->set_values (4,5);
//   ppoly2->set_values (4,5);
//   cout << rect.area() << '\n';
//   cout << trgl.area() << '\n';
//   return 0;
// }

// dynamic allocation and polymorphism
#include <iostream>
using namespace std;

class Polygon {
  protected:
    int width, height;
  public:
    Polygon (int a, int b) : width(a), height(b) {}
    virtual int area (void) =0;
    void printarea()
      { cout << this->area() << '\n'; }
};

class Rectangle: public Polygon {
  public:
    Rectangle(int a,int b) : Polygon(a,b) {}
    int area()
      { return width*height; }
};

class Triangle: public Polygon {
  public:
    Triangle(int a,int b) : Polygon(a,b) {}
    int area()
      { return width*height/2; }
};

int main () {
  Polygon * ppoly1 = new Rectangle (4,5);
  Polygon * ppoly2 = new Triangle (4,5);
  ppoly1->printarea();
  ppoly2->printarea();
  delete ppoly1;
  delete ppoly2;
  return 0;
}
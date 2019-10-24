/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*
 * Key idea:
 *
 *   decltype almost always parrots back the type of the name or expression you
 *   give it without any modification.
 */

#include <cstddef>
#include <iostream>
#include <memory>
#include <string>
#include <cstdlib>


class Widget {};

const int i = 0;           // decltype(i) is const int

bool f(const Widget& w){}   // decltype(w) is const Widget&
                           // decltype(f) is bool(const Widget&)

struct Point {
  int x, y;                // decltype(Point::x) is int
};                         // decltype(Point::y) is int

Widget w;                  // decltype(w) is Widget


template<typename T>       // simplified version of std::vector
class vector {
public:
  // ...
  T& operator[](std::size_t index){}
  // ...
};

// https://stackoverflow.com/questions/81870/is-it-possible-to-print-a-variables-type-in-standard-c

template <class T>
std::string type_name()
{
    typedef typename std::remove_reference<T>::type TR;
    std::unique_ptr<char, void(*)(void*)> own
           (
                nullptr,
                std::free
           );
    std::string r = own != nullptr ? own.get() : typeid(TR).name();
    if (std::is_const<TR>::value)
        r += " const";
    if (std::is_volatile<TR>::value)
        r += " volatile";
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";
    return r;
}

int main()
{

  if (f(w)) {}              // decltype(f(w)) is bool

  vector<int> v;            // decltype(v) is vector<int>
  // ...
  if (v[0] == 0) {}         // decltype(v[0]) is int&
  std::cout << type_name<decltype(v[0])>() << std::endl;

}

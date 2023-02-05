/*#include <iostream>

class Base {
   public:
    Base() {
        std::cout << "Base Ctor" << std::endl;
    }

    Base(const Base &obj) {
        std::cout << "Base Copy ctor" << std::endl;
    }

    Base &operator=(const Base &obj) {
        std::cout << "Base Assignment operator " << std::endl;
        return *this;
    }

    virtual ~Base() {
        std::cout << "dtor Base " << std::endl;
    }
};

class Derived : public Base {
   public:
    Derived() {
        std::cout << "Derived Ctor" << std::endl;
    }

    Derived(const Derived &obj) {
        std::cout << "Derived Copy ctor" << std::endl;
    }

    Derived &operator=(const Derived &obj) {
        std::cout << "Derived Assignment operator " << std::endl;
        return *this;
    }

    ~Derived() {
        std::cout << "dtor Derived " << std::endl;
    }
};

int main() {
    // Base a, b;
    // b = a;       // Assignment oper
    // Base c = a;  // Copy ctor
    // Base d(a);   // Copy ctor

    Derived da;
    std::cout << "-------------- Base b;" << std::endl;
    Base b;
    std::cout << "-------------- Derived a(da);" << std::endl;
    Derived a(da);
    std::cout << "-------------- Derived *d = new Derived(); " << std::endl;
    Derived *d = new Derived();
    std::cout << "-------------- Base *b;" << std::endl;
    Base *pb = d;
    Base &refb = *pb;
    std::cout << pb << " " << d << " " << &refb << std::endl;
    delete pb;
    delete d;

    std::cout << " " << &refb << std::endl;
    std::cout << "_______________________" << std::endl;

    return 0;
}*/

#include <iostream>
using namespace std;
class Base {
   protected:
    int a;

   public:
    Base() {
        a = 10;
    }
};
class Child1 : virtual public Base {
   public:
    Child1() {
        a = 1;
    }
    int c;
};
class Child2 : virtual public Base {
   public:
    Child2() {
        a = 5;
    }
    int c;
};
class GrandChild : public Child1, public Child2 {
   public:
    void show() {
        cout << a << endl;
    }
};
int main(void) {
    GrandChild d;
    d.show();
    return 0;
}
#include <iostream>

using namespace std;

class A {
  public:
    void *operator new(size_t s, string str) {
        cout << "operator of A:" << str << endl;
        return ::operator new(s);
    }
};

int main() {
    uint16_t *p1 = (uint16_t *)new ("hello") A();
    ;
    uint16_t *p = (uint16_t *)operator new(16);
}
#include <unistd.h>
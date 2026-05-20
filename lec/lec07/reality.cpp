#include <iostream>
using namespace std;

struct A {
    int a;
    void print() {
        cout << "A: " << a << endl;
    }
};

struct B : A {
    int b;
    void print() {
        cout << "B: " << a << ", " << b << endl;
    }
};

class C : B {
    
    int c;
    public:
    C(int c): c{c} {
        a = c - 2;
        b = c - 1;
    }
    void print() { cout << "C: " << a << ", " << b << ", " << c << endl; }
};

int main() {
    //// Uniform Initialization -- works as usual :) ////
    cout << endl << "-- Uniform Init" << endl;
    B b {1, 2}; //a=1, b=2
    b.print();
    C c {1}; //c=1,a=-1,b=0
    c.print();

    //// Slicing... we can turn B into an A. ////
    cout << endl << "-- Slicing" << endl;

    A a {3};
    a.print();
    ((A)b).print();

    A aArray[3];
    aArray[0] = a;
    aArray[1] = b;
    // aArray[2] = c;


    for (int i = 0; i < 2; i++) {
        aArray[i].print(); // Prints A: ...
    }

    //// Sizing... ////
    cout << endl << "-- Sizing" << endl;

     // [4 bytes of a]
    cout << "A is " << sizeof(A) << " bytes" << endl;
    // [4 bytes of a, 4 bytes of b]
    cout << "B is " << sizeof(B) << " bytes" << endl;
    // [4 bytes of a, 4 bytes of b, 4 bytes of c]
    cout << "C is " << sizeof(C) << " bytes" << endl;

    //// Access to private variables... ////
    cout << endl << "-- Memory" << endl;

    cout << "C before:" << endl;
    c.print();
    int* cAddress = (int*) &c;
    cAddress[0] = 10;
    cAddress[1] = 6;
    cout << "C after:" << endl;
    c.print();


}
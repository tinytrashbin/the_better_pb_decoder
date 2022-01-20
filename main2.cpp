#include <iostream>

// No need of including proto2.h, since we don't need to use decoder
// for subfield p4.b().

#include "pbzero.proto4.h"
#include "pbzero.proto3.h" // because we need to decode p4.c()
#include "pbzero.proto1.h" // because we need to decode p3.p1()

int main() {
  Proto4::Decoder p4("....");
  const char* p4_c_bytes = p4.c(); // or p4.c().data()
  std::cout << p4.c().decoder().p1().decoder().x() << std::endl;
}


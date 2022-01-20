#include <iostream>

// No need of including proto2.h or proto3.h, since we don't need to
// use decoder for subfield p4.b() or p4.c().
// Note that we can still access raw bytes at p4.c() without having
// to include proto2.h

#include "pbzero.proto4.h"
#include "pbzero.proto1.h"

int main() {
  Proto4::Decoder p4("AA.. BB.. CC.. DD.. EE.. FF..");
  std::cout << p4.a().decoder().x() << std::endl;

  const char* p4_a_bytes = p4.a(); // or p4.a().data()
  Proto1::Decoder p1 = p4.a().decoder();
  std::cout << p1.y() << std::endl;
  const char* p4_b_bytes = p4.c().data();
  // p4.c().decoder();  // Compilation Failure. include pbzero.proto3.h
}


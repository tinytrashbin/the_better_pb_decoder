#include "pb_stub.h"

struct Proto1_Decoder {
  Proto1_Decoder(const char* data): data_(data) { }
  int x() { return 200; }
  int y() { return 100; }
  const char* data_;
};

struct Proto1 { using Decoder=Proto1_Decoder; };

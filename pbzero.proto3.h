#include "pb_stub.h"

class Proto1;
class Proto1_Decoder;

struct Proto3_Decoder {
  Proto3_Decoder(const char* data): data_(data) { }
  PData<Proto1_Decoder> p1() { return data_ + 15; }
  int i1() { return 140; }
  int i2() { return 120; }
  const char* data_;
};

struct Proto3 { using Decoder=Proto3_Decoder; };

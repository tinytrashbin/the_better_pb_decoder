#include "pb_stub.h"

class Proto1;
class Proto1_Decoder;
class Proto2;
class Proto2_Decoder;
class Proto3;
class Proto3_Decoder;

struct Proto4_Decoder {
  Proto4_Decoder(const char* data): data_(data) { }
  PData<Proto1_Decoder> a() { return data_ + 15; }
  PData<Proto2_Decoder> b() { return data_ + 25; }
  PData<Proto3_Decoder> c() { return data_ + 35; }
  const char* data_;
};

struct Proto4 { using Decoder=Proto4_Decoder; };

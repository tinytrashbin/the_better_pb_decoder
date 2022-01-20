#ifndef PB_STUB_H
#define PB_STUB_H

// A ZERO overhead wrapper over `const chat*` (proto data). Main use case of
// this wrapper class is to statically hold the Decoder type. Which
// could be forward declaration as well.
template<typename P_Decoder>
struct PData {
  using Decoder = P_Decoder;
  PData(const char* data): data_(data) {}
  // Fake template. Q is unused. This is done to ensure full
  // declaration of `P_Decoder` is not required unless this method is called.
  // Till then forward declaration of P_Decoder is sufficient.
  template<typename Q=void>
  P_Decoder decoder() { return P_Decoder(data_); }
  operator const char* () const { return data_; } // implicit.
  const char* data() const { return data_; } // explicit.
 private:
  const char* data_;
};

#endif  // PB_STUB_H

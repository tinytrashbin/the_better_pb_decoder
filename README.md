## A better pbzero Decoder interface with ZERO overhead

### Goal : Reduce code. Improve readability. Improve dev-experience.

### Before:

To achieve: `a.b().c().d()`, one had to do:

```C++

blah::flah::slah::B::Decoder decoded_b(a.b());
blah::glah::tlah::C::Decoder decoded_c(decoded_b.c());
return decoded_c.d();

// Note, here `a.b()` is `const char*`.
```

### After
With this new interface, one can do:

```C++
a.b().decode().c().decode().d();
```

To get raw bytes, we can use:

```C++
auto bytes = a.b().data();
```
or
```C++
const char* bytes = a.b();  // Implicit.
```

### ZERO cost

1. No runtime cost.
2. No increase in binary size.
3. No need of including proto headers of subfields. Hence, no compilation
   overhead. Only need to include the protos which needs to be decoded (same
   as before).


### Check these files:

- `main1.cpp`, `main2.cpp` and `pb_stub.h`


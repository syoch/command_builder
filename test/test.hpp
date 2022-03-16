#include <builder.hpp>
#include <iostream>

bool IsSame(u8* a, u32 a_size, u8* b, u32 b_size) {
  if (a_size != b_size) {
    return false;
  }

  for (u32 i = 0; i < a_size; i++) {
    if (a[i] != b[i]) {
      return false;
    }
  }

  return true;
}
#include "test.hpp"

int main(int argc, char const *argv[]) {
  u8 buf[0x100] = {0};
  u32 written = 0;

  ReadKernel(buf, &written, 0x100, 0x12345678);

  return !IsSame(buf, written, (u8 *)"\x0C\x12\x34\x56\x78", 5);
}

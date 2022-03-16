#include "test.hpp"

int main(int argc, char const *argv[]) {
  u8 buf[0x100] = {0};
  u32 written = 0;

  WriteKernel(buf, &written, 0x100, 0x12345678, 0xABCDABCD);

  return !IsSame(buf, written, (u8 *)"\x0B\x12\x34\x56\x78\xab\xcd\xab\xcd", 9);
}

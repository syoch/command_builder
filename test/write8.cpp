#include "test.hpp"

int main(int argc, char const *argv[]) {
  u8 buf[0x100] = {0};
  u32 written = 0;

  WriteData8(buf, &written, 0x100, 0x12345678, 0xAB);

  return !IsSame(buf, written, (u8 *)"\x01\x12\x34\x56\x78\0\0\0\xAB", 1 + 8);
}

#include "test.hpp"

int main(int argc, char const *argv[]) {
  u8 buf[0x100] = {0};
  u32 written = 0;

  WriteData16(buf, &written, 0x100, 0x12345678, 0xABCD);

  return !IsSame(buf, written, (u8 *)"\x02\x12\x34\x56\x78\x00\x00\xab\xcd", 9);
}

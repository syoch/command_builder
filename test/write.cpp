#include "test.hpp"

int main(int argc, char const *argv[]) {
  u8 buf[0x100] = {0};
  u32 written = 0;

  Write(buf, &written, 0x100, 0x12345678, (u8 *)"Hello World!", 13);

  return !IsSame(buf, written,
                 (u8 *)"\x41\x12\x34\x56\x78\x12\x34\x56\x85Hello World!\0",
                 1 + 8 + 13);
}

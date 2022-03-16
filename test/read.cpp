#include "test.hpp"

int main(int argc, char const *argv[]) {
  u8 buf[0x100] = {0};
  u32 written = 0;

  Read(buf, &written, 0x100, 0x12345678, 13);

  return !IsSame(buf, written,
                 (u8 *)"\x05\x12\x34\x56\x78\x12\x34\x46\x85\x00\x00\x00\x01",
                 5);
}

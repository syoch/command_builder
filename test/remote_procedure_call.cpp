#include "test.hpp"

int main(int argc, char const *argv[]) {
  u8 buf[0x100] = {0};
  u32 written = 0;
  u32 args[8] = {
      0x1A1B1C1D, 0x2A2B2C2D, 0x3A3B3C3D, 0x4A4B4C4D,
      0x5A5B5C5D, 0x6A6B6C6D, 0x7A7B7C7D, 0x8A8B8C8D,
  };
  RemoteProcedureCall(buf, &written, 0x100, 0x01200120, args);

  return !IsSame(buf, written,
                 (u8 *)"\x70\x01\x20\x01\x20\x1A\x1B\x1C\x1D\x2A\x2B\x2C\x2D\x3A\x3B\x3C\x3D\x4A\x4B\x4C\x4D\x5A\x5B\x5C\x5D\x6A\x6B\x6C\x6D\x7A\x7B\x7C\x7D\x8A\x8B\x8C\x8D",
                 1 + 4*(1+8));
}

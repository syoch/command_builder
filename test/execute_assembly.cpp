#include "test.hpp"

int main(int argc, char const *argv[]) {
  u8 buf[0x100] = {0};
  u32 written = 0;

  u32 code[] = {
      0x60000000,
  };

  ExecuteAssembly(buf, &written, code, 2);

  return !IsSame(buf, written, (u8 *)"\x81\0\0\0\x08\x60\0\0\0\x60\0\0\0", 13);
}

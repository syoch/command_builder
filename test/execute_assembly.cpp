#include "test.hpp"

int main(int argc, char const *argv[]) {
  u8 buf[0x100] = {0};
  u32 written = 0;

  u32 code[] = {0x60000000, 0x60000000};

  ExecuteAssembly(buf, &written, 0x100, code, 2);
  for (u32 i = 0; i < written; i++) {
    std::cout << std::hex << (u32)buf[i] << " ";
  }
  return !IsSame(buf, written, (u8 *)"\x81\0\0\0\x08\x60\0\0\0\x60\0\0\0",
                 1 + 4 + 8);
}

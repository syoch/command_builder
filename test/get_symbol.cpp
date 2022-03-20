#include "test.hpp"

int main(int argc, char const *argv[]) {
  u8 buf[0x100] = {0};
  u32 written = 0;

  GetSymbol(buf, &written, 0x100, false, "coreinit.rpl", 12, "OSGetTitleID",
            12);

  return !IsSame(buf, written,
                 (u8 *)"\x71\x22\x00\x00\x00\x08\x00\x00\x00\x15\x63\x6f\x72\x65\x69\x6e\x69\x74\x2e\x72\x70\x6c\x00\x4f\x53\x47\x65\x74\x54\x69\x74\x6c\x65\x49\x44\x00\x00",
                 37);
}

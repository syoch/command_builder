#include <builder/utils.hpp>

namespace builder::utils {

void write_u32(u8* buf, u32 x) {
  write_u16(buf + 0, x >> 16);
  write_u16(buf + 2, x & 0xFFFF);
}
void write_u16(u8* buf, u16 x) {
  buf[0] = static_cast<u8>(x >> 8);
  buf[1] = static_cast<u8>(x & 0xFF);
}
u32 read_u32(u8* buf) { return (read_u16(buf + 0) << 16) | read_u16(buf + 2); }
u16 read_u16(u8* buf) { return (buf[0] << 8) | buf[1]; }

}  // namespace builder::utils
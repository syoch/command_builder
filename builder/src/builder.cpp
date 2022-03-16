#include <builder.hpp>
#include <builder/command_codes.hpp>
#include <builder/utils.hpp>

using builder::Codes;
using namespace builder::utils;

int WriteData8(u8* buf, u32* written, u32 limit, u32 addr, u8 val) {
  if (limit < 9) {
    return -1;
  }
  buf[0] = static_cast<u8>(Codes::kWrite8);
  write_u32(buf + 1, addr);
  write_u32(buf + 5, val);
  *written = 9;
}
int WriteData16(u8* buf, u32* written, u32 limit, u32 addr, u16 val) {}
int WriteData32(u8* buf, u32* written, u32 limit, u32 addr, u32 val) {}
int WriteKernel(u8* buf, u32* written, u32 limit, u32 addr, u32 val) {}
int ReadKernel(u8* buf, u32* written, u32 limit, u32 addr) {}
int Write(u8* buf, u32* written, u32 limit, u32 addr, u8* data, u32 size) {}
int Read(u8* buf, u32* written, u32 limit, u32 addr, u32 size) {}
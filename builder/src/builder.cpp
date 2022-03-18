#include <string.h>

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
  return 0;
}
int WriteData16(u8* buf, u32* written, u32 limit, u32 addr, u16 val) {
  if (limit < 9) {
    return -1;
  }
  buf[0] = static_cast<u8>(Codes::kWrite16);
  write_u32(buf + 1, addr);
  write_u32(buf + 5, val);
  *written = 9;
  return 0;
}
int WriteData32(u8* buf, u32* written, u32 limit, u32 addr, u32 val) {
  if (limit < 9) {
    return -1;
  }
  buf[0] = static_cast<u8>(Codes::kWrite32);
  write_u32(buf + 1, addr);
  write_u32(buf + 5, val);
  *written = 9;
  return 0;
}
int WriteKernel(u8* buf, u32* written, u32 limit, u32 addr, u32 val) {
  if (limit < 9) {
    return -1;
  }
  buf[0] = static_cast<u8>(Codes::kKernelWrite);
  write_u32(buf + 1, addr);
  write_u32(buf + 5, val);
  *written = 9;
  return 0;
}
int ReadKernel(u8* buf, u32* written, u32 limit, u32 addr) {
  if (limit < 5) {
    return -1;
  }
  buf[0] = static_cast<u8>(Codes::kKernelRead);
  write_u32(buf + 1, addr);
  *written = 5;
  return 0;
}
int Write(u8* buf, u32* written, u32 limit, u32 addr, u8* data, u32 size) {
  if (limit < 1 + 4 + 4 + size) {
    return -1;
  }
  buf[0] = static_cast<u8>(Codes::kUploadMemory);
  write_u32(buf + 1, addr);
  write_u32(buf + 5, addr + size);
  memcpy(buf + 9, data, size);
  *written = 1 + 4 + 4 + size;
  return 0;
}
int Read(u8* buf, u32* written, u32 limit, u32 addr, u32 size) {
  if (limit < 1 + 4 + 4 + 4) {
    return -1;
  }
  buf[0] = static_cast<u8>(Codes::kReadMemory);
  write_u32(buf + 1, addr);
  write_u32(buf + 5, addr + size);
  write_u32(buf + 9, 1);
  *written = 1 + 4 + 4 + 4;
  return 0;
}
int ReadData(u8* buf, u32* written, u32 limit, u32 addr, u32 size) {
  if (limit < 1 + 4 + 4) {
    return -1;
  }
  buf[0] = static_cast<u8>(Codes::kReadDataMemory);
  write_u32(buf + 1, addr);
  write_u32(buf + 5, addr + size);
  *written = 1 + 4 + 4;
  return 0;
}
int ExecuteAssembly(u8* buf, u32* written, u32 limit, u32* code, u32 length) {
  u32 code_length = 4 * length;
  if (limit < 1 + 4 + code_length) {
    return -1;
  }
  buf[0] = static_cast<u8>(Codes::kExecuteAssembly);
  write_u32(buf + 1, code_length);
  for (u32 i = 0; i < length; i++) {
    write_u32(buf + 5 + 4 * i, code[i]);
  }
  *written = 1 + 4 + code_length;
  return 0;
}
#ifndef BUILDER_BUILDER
#define BUILDER_BUILDER

#include "types.hpp"

int WriteData8(u8* buf, u32 limit, u32 addr, u8 val);
int WriteData16(u8* buf, u32 limit, u32 addr, u16 val);
int WriteData32(u8* buf, u32 limit, u32 addr, u32 val);
int WriteData64(u8* buf, u32 limit, u32 addr, u8 size, u32 val);
int WriteKernel(u8* buf, u32 limit, u32 addr);

int ReadData8(u8* buf, u32 limit, u32 addr, u8 val);
int ReadData16(u8* buf, u32 limit, u32 addr, u16 val);
int ReadData32(u8* buf, u32 limit, u32 addr, u32 val);
int ReadData64(u8* buf, u32 limit, u32 addr, u8 size, u32 val);
int ReadKernel(u8* buf, u32 limit, u32 addr);

#endif
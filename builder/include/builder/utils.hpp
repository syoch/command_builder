#ifndef BUILDER_UTILS
#define BUILDER_UTILS

#include "types.hpp"

namespace builder::utils {
void write_u32(u8* buf, u32 x);
void write_u16(u8* buf, u16 x);

u32 read_u32(u8* buf);
u16 read_u16(u8* buf);
}  // namespace builder::utils

#endif
#ifndef BUILDER_BUILDER
#define BUILDER_BUILDER

#include "types.hpp"

#ifdef __cplusplus
extern "C" {
#endif

int WriteData8(u8* buf, u32* written, u32 limit, u32 addr, u8 val);
int WriteData16(u8* buf, u32* written, u32 limit, u32 addr, u16 val);
int WriteData32(u8* buf, u32* written, u32 limit, u32 addr, u32 val);

int WriteKernel(u8* buf, u32* written, u32 limit, u32 addr, u32 val);
int ReadKernel(u8* buf, u32* written, u32 limit, u32 addr);

int Write(u8* buf, u32* written, u32 limit, u32 addr, u8* data, u32 size);
int Read(u8* buf, u32* written, u32 limit, u32 addr, u32 size);
int ReadData(u8* buf, u32* written, u32 limit, u32 addr, u32 size);

int ExecuteAssembly(u8* buf, u32* written, u32 limit, u32* code, u32 length);

int GetSymbol(u8* buf, u32* written, u32 limit, u8 is_data,
              const char* rpl_name, u32 rpl_name_size, const char* symbol_name,
              u32 symbol_name_size);
int RemoteProcedureCall(u8* buf, u32* written, u32 limit, u32 addr,
                        u32 args[8]);

#ifdef __cplusplus
}
#endif

#endif
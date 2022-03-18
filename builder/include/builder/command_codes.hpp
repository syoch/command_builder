#ifndef BUILDER_COMMAND_CODES
#define BUILDER_COMMAND_CODES

#include "types.hpp"

namespace builder {
enum class Codes : u8 {
  kWrite8 = 0x01,
  kWrite16 = 0x02,
  kWrite32 = 0x03,

  kKernelWrite = 0x0B,
  kKernelRead = 0x0C,

  kReadMemory = 0x05,
  kReadDataMemory = 0x04,
  kUploadMemory = 0x41,

  kExecuteAssembly = 0x81,

  kGetSymbol = 0x71,
  kRemoteProcedureCall = 0x70
};
}  // namespace builder

#endif
// 7zHeader.cpp

#include "StdAfx.h"

#include "7zHeader.h"

namespace NArchive {
namespace N7z {

// secpack fork: custom archive signature ("SPK7" + 2 bytes).
// Must stay in sync with IS_SIGNATURE in 7zIn.cpp and k_Signature_Dec in 7zRegister.cpp.
Byte kSignature[kSignatureSize] = {'S', 'P', 'K', '7', 0x9E, 0xD1};
#ifdef Z7_7Z_VOL
Byte kFinishSignature[kSignatureSize] = {'S', 'P', 'K', '7', 0x9E, 0xD1 + 1};
#endif

// secpack fork: fixed mask applied to the 32-byte start header on disk
// (signature + version + CRC + next-header coordinates), so the file has no
// recognizable 7z header. See docs/format.md in the secpack repo.
Byte kSecpackHeaderMask[kSecpackHeaderMaskSize] =
{
  0xF9, 0xBC, 0xFA, 0x64, 0x45, 0x2A, 0xFE, 0x1B,
  0x3A, 0x67, 0x37, 0x1E, 0xA9, 0xB8, 0xA7, 0x3A,
  0x41, 0xCF, 0xCF, 0xC1, 0x3B, 0x15, 0x9F, 0xF6,
  0xF1, 0x06, 0x64, 0x79, 0x56, 0x8E, 0xBA, 0xD9
};

// We can change signature. So file doesn't contain correct signature.
// struct SignatureInitializer { SignatureInitializer() { kSignature[0]--; } };
// static SignatureInitializer g_SignatureInitializer;

}}

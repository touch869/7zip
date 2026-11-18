// 7zRegister.cpp

#include "StdAfx.h"

#include "../../Common/RegisterArc.h"

#include "7zHandler.h"

namespace NArchive {
namespace N7z {

// secpack fork: decoder-side signature must match kSignature in 7zHeader.cpp.
// Real secpack files mask the start header, so detection happens through the
// .spk extension (or an explicit -t7z) rather than the signature.
static Byte k_Signature_Dec[kSignatureSize] = {'S', 'P', 'K', '7', 0x9E, 0xD1};

REGISTER_ARC_IO_DECREMENT_SIG(
  "7z", "spk", NULL, 7,
  k_Signature_Dec,
  0,
    NArcInfoFlags::kFindSignature
  | NArcInfoFlags::kCTime
  | NArcInfoFlags::kATime
  | NArcInfoFlags::kMTime
  | NArcInfoFlags::kMTime_Default
  , TIME_PREC_TO_ARC_FLAGS_MASK(NFileTimeType::kWindows)
  | TIME_PREC_TO_ARC_FLAGS_TIME_DEFAULT(NFileTimeType::kWindows)
  , NULL)

}}

// Copyright 2014 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "src/machine-type.h"
#include "src/ostreams.h"

namespace v8 {
namespace internal {

std::ostream& operator<<(std::ostream& os, MachineRepresentation rep) {
  return os << MachineReprToString(rep);
}

const char* MachineReprToString(MachineRepresentation rep) {
  switch (rep) {
    case MachineRepresentation::kNone:
      return "kMachNone";
    case MachineRepresentation::kBit:
      return "kRepBit";
    case MachineRepresentation::kWord8:
      return "kRepWord8";
    case MachineRepresentation::kWord16:
      return "kRepWord16";
    case MachineRepresentation::kWord32:
      return "kRepWord32";
    case MachineRepresentation::kWord64:
      return "kRepWord64";
    case MachineRepresentation::kFloat32:
      return "kRepFloat32";
    case MachineRepresentation::kFloat64:
      return "kRepFloat64";
    case MachineRepresentation::kSimd128:
      return "kRepSimd128";
    case MachineRepresentation::kSimd1x4:
      return "kRepSimd1x4";
    case MachineRepresentation::kSimd1x8:
      return "kRepSimd1x8";
    case MachineRepresentation::kSimd1x16:
      return "kRepSimd1x16";
    case MachineRepresentation::kTaggedSigned:
      return "kRepTaggedSigned";
    case MachineRepresentation::kTaggedPointer:
      return "kRepTaggedPointer";
    case MachineRepresentation::kTagged:
      return "kRepTagged";
  }
  UNREACHABLE();
}

std::ostream& operator<<(std::ostream& os, MachineSemantic type) {
  switch (type) {
    case MachineSemantic::kNone:
      return os << "kMachNone";
    case MachineSemantic::kBool:
      return os << "kTypeBool";
    case MachineSemantic::kInt32:
      return os << "kTypeInt32";
    case MachineSemantic::kUint32:
      return os << "kTypeUint32";
    case MachineSemantic::kInt64:
      return os << "kTypeInt64";
    case MachineSemantic::kUint64:
      return os << "kTypeUint64";
    case MachineSemantic::kNumber:
      return os << "kTypeNumber";
    case MachineSemantic::kAny:
      return os << "kTypeAny";
  }
  UNREACHABLE();
}


std::ostream& operator<<(std::ostream& os, MachineType type) {
  if (type == MachineType::None()) {
    return os;
  } else if (type.representation() == MachineRepresentation::kNone) {
    return os << type.semantic();
  } else if (type.semantic() == MachineSemantic::kNone) {
    return os << type.representation();
  } else {
    return os << type.representation() << "|" << type.semantic();
  }
  return os;
}

}  // namespace internal
}  // namespace v8

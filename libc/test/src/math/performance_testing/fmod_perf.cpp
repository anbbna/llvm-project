//===-- Differential test for fmod ----------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "PerfTest.h"
#include "src/math/fmod.h"

#include <math.h>

int main() {
  BINARY_INPUT_SINGLE_OUTPUT_PERF(double, double, LIBC_NAMESPACE::fmod, ::fmod,
                                  "fmod_perf.log")
  return 0;
}

// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 5
// RUN: %clang_cc1 -emit-llvm -triple aarch64-arm-none-eabi -target-feature -fp8 -target-feature +neon -o - %s | FileCheck %s --check-prefixes=CHECK,CHECK-C
// RUN: %clang_cc1 -emit-llvm -triple aarch64-arm-none-eabi -target-feature -fp8 -target-feature +neon -o -  -x c++ %s | FileCheck %s --check-prefixes=CHECK,CHECK-CXX

// REQUIRES: aarch64-registered-target


#include <arm_neon.h>

// CHECK-C-LABEL: define dso_local <16 x i8> @test_ret_mfloat8x16_t(
// CHECK-C-SAME: <16 x i8> [[V:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-C-NEXT:  [[ENTRY:.*:]]
// CHECK-C-NEXT:    [[V_ADDR:%.*]] = alloca <16 x i8>, align 16
// CHECK-C-NEXT:    store <16 x i8> [[V]], ptr [[V_ADDR]], align 16
// CHECK-C-NEXT:    [[TMP0:%.*]] = load <16 x i8>, ptr [[V_ADDR]], align 16
// CHECK-C-NEXT:    ret <16 x i8> [[TMP0]]
//
// CHECK-CXX-LABEL: define dso_local <16 x i8> @_Z21test_ret_mfloat8x16_tu14__MFloat8x16_t(
// CHECK-CXX-SAME: <16 x i8> [[V:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-CXX-NEXT:  [[ENTRY:.*:]]
// CHECK-CXX-NEXT:    [[V_ADDR:%.*]] = alloca <16 x i8>, align 16
// CHECK-CXX-NEXT:    store <16 x i8> [[V]], ptr [[V_ADDR]], align 16
// CHECK-CXX-NEXT:    [[TMP0:%.*]] = load <16 x i8>, ptr [[V_ADDR]], align 16
// CHECK-CXX-NEXT:    ret <16 x i8> [[TMP0]]
//
mfloat8x16_t test_ret_mfloat8x16_t(mfloat8x16_t v) {
  return v;
}

// CHECK-C-LABEL: define dso_local <8 x i8> @test_ret_mfloat8x8_t(
// CHECK-C-SAME: <8 x i8> [[V:%.*]]) #[[ATTR0]] {
// CHECK-C-NEXT:  [[ENTRY:.*:]]
// CHECK-C-NEXT:    [[V_ADDR:%.*]] = alloca <8 x i8>, align 8
// CHECK-C-NEXT:    store <8 x i8> [[V]], ptr [[V_ADDR]], align 8
// CHECK-C-NEXT:    [[TMP0:%.*]] = load <8 x i8>, ptr [[V_ADDR]], align 8
// CHECK-C-NEXT:    ret <8 x i8> [[TMP0]]
//
// CHECK-CXX-LABEL: define dso_local <8 x i8> @_Z20test_ret_mfloat8x8_tu13__MFloat8x8_t(
// CHECK-CXX-SAME: <8 x i8> [[V:%.*]]) #[[ATTR0]] {
// CHECK-CXX-NEXT:  [[ENTRY:.*:]]
// CHECK-CXX-NEXT:    [[V_ADDR:%.*]] = alloca <8 x i8>, align 8
// CHECK-CXX-NEXT:    store <8 x i8> [[V]], ptr [[V_ADDR]], align 8
// CHECK-CXX-NEXT:    [[TMP0:%.*]] = load <8 x i8>, ptr [[V_ADDR]], align 8
// CHECK-CXX-NEXT:    ret <8 x i8> [[TMP0]]
//
mfloat8x8_t test_ret_mfloat8x8_t(mfloat8x8_t v) {
  return v;
}

//// NOTE: These prefixes are unused and the list is autogenerated. Do not add tests below this line:
// CHECK: {{.*}}

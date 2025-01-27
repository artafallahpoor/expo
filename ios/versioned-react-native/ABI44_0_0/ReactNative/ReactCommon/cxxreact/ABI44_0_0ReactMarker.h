/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#ifdef __APPLE__
#include <functional>
#endif

namespace ABI44_0_0facebook {
namespace ABI44_0_0React {
namespace ABI44_0_0ReactMarker {

enum ABI44_0_0ReactMarkerId {
  NATIVE_REQUIRE_START,
  NATIVE_REQUIRE_STOP,
  RUN_JS_BUNDLE_START,
  RUN_JS_BUNDLE_STOP,
  CREATE_REACT_CONTEXT_STOP,
  JS_BUNDLE_STRING_CONVERT_START,
  JS_BUNDLE_STRING_CONVERT_STOP,
  NATIVE_MODULE_SETUP_START,
  NATIVE_MODULE_SETUP_STOP,
  REGISTER_JS_SEGMENT_START,
  REGISTER_JS_SEGMENT_STOP,
  ABI44_0_0REACT_INSTANCE_INIT_START,
  ABI44_0_0REACT_INSTANCE_INIT_STOP
};

#ifdef __APPLE__
using LogTaggedMarker =
    std::function<void(const ABI44_0_0ReactMarkerId, const char *tag)>;
using LogTaggedMarkerWithInstanceKey = std::function<
    void(const ABI44_0_0ReactMarkerId, const char *tag, const int instanceKey)>;
#else
typedef void (*LogTaggedMarker)(const ABI44_0_0ReactMarkerId, const char *tag);
typedef void (*LogTaggedMarkerWithInstanceKey)(
    const ABI44_0_0ReactMarkerId,
    const char *tag,
    const int instanceKey);
#endif

#ifndef ABI44_0_0RN_EXPORT
#define ABI44_0_0RN_EXPORT __attribute__((visibility("default")))
#endif

extern ABI44_0_0RN_EXPORT LogTaggedMarker logTaggedMarker;
extern ABI44_0_0RN_EXPORT LogTaggedMarkerWithInstanceKey logTaggedMarkerWithInstanceKey;

extern ABI44_0_0RN_EXPORT void logMarker(const ABI44_0_0ReactMarkerId markerId);

} // namespace ABI44_0_0ReactMarker
} // namespace ABI44_0_0React
} // namespace ABI44_0_0facebook

#pragma once

#include <cstdint>
#include "math\math.hpp"

using int8 = int8_t;
using int16 = int16_t;
using int32 = int32_t;
using int64 = int64_t;

using uint8 = uint8_t;
using uint16 = uint16_t;
using uint32 = uint32_t;
using uint64 = uint64_t;

using Byte = int8;
using uint = uint32;
using ushort = uint8;

using vec2 = silver::core::Vector2<float>;
using vec2f = vec2;
using vec2i = silver::core::Vector2<int32>;
using vec2ui = silver::core::Vector2<uint>;
using vec2us = silver::core::Vector2<ushort>;

using vec3 = silver::core::Vector3<float>;
using vec3f = vec3;
using vec3i = silver::core::Vector3<int32>;
using vec3ui = silver::core::Vector3<uint>;
using vec3us = silver::core::Vector3<ushort>;

using vec4 = silver::core::Vector4<float>;
using vec4f = vec4;
using vec4i = silver::core::Vector4<int32>;
using vec4ui = silver::core::Vector4<uint>;
using vec4us = silver::core::Vector4<ushort>;

using mat2 = silver::core::Matrix2<float>;
using mat3 = silver::core::Matrix3<float>;
using mat4 = silver::core::Matrix4<float>;
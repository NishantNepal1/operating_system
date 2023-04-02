#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <stdint.h>

typedef int32_t fixed_point;

#define FP_SHIFT 16

static inline fixed_point int_to_fp(int n) {
  return n << FP_SHIFT;
}

static inline int fp_to_int_round(fixed_point x) {
  return (x >= 0) ? (x + (1 << (FP_SHIFT - 1))) >> FP_SHIFT : (x - (1 << (FP_SHIFT - 1))) >> FP_SHIFT;
}

static inline int fp_to_int(fixed_point x) {
  return x >> FP_SHIFT;
}

static inline fixed_point fp_add(fixed_point x, fixed_point y) {
  return x + y;
}

static inline fixed_point fp_sub(fixed_point x, fixed_point y) {
  return x - y;
}

static inline fixed_point fp_mul(fixed_point x, fixed_point y) {
  return ((int64_t) x) * y >> FP_SHIFT;
}

static inline fixed_point fp_div(fixed_point x, fixed_point y) {
  return ((int64_t) x) << FP_SHIFT / y;
}
// Add these functions to your fixed_point.h

static inline fixed_point fixed_from_int(int n) {
  return int_to_fp(n);
}

static inline fixed_point fixed_add(fixed_point x, fixed_point y) {
  return fp_add(x, y);
}

static inline fixed_point fixed_sub(fixed_point x, fixed_point y) {
  return fp_sub(x, y);
}

static inline fixed_point fixed_mul(fixed_point x, fixed_point y) {
  return fp_mul(x, y);
}

static inline fixed_point fixed_div(fixed_point x, fixed_point y) {
  return fp_div(x, y);
}
#define F (1 << 14)

int fixed_to_int_nearest(int fixed_point_value) {
  if (fixed_point_value >= 0) {
    return (fixed_point_value + F / 2) / F;
  } else {
    return (fixed_point_value - F / 2) / F;
  }
}

#endif // FIXED_POINT_H

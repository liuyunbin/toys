#ifndef CPP_STANDARD_LIBRARY_CSTRING_STRNCPY_H_
#define CPP_STANDARD_LIBRARY_CSTRING_STRNCPY_H_

#include <stdio.h>

namespace liuyunbin {

/*
 * 函数原型：
 *   char* strncpy(char* dest, const char* src, size_t count);
 *
 * 函数说明：
 *   将 src 所指向的字符串（包括 '\0'），拷贝到 dest
 *     所指向的字符数组中，最多拷贝 count 个字符
 *
 * 参数要求：
 *   * src  所指向的字符数组不一定包含 '\0'
 *   * dest 所指向的字符数组的长度最小为：count
 *   * src 和 dest 所指向的字符数组不能重叠
 *
 * 返回说明：
 *   * 返回 dest，dest 所指向的字符数组最终不一定包含 '\0'
 *
 * 特别说明：
 *   * src 所指向的字符数组的长度小于 count，且 src 所指向的字符数组不包括
 *       '\0'，是未定义的行为
 *   * 当已复制了 src 的所有元素（包括 '\0'）时，个数却未到 count
 *       时，程序将继续填充 '\0'，直到 count 个字符
 *
 * 优化：
 *   * 如果，dest 和 src 的值相同，则无需复制
 *   * 如果，count <= 0，则无需复制
 */

char *strncpy(char *dest, const char *src, size_t count) {
  if (dest == src || count <= 0)
    return dest;

  for (size_t i = 0; i != count; ++i) {
    dest[i] = src[i];
    if (dest[i] == '\0') {
      while (++i != count)
        dest[i] = '\0';
      break;
    }
  }

  return dest;
}

} // namespace liuyunbin

#endif
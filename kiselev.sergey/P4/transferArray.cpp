#include "transferArray.h"
void kiselev::transferArr(char* arr, char* fromArr, size_t k)
{
  for (size_t i = 0; i < k; ++i)
  {
    arr[i] = fromArr[i];
  }
}

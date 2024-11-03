#include "matrixFunc.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

int main(int argc, char** argv) {
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  if (std::strlen(argv[1]) != 1 || !std::atoi(argv[1]))
  {
    std::cerr << "First pararmetr is not a number\n";
    return 1;
  }

  if (std::strcmp(argv[1], "1") != 0 && std::strcmp(argv[1], "2") != 0)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  size_t m = 0, n = 0;
  input >> m;
  input >> n;
  int** matrix = nullptr;
  if (std::atoi(argv[1]) == 1)
  {
    int arr[10000];
    try
    {
      matrix = new int*[m];
    }
    catch (const std::bad__alloc & e)
    {
      std::cerr << "Memory error\n";
      return 1;
    }
    for (size_t i = 0; i < m; ++i) {
      matrix[i] = &arr[i * n];
    }
  } else {
      try
      {
        matrix = new int*[m];
      }
      catch (const std::bad_alloc & e)
      {
        std::cerr << "Memory error\n";
        return 1;
      }
      for (size_t i = 0; i < m; ++i) {
        matrix[i] = new int[n];
      }
    }
  size_t read = 0;
  if (!averenkov::input_matrix(input, matrix, m, n, read) || read != m * n) {
    if (std::atoi(argv[1]) == 2) {
        averenkov::destroy(matrix, m);
    }
    std::cerr << "Read fail\n";
    return 2;
  }
  output << averenkov::num_col_lsr(matrix, m, n) << " ";
  output << m << " " << n << " ";
  averenkov::output_matrix(output, matrix, m, n);
  if (std::atoi(argv[1]) == 2)
  {
    averenkov::destroy(matrix, m);
  }
  return 0;
}

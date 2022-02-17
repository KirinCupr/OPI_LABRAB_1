#include <iostream>
#include <stdlib.h>
#include <ctime>

struct number{
  int row;
  int column;
};

void initialization_array(int **f_array, int f_rows, int f_columns);
void fill_array(int **f_array, int f_rows, int f_columns);
void print_array(int **f_array, int f_rows, int f_columns);
number searh_of_min_in_area(int **f_array, int f_rows, int f_columns);


int main() {
  const int rows{10}, columns{10};

  int **array = new int *[rows];
  for (int i = 1; i <= rows; i++) {
    array[i] = new int[columns];
  }

  initialization_array(array, rows, columns);

  fill_array(array, rows, columns);

  print_array(array, rows, columns);
  std::cout << '\n';

  number min_number = searh_of_min_in_area(array, rows, columns);

  std::cout << "Min number: row - " << min_number.row << " , column - " << min_number.column << '\n';

  print_array(array, rows, columns);
  std::cout << '\n';

  return 0;
}



 void initialization_array(int **f_array, int f_rows, int f_columns){
 for (int i = 1; i <= f_rows; i++) {
   f_array[i] = new int[f_columns];
 }
}

void fill_array(int **f_array, int f_rows, int f_columns){
  srand(1408);
  for (int i = 1; i <= f_rows; i++) {
    for (int j = 1; j <= f_columns; j++) {
      f_array[i][j] = rand() % 31 - 15;
    }
  }
}

void print_array(int **f_array, int f_rows, int f_columns){
  for (int i = 1; i <= f_rows; i++) {
    for (int j = 1; j <= f_columns; j++) {
      std::cout << f_array[i][j] << '\t';
        }
      std::cout << '\n';
    }
}

number searh_of_min_in_area(int **f_array, int f_rows, int f_columns){
  int i{}, j{};
  int f_min_value = 16;

  number f_min_number{};
  //bool condition = (i <= j) && (i + j >= f_rows + 1);

  for (i = 1; i <= f_rows; i++) {
    for (j = 1; j <= f_columns; j++) {
      if ((i >= j) && (i + j <= f_rows + 1)) {
        if (f_min_value > f_array[i][j]) {
          f_min_value = f_array[i][j];
          f_min_number.row = i;
          f_min_number.column = j;
          std::cout << f_min_number.row << '\t' << f_min_number.column << '\n';
        }
        f_array[i][j] = 0;
      }
    }
  }
  return f_min_number;
}

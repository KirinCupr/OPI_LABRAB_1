#include <iostream>
#include <stdlib.h>
#include <ctime>

void initialization_array(int **f_array, int f_pows, int f_columns);
void fill_array(int **f_array, int f_pows, int f_columns);
void print_array(int **f_array, int f_pows, int f_columns);
int searh_of_min_in_area(int **f_array, int f_pows, int f_columns);


int main() {
  const int pows{10}, columns{10};

  int **array = new int *[pows];
  for (int i = 1; i <= pows; i++) {
    array[i] = new int[columns];
  }

  initialization_array(array, pows, columns);

  fill_array(array, pows, columns);

  print_array(array, pows, columns);
  std::cout << '\n' << '\n';

  std::cout << searh_of_min_in_area(array, pows, columns) << '\n';

  return 0;
}

 void initialization_array(int **f_array, int f_pows, int f_columns){
 for (int i = 1; i <= f_pows; i++) {
   f_array[i] = new int[f_columns];
 }
}

void fill_array(int **f_array, int f_pows, int f_columns){
  srand(time(nullptr));
  for (int i = 1; i <= f_pows; i++) {
    for (int j = 1; j <= f_columns; j++) {
      f_array[i][j] =  rand() % 31 - 15;
    }
  }
}

void print_array(int **f_array, int f_pows, int f_columns){
  for (int i = 1; i <= f_pows; i++) {
    for (int j = 1; j <= f_columns; j++) {
      std::cout << f_array[i][j] << '\t';
        }
      std::cout << '\n';
    }
}

int searh_of_min_in_area(int **f_array, int f_pows, int f_columns){
  int i{}, j{};
  int f_min_value = f_array[0][0];

  bool condition = (i <= j) && (i <= f_pows + 1 - j);

  for (i = 1; i <= f_pows; i++) {
    for (j = 1; j <= f_columns; j++) {
      if (condition && (f_array[i][j] < f_min_value)) {
        f_min_value = f_array[i][j];
      }
    }
  }
  return f_min_value;
}

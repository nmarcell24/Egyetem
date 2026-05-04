// kodstilus.cpp
// Demonstrates Google C++ Style Guide compliance.

#include <iostream>

// A record holding two integer fields.
struct Record {
  int first;
  int second;
};

// Sorts an array of Records in ascending order by the 'first' field
// using bubble sort.
void BubbleSort(Record* records, int length) {
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length - 1; j++) {
      if (records[j].first > records[j + 1].first) {
        int tmp = records[j].first;
        records[j].first = records[j + 1].first;
        records[j + 1].first = tmp;

        tmp = records[j].second;
        records[j].second = records[j + 1].second;
        records[j + 1].second = tmp;
      }
    }
  }
}

void PrintDoubleLine() { std::cout << "===\n"; }
void PrintSingleLine() { std::cout << "---\n"; }
void PrintOutputLabel() { std::cout << "Output:\n"; }

// Computes and prints a value for each Record based on the parity of its
// fields.
void PrintComputedValues(const Record* records, int size) {
  for (int i = 0; i < size; i++) {
    int r = records[i].first;
    int u = records[i].second;
    int result;
    if (r % 2 == 0) {
      if (u % 2 == 0) {
        result = r * u;
      } else {
        result = r + u;
      }
    } else {
      if (u % 2 == 0) {
        result = r - u;
      } else {
        result = r;
      }
    }
    std::cout << result << '\n';
  }
}

// Sorts the records, then prints headers and computed values.
void ProcessAndPrint(Record* records, int length) {
  BubbleSort(records, length);
  PrintDoubleLine();
  PrintOutputLabel();
  PrintSingleLine();
  PrintComputedValues(records, length);
}

int main() {
  Record records[5] = {
    {5, 1},
    {2, 4},
    {3, 7},
    {1, 6},
    {4, 5},
  };
  ProcessAndPrint(records, 5);
  return 0;
}
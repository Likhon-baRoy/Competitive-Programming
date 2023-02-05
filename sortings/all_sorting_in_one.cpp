#include <bits/stdc++.h>
using namespace std;

void selectionSort(int[], int);
void bubbleSort(int[], int);
void insertionSort(int[], int);
void insertionSortByRecursion(int[], int, int);
void backTrace(int[], int);
void insertionSortByKey(int[], int);
void insertionSortDescend(int[], int);
void mergeSort(int[], int, int);
void merge(int[], int, int, int);
void quickSort(int[], int, int);
int partition(int[], int, int);
int linearSearch(int[], int, int);
int binarySearch(int[], int, int);
int recursiveBinarySearch(int[], int, int, int);
void swap(int *, int *);
void print(int[], int);

int main() {

  int n, len, key, userChoice = 0, index, x, y;
  int a[] = {5, 4, 3, 2, 1};
  len = sizeof(a) / sizeof(int);

  printf("Before Sort : ");
  print(a, len);

  printf("[*] Select your Sorting Method :\n 1) SelectionSort 2) BubbleSort 3) "
         "InsertionSort 4) MergeSort 5) QuickSort : ");
  scanf("%d", &userChoice);

  switch (userChoice) {
  case 1:
    selectionSort(a, len);
    break;
  case 2:
    bubbleSort(a, len);
    break;
  case 3:
    insertionSort(a, len);
    // insertionSortByRecursion(a, 1, len);
    // insertionSortByKey(a, len);
    // insertionSortDescend(a, len);
    break;
  case 4:
    mergeSort(a, 0, len - 1);
    break;
  case 5:
    quickSort(a, 0, len);
    break;
  default:
    printf("\n\t\t*** You've Chosen Wrong Option ***\n\t\t*** Please! Try "
           "Again... *** \n\n");
    return 0;
  }

  printf("\nAfter Sort : ");
  print(a, len);

  printf("Would You Like to Search for an Element? (y/n) : ");
  char ch;
  cin >> ch;
  if (ch == 'y') {
    int key;
    printf("Now enter your Element here : ");
    scanf("%d", &key);
    // index = binarySearch(a, len, key);
    index = recursiveBinarySearch(a, 0, len - 1, key);
    if (index == -1)
      printf("Opps!\nyour data isn't in the list.\n");
    else
      printf("Found in : Array[%d]\n", index);
  } else {
    printf("Thank You <3\n");
  }

  return 0;
}
void selectionSort(int a[], int len) {
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (a[i] > a[j]) {
        swap(a[i], a[j]);
      }
    }
  }
}
void bubbleSort(int a[], int len) {
  bool flag;
  do {
    flag = false;
    for (int i = 0; i < len - 1; i++) {
      if (a[i] > a[i + 1]) {
        swap(a[i], a[i + 1]);
        flag = true;
      }
    }
  } while (flag);
}
void insertionSort(int a[], int len) {
  for (int i = 1; i < len; i++) {
    for (int j = i; j > 0 && (a[j] < a[j - 1]); j--) {
      swap(a[j], a[j - 1]);
    }
  }
}
void insertionSortByRecursion(int a[], int i, int len) {
  if (i < len) {
    backTrace(a, i++);
    insertionSortByRecursion(a, i, len);
  }
}
void backTrace(int a[], int len) {
  for (int j = len; j > 0 && (a[j] < a[j - 1]); j--) {
    swap(a[j], a[j - 1]);
  }
}
void insertionSortDescend(int a[], int len) {
  for (int i = len - 1; i > 0; i--) {
    for (int j = i; j < len && (a[j - 1] < a[j]); j++) {
      swap(a[j], a[j - 1]);
    }
  }
}
void insertionSortByKey(int a[], int len) {
  bool flag = true;
  for (int i = len - 1; i > 0; i--) {
    int j = i;
    int key = a[j];
    for (; j > 0 && (a[j - 1] > key); j--) {
    }
    a[i] = a[j];
    a[j] = key;
  }
}
void mergeSort(int a[], int first, int last) {
  if (first < last) {
    int mid = first + (last - first) / 2;
    mergeSort(a, first, mid);
    mergeSort(a, mid + 1, last);

    merge(a, first, mid, last);
  }
}
void merge(int a[], int first, int mid, int last) {
  // int n = sizeof(a) / sizeof(int);
  // int tempArray[MAX_SIZE];
  int tempArray[last + 1];
  int first1, first2, last1, last2, index;

  first1 = first;
  last1 = mid;
  first2 = mid + 1;
  last2 = last;

  index = first1;
  while ((first1 <= last1) && (first2 <= last2)) {
    if (a[first1] <= a[first2]) {
      tempArray[index] = a[first1];
      first1++;
    } else {
      tempArray[index] = a[first2];
      first2++;
    }
    index++;
  }
  while (first1 <= last1) {
    tempArray[index++] = a[first1++];
  }
  while (first2 <= last2) {
    tempArray[index++] = a[first2++];
  }
  for (index = first; index <= last; index++) {
    a[index] = tempArray[index];
  }
}
void quickSort(int a[], int first, int last) {
  /*
    if (last - first + 1 < SIZE_MIN) {
    insertionSort(a, last);
    }
  */
  if (first < last) {
    int j = partition(a, first, last);
    quickSort(a, first, j);
    quickSort(a, j + 1, last);
  }
}
int partition(int a[], int first, int last) {
  int pivot = a[first];
  int i = first, j = last;
  while (i < j) {
    do {
      i++;
    } while (a[i] <= pivot);
    do {
      j--;
    } while (a[j] > pivot);
    if (i < j) {
      swap(a[i], a[j]);
    }
  }
  swap(a[first], a[j]);
  return j;
}
int linearSearch(int *a, int len, int key) {
  for (int i = 0; i < len; ++i) {
    if (key == a[i]) {
      return i;
    }
  }
  return -1;
}
int binarySearch(int a[], int len, int key) {
  int first = 0, last = len - 1, mid;
  while (first <= last) {
    mid = first + (last - first) / 2;
    if (a[mid] == key)
      return mid;
    else if (a[mid] > key)
      last = mid - 1;
    else
      first = mid + 1;
  }
  return -1;
}
int recursiveBinarySearch(int a[], int first, int last, int key) {
  if (first > last)
    return -1;

  // Otherwise (first <= last)
  int mid = first + (last - first) / 2;
  if (a[mid] == key)
    return mid;
  else if (a[mid] > key)
    return recursiveBinarySearch(a, first, mid - 1, key);
  else
    return recursiveBinarySearch(a, mid + 1, last, key);
}
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void print(int a[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d, ", a[i]);
  }
  printf("\n\n");
}

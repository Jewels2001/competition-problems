
int* globalPtr;

int *countNegatives(int *A) {
  if(A != nullptr){
    globalPtr = A;
  }
  while(*globalPtr >= 0) {
    if(*globalPtr == 100000){
      return nullptr;
    }
    globalPtr++;
  }
  return globalPtr++;
}

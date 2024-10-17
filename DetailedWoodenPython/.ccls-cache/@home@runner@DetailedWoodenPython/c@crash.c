void main() {
  unsigned char *ptr;
  int i;
  ptr = (unsigned char *) 0x0;
  for(i = 0; i < 1024; i++) {
    ptr[i] = 0x0;
  }
  return;
}
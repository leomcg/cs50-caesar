#include <stdio.h>

#include <cs50.h>

#include <string.h>

#include <stdlib.h>

#include <ctype.h>

bool check_valid_key(string s);

int main(int argc, string argv[]) {
  if (argc != 2 || argv[1] < 0 || !check_valid_key(argv[1])) {
    printf("error");
    return 1;
  }
  int key = atoi(argv[1]);
  string s = get_string("plaintext: ");
  int n = strlen(s);
  printf("ciphertext: ");
  for (int i = 0; i < n; i++) {
    char c = s[i];
    if (isalpha(c)) {
      char m = 'A';
      if (islower(c))
        m = 'a';
      printf("%c", (c - m + key) % 26 + m);
    } else
      printf("%c", c);
  }
  printf("\n");
  return 0;

}

bool check_valid_key(string s) {
  for (int i = 0, len = strlen(s); i < len; i++)
    if (!isdigit(s[i]))
      return false;

  return true;

}
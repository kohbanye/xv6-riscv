#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int main() {
  char buf[32];

  int fd = open("test.txt", O_WRONLY | O_CREATE);
  write(fd, "hello", 5);
  lseek(fd, 0, SEEK_SET);
  write(fd, "!", 1);
  close(fd);

  fd = open("test.txt", O_RDONLY);
  read(fd, buf, 32);
  printf("%s\n", buf);
  close(fd);

  fd = open("test.txt", O_WRONLY | O_TRUNC);
  write(fd, "hello", 5);
  lseek(fd, -2, SEEK_CUR);
  write(fd, "!", 1);
  close(fd);

  fd = open("test.txt", O_RDONLY);
  read(fd, buf, 32);
  printf("%s\n", buf);
  close(fd);

  fd = open("test.txt", O_WRONLY | O_TRUNC);
  write(fd, "hello", 5);
  lseek(fd, 5, SEEK_END);
  write(fd, "!", 1);
  close(fd);

  fd = open("test.txt", O_RDONLY);
  read(fd, buf, 32);
  printf("%s\n", buf);
  close(fd);

  exit(0);
}

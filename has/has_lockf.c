#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define TEST_FILE "junk"

int
main(void)
{
  char buffer[64];
  int fd = open(TEST_FILE, O_CREAT | O_RDWR);
  if (fd < 0) {
    perror("open(\"" TEST_FILE "\", O_CREAT | O_RDWR);");
    return(1);
  }
  if (unlink(TEST_FILE) < 0) {
    perror("unlink(\"" TEST_FILE "\");");
  }
  int result = lockf(fd, F_TLOCK, 0);
  if (result) {
    sprintf(buffer, "lockf(%d, F_TLOCK, 0);", fd);
    perror(buffer);
  }
  close(fd);
  return(result);
}

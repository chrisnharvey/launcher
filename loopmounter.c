/*

Copyright (c) 2004-16 Simon Peter

All Rights Reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mount.h>

int main(int argc, char* argv[]) {

  // Become root
  setuid(0);

  // As root, unmount if we get 1 argument
  if(argc == 2)
  {
    if (0 == umount2(argv[1], MNT_DETACH | UMOUNT_NOFOLLOW)) {
      return EXIT_SUCCESS;
    } else {
      return EXIT_FAILURE;
    }
  }

  // As root, mount if we get 2 arguments
  // TODO: Replace the call to "mount" with mount(2)
  // But it doesn't seem to do loop-mounting so this might get complex
  if(argc == 3)
  {
    if( access( "/bin/mount", F_OK ) != -1 ) {
      execl ("/bin/mount", "/bin/mount", "-o", "loop,ro", argv[1], argv[2], NULL);
    } else if( access( "/usr/bin/mount", F_OK ) != -1 ) {
      execl ("/usr/bin/mount", "/usr/bin/mount", "-o", "loop,ro", argv[1], argv[2], NULL);
    }
  }

}

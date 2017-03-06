#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  printf("Hi, I'm %s\n", argv[0]); /* The first "argument" is the path-to-self */

  if(argc != 2) { /* argc is how long argv is, including that path-to-self */
    puts("You need to give me exactly one argument!");
    return -1;
  }

  /* if statements, character and string constants, && and ||, and
   * comparisions work a lot like Java or any other language. */
  if(argv[1][0] == 't') {
    if(argv[1][1] == 'h' && argv[1][2] == 'i' && argv[1][3] == 's') {

      /* In C, characters are just numbers from 0 to 255. */
      if(argv[1][4] == 95 && argv[1][5] == 105 && argv[1][6] == 0x73) {
        puts("half way there!");
        if(argv[1][7] != 0x5f) return 0;

        /* Since characters are just numbers, we can bit-flip them! */
        if(argv[1][8] != ~'t' || argv[1][9] != ~'h' || argv[1][10] != ~'e') {
          puts("noooo!");
          return 0;
        }

        /* Lastly, "strings" are really just pointers to characters.
         * argv[1][11] is the 12th character of argv[1]. So, &argv[1][11]
         * points at that 12th character, which in C is basically just
         * the argv[1] string from the 12th character onwards. */
        if(strcmp("_pass\x99word", &argv[1][11]) == 0) {
          /* strcmp returns 0 if the strings match, and non-zero if
           * they don't. You can type `man strcmp` (without backticks)
           * at the terminal to get more detailed information on strcmp. */
          puts("yep, that's it!");
          system("sh -i");
          return 0;
        }
      }
    }
  }
  puts("nope!");
  return 0;
}

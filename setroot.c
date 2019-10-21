/*   ****** setroot.c   **********
 *
 * This program will set the real user id and then execute the command
 * that follows on the command line.
 *
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

main(argc, argv)
int argc;
char **argv;

{
++argv;
#ifdef _HPUX_SOURCE
setresuid(0,0);
#else
setreuid(0,0);
#endif
execvp(*argv, argv);
fprintf(stderr, "can't execute\n");
exit(1);
}
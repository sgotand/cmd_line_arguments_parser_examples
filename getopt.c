#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//extern char *optarg;
//extern int optind,opterr,optopt;


int main(int argc, char *argv[]) {
  int flags, opt;
  int nsecs, tfnd;

  nsecs = 0;
  tfnd = 0;
  flags = 0;
  while ((opt = getopt(argc, argv, "nt:O::W;")) != -1) {
    switch (opt) {
    case 'n':
      flags = 1;
      break;
    case 't':
      printf("%s\n",optarg);
      nsecs = atoi(optarg);
      tfnd = 1;
      break;
    case 'O':
      if(optarg)printf("%s\n",optarg);
      else printf("hello");
      break;
    case 'W':
      if(optarg)printf("%s\n",optarg);
      else printf("helloW");
      break;
    case '1':
    case 'l':
      while(optarg)printf("%s\n",optarg++);
      break;
    default: /* '?' */
      fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  }
//Then optind is the index in argv of the first argv-element that is not an option.
//オプション以降の引数はargv[optind]で参照

  printf("flags=%d; tfnd=%d; nsecs=%d; optind=%d\n", flags, tfnd, nsecs,
         optind);

  if (optind >= argc) {
    fprintf(stderr, "Expected argument after options\n");
    exit(EXIT_FAILURE);
  }

  printf("name argument = %s\n", argv[optind]);

  /* Other code omitted */

  exit(EXIT_SUCCESS);
}


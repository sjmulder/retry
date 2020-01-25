#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <getopt.h>
#include <err.h>

static const char usage[] =
"usage: retry [-c count] [-w delay] command ...\n";

int
main(int argc, char **argv)
{
	int c, i, st, delay=1, count=0;
	pid_t pid;

	while ((c = getopt(argc, argv, "c:w:")) != -1) {
		switch (c) {
		case 'c': count = strtol(optarg, NULL, 10); break;
		case 'w': delay = strtol(optarg, NULL, 10); break;
		default: fputs(usage, stderr); return 1;
		}
	}

	if (count < 0) errx(1, "invalid -c");
	if (delay < 1) errx(1, "invalid -w");

	argc -= optind; argv += optind;
	if (!argc) { fputs(usage, stderr); return 1; }

	for (i = 0; !count || i < count; i++) {
		if ((pid = fork()) == -1) err(1, "fork");
		if (!pid) { execvp(argv[0], &argv[0]); err(1, "%s",
		    argv[0]); }
		if (wait(&st) == -1) err(1, "wait");
		if (st == 0) return 0;
		sleep(delay);
	}

	return 2;
}

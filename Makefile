DESTDIR   ?=
PREFIX    ?= /usr/local
MANPREFIX ?= $(PREFIX)/man

CFLAGS += -Wall -Wextra

all: retry
install: all
	install -d $(DESTDIR)$(PREFIX)/bin $(DESTDIR)$(MANPREFIX)/man1
	install -m755 retry $(DESTDIR)$(PREFIX)/bin/
	install -m644 retry.1 $(DESTDIR)$(MANPREFIX)/man1/
uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/retry \
	      $(DESTDIR)$(MANPREFIX)/man1/retry.1
clean:
	rm -f retry

.PHONY: all clean

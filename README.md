retry
=====
Persistently try to run a command

**retry** [**-w** *delay*] [**-c** *count*] *command* ...

Invokes the given *command* until it succeeeds (or at most count times
if given), waiting *delay* seconds between invocations (1 by default).

Exits with 0 if succesful, 1 if an error occurs, 2 if count is exceeded.

Installing
----------
Should work on most Unix systems, including Linux, BSD and macOS.

    make
    make install   [DESTIDR=] [PREFIX=/usr/local] [MANPREFIX=PREFIX/man]
    make uninstall [DESTIDR=] [PREFIX=/usr/local] [MANPREFIX=PREFIX/man]

Author
------
By Sijmen J. Mulder (<ik@sjmulder.nl>)

fixenv
====================

A script to make stack addresses the same when running a program under gdb,ltrace,strace or without debugging (without ASLR of course).
Env variables order is saved too.

Usage
---------------------

<pre>
Usage:
  ./r.sh getvar [var_name] - get address of envvar's value
  ./r.sh dump [start_addr [size]] - dump the end of the stack

Running programs:
  ./r.sh ./program - run program
  ./r.sh strace ./program - run program in strace
  ./r.sh ltrace ./program - run program in ltrace
  ./r.sh gdb ./program [arg1 [arg2 [ ... ]]] - run program in gdb
</pre>

Example
---------------------

<pre>
$ ./r.sh gdb test/test
...
Local var: 0xbffffa5c
Env vars:
0xbffffc5f SHELL=/bin/bash
...

$ ./r.sh strace test/test 2>/dev/null
Local var: 0xbffffa5c
Env vars:
0xbffffc5f SHELL=/bin/bash
...

$ ./r.sh test/test 
Local var: 0xbffffa5c
Env vars:
0xbffffc5f SHELL=/bin/bash

$ export XYZ=SOMEDATA
$ ./r.sh getvar XYZ
0xbffffcb8  \xb8\xfc\xff\xbf  (XYZ)
$ ./r.sh test/test | grep XYZ
0xbffffcb4 XYZ=SOMEDATA
</pre>

Author: hellman ( hellman1908@gmail.com )

License: GNU General Public License v2 (http://opensource.org/licenses/gpl-2.0.php)

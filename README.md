cds_sync
========

This
[single header file](https://github.com/nothings/stb/blob/master/docs/other_libs.md)
C90 library provides a portable collection of synchronization
primitives for use in multithreaded programming - by [Cort Stratton](https://codeberg.org/cdwfs). The following
primitives are provided:

- `cds_sync_futex_t` -- A [futex](https://en.wikipedia.org/wiki/Futex)
  (fast userspace [mutex](https://en.wikipedia.org/wiki/Mutex)),
  guaranteed to stay in userspace code unless a thread must be put to
  sleep or awakened.
- `cds_sync_fusem_t` -- A fast userspace
  [semaphore](https://en.wikipedia.org/wiki/Semaphore_%28programming%29),
  guaranteed to stay in userspace code unless a thread must be put to
  sleep or awakened.
- `cds_sync_monitor_t` -- A
  [monitor](https://en.wikipedia.org/wiki/Monitor_%28synchronization%29),
  which bundles a condition variable and its associated mutex.
- `cds_sync_eventcount_t` -- An
  [event count](http://cbloomrants.blogspot.com/2011/07/07-08-11-who-ordered-event-count.html)
  which lets callers safely avoid waiting unless there's actually no
  work to do.
- `cds_sync_monsem_t` -- A
  [monitored semaphore](http://cbloomrants.blogspot.com/2015/05/05-16-15-threading-primitive-monitored.html),
  which builds on the basic semaphore by allowing a master thread to
  wait for the semaphore to have a certain positive non-zero value.
- `cds_sync_barrier_t` -- Lets users specify a barrier that all
  threads must reach before any thread can proceed.

<br>

Installation
------------

Run:

```sh
$ npm i cds_sync.c
```

And then include `cds_sync.h` as follows:

```c
// main.c
#define CDS_SYNC_IMPLEMENTATION
#include <cds_sync.h>

int main() { /* ... */ }
```

Finally, compile while adding the path `node_modules/cds_sync.c` to your compiler's include paths.

```bash
$ clang -I./node_modules/cds_sync.c main.c  # or, use gcc
$ gcc   -I./node_modules/cds_sync.c main.c
```

You may also use a simpler approach with the [cpoach](https://www.npmjs.com/package/cpoach.sh) tool, which automatically adds the necessary include paths of all the installed dependencies for your project.

```bash
$ cpoach clang main.c  # or, use gcc
$ cpoach gcc   main.c
```

<br>

Key Features / Design Goals
---------------------------
- **Identical API on all supported platforms**. The following
  platforms are tested regularly:
  - Microsoft Windows 7
    - Visual Studio 2010
    - Visual Studio 2012
    - Visual Studio 2013
  - Linux Mint
    - LLVM/Clang 3.5
    - gcc 4.8.4
  - Apple OSX
    - Apple LLVM/Clang 6.1.0
- **No (mandatory) external dependencies**. Only standard C library
  functions are used, and even those can be overriden with custom
  implementations through `#define`s if desired.
- **Dirt-simple integration**. Just a single header file to include in
your project.
- **Public domain license terms**.

<br>

Acknowledgements
----------------
- [Sean Barrett](http://nothings.org/): master of single-header C libraries.
- [Charles Bloom](http://cbloomrants.blogspot.com/): poster of sync primitives; ranter.
- [Allen B. Downey](http://www.allendowney.com/): author of [The Little Book of Semaphores](http://greenteapress.com/semaphores/index.html).

<br>
<br>


[![](https://raw.githubusercontent.com/qb40/designs/gh-pages/0/image/11.png)](https://wolfram77.github.io)<br>
[![ORG](https://img.shields.io/badge/org-nodef-green?logo=Org)](https://nodef.github.io)
![](https://ga-beacon.deno.dev/G-RC63DPBH3P:SH3Eq-NoQ9mwgYeHWxu7cw/github.com/nodef/cds_sync.c)

# Kyunix
Kyunix is experimental operating system written from scratch in C.

Aimed to be POSIX compliant, combining ideas of unix like systems and modern software practices.

Currently based on aenix.


## Dependencies
- [GCC](http://gcc.gnu.org/)
- [NASM](http://www.nasm.us/)
- [genisoimage](http://cdrkit.org/)
- [bochs](http://bochs.sourceforge.net/)
- [Make](http://www.gnu.org/software/make/)
- package libc6-dev-i386

If you are running Ubuntu 10.10 or later, these can all be installed by running

    sudo apt-get install build-essential nasm genisoimage bochs bochs-x

## Building

    cd src
    make
## Implemented Features:
* fb driver.
* Serial COM1 kernel logging.
* elf binary support.
* segmentation/paging.
* dynamic memory allocation, malloc/free.
* Interrupts and Input.
* kernel and usermode applications.
* system calls
* read-only file system
* multitasking
* shell (basic command parsing)
* libc
                  
## Planned
Core:
* networking (ip stack)
* vesa graphics card driver
* compostive GUI (GEM stack)
* fancy splash screen
* Multiprocessor/core support, SMP
* self healing features
* real file system,ide driver
* os installation on physical hdd
Apps:
* text editor.
* process manager.
* man pages.
* irc client.
* gcc port.


## Running

    cd src
    make run

## Documentation

Can be found in docs.

## License
[GPLv3](http://www.gnu.org/licenses/gpl.html)

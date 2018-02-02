Labsec's undergraduate challenge
================================

This is a project currently under development. Please submit your sugestions :)
- - -


# Introduction
This exercise is designed to evaluate how you can handle C++ programming.
You are not required to have experience with cryptography. The code you
are about to write uses a cryptographic C++ library maintained by undergraduate
students at LabSEC. It is partially documented in Portuguese and should't be
hard to use. The exercise is supposed to be easy to start with and
challenge you gradually as you progress. There are 6 Milestones
to be completed in sequence. Each Milestone requires the previous to work.
An evaluation tool is available to get you started. This tool will evaluate the
first three (3) milestones. For the remainder of the exercise you are on your
own. We recomend that you use this evaluation tool, building your own tests.


**IMPORTANT**

From previous experiences, we have noticed that most students can't complete
all the milestones. You shouldn't worry if you haven't finished the exercise.
Submiting your code is more important, since it is the only way that we can
evaluate your work.

**Please contact us if you need help.**
- - -

# Evaluation

What do we expect from the code you submit?

* Good coding practices:
  * Correct use of *header* and *cpp* files;
  * Naming conventions;
  * Clear and short code (create you own private functions):
* Exception handling;
* Implementing your own tests for Milestones 4, 5 and 6:
  * Code coverage;
  * Output correctness.

- - -

# Installation

We recommend any 32its Linux distributions for the exercise. Running on a
64bits OS will require some tweaks described bellow. Windows is not permitted! :)

## OpenSSL
OpenSSL is an open source project that will provide all
cryptografic functions needed to complete this exercise.

Download the latest version of [OpenSSL](https://www.openssl.org/).


If you are running a 32bits OS, run the following commands:


    $ ./config shared
    $ make
    $ sudo make install


If you are running a 64bits OS, run the following commands:

    $ CFLAGS=-fPIC ./config shared
    $ make
    $ sudo make install

Check if your installation is working:

    $ /user/local/ssl/bin/openssl version
    OpenSSL 1.0.2c 12 Jun 2015

## LibcryptoSec
Since OpenSSL is writen in C and very hard to work with, we have developed
an Object Oriented C++ wrapper of OpenSSL. We call it LibCryptoSec! It is
currently under development and was written entirely by undergraduate and
graduate students. We hope you can contribute someday!


Before installing Libcryptosec, you need to install OpenSSL first. If you haven't done so, please head back to the
[OpenSSL](#openssl) section.


Download the [latest version](https://github.com/LabSEC/libcryptosec)
and check the [documentation page](https://labsec.github.io/libcryptosec/).


If you are running a 32bits OS, run the following commands:

    $ make
    $ sudo make install

If you are running a 64bits OS, do the following steps:


Edit Libcryptosec's Makefile:
* Add **-fPIC** to the CC flag: `CC = g++ -fPIC`;
* At line 100, replace "g++ $(INCLUDES)..." with "$(CC) $(INCLUDES)...".

run:

    $ make
    $ sudo make install

Check if your installation is working:

    $ cd tests/
    $ make test

Output should be a list of HMAC and Brainpool tests running 100% OK

Error when runing make test? try the following:


If make can't find libcryptosec.so and you are using a 64bit OS:
* Move `/usr/lib/libcryptosec.so` to `/usr/lib64/libcryptosec.so`;
* Edit Libcryptosec's test Makefile. Change the path to *libcryptosec.so* to `/usr/lib64`.

If make can't resolve Libcryptosec's includes (evp.h or any other OpenSSL header):
* Add `-I/usr/local/ssl/include` to the `INCLUDES= ..` flag in the test Makefile.


check if istallation is working again. If not, contact us.

The installation was tested with Ubuntu 15.04 and Fedora 22 successfully.
- - -

# Running your code


To run all tests at once, run:

    $ cd evaluation/
    $ make evaluate

To run a single milestone, run:

    $ cd evaluation/
    $ make first
    $ make second
    $ make third
    $ make fourth
    $ make fifth
    $ make sixth

The evaluation tool uses
[Google's C++ Testing Framework](https://code.google.com/p/googletest/).
The last 3 Milestones tests are not implemented. The tests ready to run
but will **FAIL** by default. You will have to implement these tests using
Google's API.
- - -

# Getting Started

Start by reading the documentation inside the header files of each Milestone.
You will implement your code in the cpp files and use header files if needed.
All of the variables available should be used. Don't forget to implement **FIleIo**
class inside the *utils* folder. Also, the **TRACE(x)** macro is available to help
debug when needed.
- - -

# contact

Please contact me at <mailto:lucas.perin@posgrad.ufsc.br> if you have any questions.

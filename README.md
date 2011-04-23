# laniidae -- A (currently WIP) cross-platform PS1 emulator.

This program is "Free and Open Source Software" (FOSS) under the FreeBSD License
(also known as the 2-clause BSD license), see the docs/LICENSE file for the details.

The development tree can be found on [GitHub][].
[github]: http://github.com/dkingston/laniidae/

#### TABLE OF CONTENTS
* Presentation
* Installation
* Documentation
* Contact and support

PRESENTATION
------------

I am writing this emulator specifically as an exercise in emulation.
Yeah, that implies this is my first attempt at an emulator.
Any help is appreciated in the form of patches or feature suggestions.

Currently, there is support for only Qt as the GUI framework, but there are
planned ports to the following frameworks:

* Native Windows
* Native Mac OS X (Cocoa)
* GTK
* Wx

laniidae has also only been tested on Linux, more tests on other systems will be
conducted in the future.

INSTALLATION
------------

You need the SCons build system.  You may download and install SCons at
http://scons.org/download.php, or if you are on a Unix(-like) system, you may
use your package manager to download SCons instead.

The current GUI framework used is Qt, so you also must install that.  You may
download and install Qt at http://qt.nokia.com/downloads, or if you are on a
Unix(-like) system, you may use your package manager to download Qt instead.

Once you have all of the required prerequisites, run the command "scons"
(without quotes) in the root directory tree.  This will build the project and
generate a standalone executable.  Finally, run "scons install" (without
quotes) to install it.

Depending on your operating system, the installation method will be as follows:

* Unix(-like) -- Installs to ~/laniidae, directory tree is as followed:
                     bin/<executable>
                     etc/
                     cdimages/
                     memcards/

Run ~/laniidae/bin/laniidae to start the first-time setup wizard and start
playing your games.

DOCUMENTATION
-------------

Due to FOSS's stunning lack of documentation, you will find the code is extremely
well documented, both the GUI and the core.

CONTACT AND SUPPORT
-------------------

Okay, I code this program, for MY purposes.  If you find a use for it, then
that is fine, but I do not mind helping people who want to use this program.
You may find me on IRC on `irc.freenode.net` on channel `#laniidae`.  Any one in
that channel who has channel operator status is a developer or a trusted
contributor, and any one who have voice status is a trusted helper.  This isn't
to say that people who try to help you who have no channel status have no clue
what they are talking about, though.

Well... thats about it. Enjoy.

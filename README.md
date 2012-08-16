Improved shell for ComputerCraft
--------------------------------

This is a more advanced version of the standard ComputerCraft shell application.

It's still in development, thus some functionality may be broken. Also because of this, the code may be messy in places.

Currently working features:

  - Autocompletion with Tab key
  - History (similar to how it works in the default shell)
  - Editing the text on the command line
  - Most programs should run like in the normal CC shell
  - Basic globbing (Currently supports *, behaves similar to *nix shells, see below)
  - Output redirection to file (Similar to bash, using `foo > out` or `foo >> out`)

Planned features:

  - History search (bash ctrl-r style)

Possible features at some point:

  - Piping
  - Input redirection

Running jhsh as the default CC shell
------------------------------------

The current way to replace your default shell with jhsh is as follows:

  - Create a directory in `/rom` called `autorun`
  - Place `jhsh` into `/rom/autorun`

This depends on the feature of the default startup script of the OS localted in `/rom/startup` which
runs every program in the autorun dir.

Globbing
--------

The globbing functionality behaves in a similar way as globbing does in *nix shells.

If you run the following command:

    cp *.jpg foo

It will get expanded into

    cp file1.jpg file2.jpg file3.jpg foo

Assuming the directory contains file1, file2 and file3.

So in order to make your application compatible with globbing, you will need to have multi parameter
arguments similar to how most *nix utils do. (Or you can use the expand function in jhsh directly)

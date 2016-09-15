# AppImage Launcher

Simple launcher to make it easier to download and run AppImages.

## How it works

AppImage Launcher allows [AppImages](http://appimage.org) to run without marking them executable. It starts by mounting the AppImage and looking for a ```.sandbox``` file. If this file is found then the AppImage is run inside the [Firejail](https://firejail.wordpress.com/) sandbox. If the file contains the word ```strict``` then the AppImage is run inside Firejail with the ```---private``` flag set.

If the AppImage does not contain a ```.sandbox``` file. Then the user is prompted that the app they are trying to run is potentially unsafe and gives the user the option to continue running the app or not.

# AppImage Launcher

Copyright (c) 2016 Nimbusoft Ltd

Simple launcher to make it easier to download and run AppImages.

Icon made by [Pixel Buddha](http://www.flaticon.com/authors/pixel-buddha "Pixel Buddha") from [www.flaticon.com](http://www.flaticon.com "Flaticon") is licensed by [CC 3.0 BY](http://creativecommons.org/licenses/by/3.0/ "Creative Commons BY 3.0")

## How it works

AppImage Launcher allows [AppImages](http://appimage.org) to run without marking them executable. It starts by mounting the AppImage and looking for a ```.sandbox``` file. If this file is found then the AppImage is run inside the [Firejail](https://firejail.wordpress.com/) sandbox. If the file contains the word ```strict``` then the AppImage is run inside Firejail with the ```---private``` flag set.

If the AppImage does not contain a ```.sandbox``` file. Then the user is prompted that the app they are trying to run is potentially unsafe and gives the user the option to continue running the app or not.

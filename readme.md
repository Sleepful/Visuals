# Visuals ~

This repo must be inside OpenFramework's library folder in order to compile the programs

i.e. install OpenFrameworks then place this repository at openFrameworks/apps/[thisrepo]

# useful commands 

make: build project
make run: run project
make copy_dlls: copies dlls from project (if running with msys2)

# to install OF

clone OF repo, then run the install scripts at openFrameworks/scripts and add this repo as submodule

# to run on windows with msys2 installed 

add to windows path:
* c:\msys64\mingw32\bin (or mingw64 depending)
* c:\msys64\usr\bin
in order for windows to find the dlls without having to use `make copy_dlls`
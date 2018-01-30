# libmcseedcpp
libmcseedcpp is a project of C++ library implementing Minecraft's seed
generation. It should give the exact same output as Minecraft, no
matter what obscure UTF-16 character you choose to try to break it.

## building tests
This library requires [libmcjavacpp](https://github.com/cylgom/libmcjavacpp)
to work: simply clone it, then compile it and move the shared library to
libmcseedcpp's build dir. You can now compile libmcseedcpp and run the
tests as explained below.

## running tests
Remember to prefix your command with the library path upon testing:
```
LD_LIBRARY_PATH="/home/user/path/to/dir/libmcjavacpp/build/libmcjavacpp.so"
```

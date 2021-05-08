# TMShell
Time machine shell

Read `LangSpec.md` for more information on the language.

## Build
The `CMakeLists.txt` is only for compiling with Visual Studio 2019 (msvc v142). The linking are static to 3rd party libs (antlr and boost, included in the repo).

To build, In powershell, run:
```shell
mkdir build
cd build
cmake ..
cmake --build . --config Release
```
And `tmshelld.exe` and `tmshell.exe` will be compiled to `build/Release/`. 

## Run
Run `tmshelld.exe` first, it will run a websocket server on localhost(currently ipv4 only), and it is also the event dispatcher.
`tmshell.exe` is the client. 

You can directly open "tmshell.exe" for interactive mode. 

You can also run `tmshell.exe <filename1> <filename2> ... ` to run tmshell scripts. In this mode, client will exit when the files finish running.



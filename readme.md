[![Build Status](https://travis-ci.org/AdrienJarretier/CamlCompiler.svg?branch=master)](https://travis-ci.org/AdrienJarretier/CamlCompiler)


## How to use
 - `programName --test` launch test
 - `programName --help` see commands

## Dependencies
- [googleTest](https://github.com/google/googletest)

## Install
On linux

```
sudo chmod 775 dependencies.sh
sudo ./dependencies.sh;
make all
```

On Mac OS

```
sudo chmod 775 dependencies_mac.sh
sudo ./dependencies_mac.sh;
make -f makefile.mac
```
- That's it !

##Compilation
 - add flag `-thread` in compilation instruction if you choose to use an IDE

# DLLLoader

A DLL that loads more DLLs, just to make DLL injection easier

## Compile

`cl /LD DLLLoader.cpp`

## Configure

Edit the `Paths` section of `DLLLoader.ini`

Starting from `0`, add entries like:

```
[Paths]
0=DLL1.dll
1=DLL2.dll
...
```

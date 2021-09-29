# Switch vs function pointer performance

Simple benchmark to test the performance of executing random instructions in a VM-ish environment where there is typically a range of instruction codes defined and their implementation is called by a large switch statement or by looking up function pointers from an array.

## Setup

The test has 3 different setups for instruction sets of 32, 64 and 128 main instruction types

## Quick performance overview
```
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Sandbox.exe is a Catch v3.0.0-preview.3 host application.
Run with -? for options

-------------------------------------------------------------------------------
Random indirect call (32 instruction types)
-------------------------------------------------------------------------------
A:\Projects\switch_fp_comparison\TestTemplate.h:23
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Switch Inline                                  100             1     28.407 ms 
                                        287.475 us    284.135 us    292.314 us 
                                        20.3942 us    15.7979 us    29.3641 us 
                                                                               
a == 1706428809
b == 12

Function table                                 100             1    29.1348 ms 
                                         287.25 us    286.282 us    289.384 us 
                                        6.97722 us    3.36966 us    11.6497 us 
                                                                               
a == 1706428809
b == 12


-------------------------------------------------------------------------------
Random indirect call (64 instruction types)
-------------------------------------------------------------------------------
A:\Projects\switch_fp_comparison\TestTemplate.h:23
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Switch Inline                                  100             1    29.2808 ms 
                                        296.625 us    293.703 us    301.866 us 
                                        19.3753 us    12.7173 us     30.478 us 
                                                                               
a == -817253111
b == 76

Function table                                 100             1    29.8629 ms 
                                        295.438 us    293.535 us    298.957 us 
                                        12.8171 us    8.36316 us    21.4801 us 
                                                                               
a == -817253111
b == 76


-------------------------------------------------------------------------------
Random indirect call (128 instruction types)
-------------------------------------------------------------------------------
A:\Projects\switch_fp_comparison\TestTemplate.h:23
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Switch Inline                                  100             1    30.5169 ms 
                                        333.252 us    324.703 us    344.176 us 
                                        49.1605 us    40.1165 us    59.4141 us 
                                                                               
a == -1573530743
b == 204

Function table                                 100             1    30.9732 ms 
                                         345.33 us    328.871 us    379.221 us 
                                        115.458 us    69.0734 us    215.904 us 
                                                                               
a == -1573530743
b == 204


===============================================================================
test cases: 3 | 3 passed
assertions: - none -
```

- Processor	Intel(R) Core(TM) i5-8600K CPU @ 3.60GHz, 3600 Mhz, 6 Core(s), 6 Logical Processor(s)
- Compiled using:
```
C:\msys64\mingw64\bin\g++.exe  @CMakeFiles/Sandbox.dir/includes_CXX.rsp -O3 -DNDEBUG -MD -MT CMakeFiles/Sandbox.dir/main.cpp.obj -MF CMakeFiles\Sandbox.dir\main.cpp.obj.d -o CMakeFiles\Sandbox.dir\main.cpp.obj -c A:\Projects\switch_fp_comparison\main.cpp
C:\msys64\mingw64\bin\g++.exe -O3 -DNDEBUG -Wl,--whole-archive CMakeFiles\Sandbox.dir/objects.a -Wl,--no-whole-archive -o Sandbox.exe -Wl,--out-implib,libSandbox.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles\Sandbox.dir\linklibs.rsp
```
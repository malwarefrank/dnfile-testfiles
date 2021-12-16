This directory contain examples of mixed-mode executables:

## EmptyClass

These executables have been built with the C compiler `cl` and a netmodule file built with the C# compiler `csc` and linked together using the `CLRIMAGETYPE:IJW` flag. This produces a sample that some tools may assume is a .NET assembly has no code visible in dnSpy. Unlike `ModuleCode`, the two source projects used to build `EmptyClass` do not interact with each other.

## ModuleCode

This project is more complex to get setup, but allows for managed and unmanaged code to live in the same source file. The drawback is the source code is easily seen in dnSpy by looking under the Module class. 

## references

[The Wover's Mixed Assemblies](https://thewover.github.io/Mixed-Assemblies/)  
[Call managed code from your C++ code](https://docs.microsoft.com/en-us/archive/blogs/calvin_hsia/call-managed-code-from-your-c-code)
[CVE-2019-18935 using Mixed Assemblies for delivery](https://github.com/noperator/CVE-2019-18935)  
[Native and .NET Interoperability](https://docs.microsoft.com/en-us/cpp/dotnet/native-and-dotnet-interoperability?view=msvc-170)
This directory contains a number of .NET modules with unusual string constants:

  - `unpaired-surrogate`: references a string constant with an unpaired UTF-16 surrogate
  - `raw-binary`: references a string constant containing a raw binary MZ header
  - `string-decoder`: uses a routine to XOR decode a string constant at runtime

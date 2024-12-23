## Overview
base_definitions.h provides basic definitions and utility macros designed for embedded systems frameworks. It includes essential macros for common operations, such as timeout calculations, bit manipulation, and value clamping. The header also defines basic status codes, standard variable types, and some common enumerations used in embedded systems development.

## Features

### Macros:

- `iTIMEOUT`: Calculate timeout based on start, current, and timeout values.
- `UNUSED`: Mark a variable as unused to avoid compiler warnings.
- `ARRAY_SIZE`: Get the size of an array.
- `MIN, MAX, CLAMP`: Utility macros to find the minimum, maximum, or clamp a value within a range.
Bit manipulation macros: `SET_BIT, CLEAR_BIT, TOGGLE_BIT, IS_BIT_SET, IS_BIT_CLEAR`.

### Enumerations:

- `i_status`: Defines various status codes used for general operation, memory and alignment, access and permissions, activity states, and debug purposes.
- `var_type`: Defines standard variable types, including integers and arrays of integers of various sizes.

## Dependencies
This header file relies on standard C libraries:

```
<stdint.h>
<stdbool.h>
<stddef.h>
<limits.h>
```
Ensure that your build system links these libraries correctly.

## License
This software is licensed under the MIT License. See the LICENSE file for details.


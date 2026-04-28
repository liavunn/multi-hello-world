![Static Badge](https://img.shields.io/github/v/release/liavunn/multi-hello-world?color=E0FFFF)

[简体中文](README_zh_CN.md) | English
# Multi Hello World

>Display 'Hello World' in the corresponding language based on the country code entered by the user.

## Requirements
- **C compiler** (e.g., `clang`,`gcc`)
- **Standard C Library** (`libc`)
- **Tested on** `clang` version 14.0.6

## Structure
- `main.c`:Core logic.
- `data.c`:Data source.
- `data.h`:Header definition.

## How to Run
Compile and run the program using the following commands:
```bash
make
./Hello-World
```

## License
[GPL-3.0](LICENSE)

### About
>**My First C Project**
>This is my first C programming project, completed at age 14.
>Follows **Google C Style Guide**.

 ---

> **v1.0.0**
>  - Core features implemented.
>  - Currently supported languages:
>    - `zh_CN`,  `zh_TW` (Chinese),
>    - `en_US`, `en_GB` (English),
>    - `es_ES` (Spanish), `fr_FR` (french),
>    - `ja_JP` (Japanese) ,`ru_RU` (Russian),
>    - `de_DE` (German), `pt_BR` (Portuguese).
> 
>    Default languages: `en_US` (English).
> 
> *Completed on March 23, 2026*
 
---
 
> **v1.1.0**
>  - Added case-insensitive input support.
>  - Automatic system locale detection.
>
> *Completed on April 6, 2026*

---

> **v1.2.0**
>  - Moved logic listing, input, and validation logic into `data.h/c`. 
>  - Added `utils.h/c` for better modularity.
>
> *Completed on April 19, 2026*

---

> **v2.0.0**
>  - Migrated all naming to PascalCase for consistency.
>  - Implemented Hash-based INI parser with multi-section support.
>  - Added Makefile for streamlined compilation.
>  - Enhanced error handling for configuration recovery and memory safety. 
>
> *Completed on April 28, 2026*


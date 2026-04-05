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
clang main.c data.c -o Hello-World
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
>*Completed on March 23, 2026*

 ---


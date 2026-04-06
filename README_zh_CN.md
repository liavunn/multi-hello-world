![Static Badge](https://img.shields.io/github/v/release/liavunn/multi-hello-world?color=E0FFFF)

[English](README.md) | 简体中文

# 多语言你好世界

>根据用户输入的国家代码显示对应语言的 'Hello World

## 运行环境
- C 编译器 （`clang`, `gcc`等）
- 标准 C 库  (`libc`)
- 测试环境 clang 14.0.6 版本成功编译并运行

## 结构
- `main.c`:核心逻辑
- `data.c`:数据源实现
- `data.h`:头文件定义

## 如何运行
使用以下命令编译并运行程序：
```bash
clang main.c data.c -o Hello-world
./Hello-World
```

## 开源协议
[GPL-3.0](LICENSE)

### 关于
>**我的第一个 C 语言项目**
>这是我的首个 C 语言编程项目，完成于 14 岁。
>遵循 **Google C 语言代码规范**。

 ---

> **v1.0.0**
>  - 实现核心功能。
>  - 支持语言:
>    - `zh_CN`,  `zh_TW` (中文),
>    - `en_US`, `en_GB` (英文),
>    - `es_ES` (西班牙语), `fr_FR` (法语),
>    - `ja_JP` (日语) ,`ru_RU` (俄语),
>    - `de_DE` (德语), `pt_BR` (巴西葡萄牙语)。
>
>    默认语言: `en_US` (英语)。
>
> *完成于2026年3月23日*

 ---

> **v1.1.0**
>  - 加入大小写不敏感。
>  - 添加自动获取系统语言作为备用。
>
> *完成与2026年4月6日*

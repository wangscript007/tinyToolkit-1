# 简介

  * tinyToolkit是为减少编码工作而封装的简易工具套件, 不同工具代码之间无相互依赖关系, 可单独提取源码使用

# 要求

  * 标准特性
    - c++11

  * 构建工具
    - cmake 3.0 

# 系统

  * MacOS
  * Kylin
  * CentOS
  * Debian
  * Fedora
  * RedHat
  * Ubuntu
  * OpenWrt
  * Windows
  * OpenSUSE
  * OracleLinux

# 安装

  ```shell
  cmake . -B build -DCMAKE_BUILD_TYPE=Release [-DCMAKE_INSTALL_PREFIX=PREFIX]
  cmake --build   build --config Release
  cmake --install build --config Release
  ```

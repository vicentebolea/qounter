# Qounter (QT days counter) [![C/C++ CI](https://github.com/vicentebolea/Qounter/workflows/C/C++%20CI/badge.svg?branch=master)](https://github.com/vicentebolea/Qounter/actions?query=workflow%3A%22C%2FC%2B%2B+CI%22)

---

![](https://github.com/vicentebolea/qounter/raw/master/qounter.png)

---

# TRY IT

You can try it in Docker by:

```
sudo docker run -ti --rm -e DISPLAY=unix$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix vbolea/qounter
```

# INSTALL

1. Install Qt:
  - Ubuntu/Debians
```
     sudo apt-get install qt5-default pkg-config qttools5-dev-tools
```
  - OpenSUSE
```
     sudo zypper in -t pattern devel_qt5 pkg-config
```
2. Compile and Install
```
    make && sudo make install
```

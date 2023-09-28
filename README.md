<p align="center">
      <img src="https://i.ibb.co/vdydkBk/cpp-img.jpg" alt="cpp_template_project" width="300">
</p>


---

## About

Purpose of this repo: show how to link GTest and create some unit tests.

---

## Requirements
* C++ version: `C++11`
* Build system: [`CMake`](https://cmake.org/)
* C++ compiler: `g++`
* Code coverage report: [`lcov`](http://ltp.sourceforge.net/coverage/lcov.php)
* Package manager: [`Conan`](https://conan.io/downloads) or
* Test framework: [`gtest`](https://github.com/google/googletest)

---

## Run programm in docker

* Install docker and pull image of ubuntu: `./scripts/docker_setup.sh` (if you already have docker, then just do `docker pull ubuntu:22.04`)

* Build app in docker: `./scripts/docker_build.sh`

* Run unit tests in docker: `./scripts/docker_test.sh`


## Run programm locally

* Install dependencies: `./scripts/install_dep.sh`
* Build project: `./scripts/build.sh`
* Run unit tests: `./scripts/test.sh`
---

## Developers

- [Renat](https://github.com/khatymov)

---

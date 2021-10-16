from conans import ConanFile, CMake

class Quaternion(ConanFile):
    name = "Quaternion"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    requires = "gtest/cci.20210126"
    
    generators = "cmake", "cmake_find_package"

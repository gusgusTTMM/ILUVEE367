cmake_minimum_required(VERSION 2.8.8)
project(iLUVEE367)
include_directories(${MY_SOURCE_DIR})
add_executable(net367 main.c man.c host.c net.c packet.c main.c switch.c)
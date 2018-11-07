cmake_minimum_required(VERSION 3.0)

project(brain_test)

set (SRC_DIR ../../src)

set (SIM_HDR 
  ${SRC_DIR}/SupportTypes.h
  ${SRC_DIR}/Brain.h
)

set (SIM_SRC 
  ${SRC_DIR}/Brain.cpp
)
add_executable(brain_test brain_test.cpp ${SIM_HDR} ${SIM_SRC})

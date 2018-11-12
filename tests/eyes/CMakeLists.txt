cmake_minimum_required(VERSION 3.0)

project(eyes_test)

set (SRC_DIR ../../src)

set (SIM_HDR 
  ${SRC_DIR}/SupportTypes.h
  ${SRC_DIR}/IdGenerator.h
  ${SRC_DIR}/Animal.h
  ${SRC_DIR}/Carnivor.h
  ${SRC_DIR}/Herbivor.h
  ${SRC_DIR}/Brain.h
  ${SRC_DIR}/Eyes.h
  ${SRC_DIR}/LivingOrganisms.h
  ${SRC_DIR}/Plant.h
  ${SRC_DIR}/World.h
)

set (SIM_SRC 
  ${SRC_DIR}/IdGenerator.cpp
  ${SRC_DIR}/Animal.cpp
  ${SRC_DIR}/Carnivor.cpp
  ${SRC_DIR}/Herbivor.cpp
  ${SRC_DIR}/Brain.cpp
  ${SRC_DIR}/Eyes.cpp
  ${SRC_DIR}/LivingOrganisms.cpp
  ${SRC_DIR}/Plant.cpp
  ${SRC_DIR}/World.cpp
)
add_executable(eyes_test eyes_test.cpp ${SIM_HDR} ${SIM_SRC})

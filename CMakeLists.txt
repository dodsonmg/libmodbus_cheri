cmake_minimum_required(VERSION 3.5)
project(libmodbus_cheri)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(libmodbus REQUIRED)

add_library(modbus_cheri SHARED
            src/modbus_cheri.c
            )

target_include_directories(modbus_cheri PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

try_compile(HAVE_CHERI ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/have_cheri.c)

if(HAVE_CHERI)
  target_compile_definitions(modbus_cheri PRIVATE MACAROONS_LAYER=1 CHERI_LAYER=1)
else()
  target_compile_definitions(modbus_cheri PRIVATE MACAROONS_LAYER=1)
endif()

ament_target_dependencies(modbus_cheri libmodbus)

ament_export_interfaces(export_modbus_cheri HAS_LIBRARY_TARGET)

install(
  DIRECTORY include/
  DESTINATION include
)

install(
  TARGETS modbus_cheri
  EXPORT export_modbus_cheri
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

ament_export_include_directories(include)
ament_export_libraries(modbus_cheri)

ament_package()
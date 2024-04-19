# Install script for directory: E:/Builds/redis-plus-plus-1.3.12

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/redis++")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "E:/Builds/redis-plus-plus-1.3.12/build/Debug/redis++_static.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "E:/Builds/redis-plus-plus-1.3.12/build/Release/redis++_static.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "E:/Builds/redis-plus-plus-1.3.12/build/MinSizeRel/redis++_static.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "E:/Builds/redis-plus-plus-1.3.12/build/RelWithDebInfo/redis++_static.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/Builds/redis-plus-plus-1.3.12/build/Debug/redis++.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/Builds/redis-plus-plus-1.3.12/build/Release/redis++.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/Builds/redis-plus-plus-1.3.12/build/MinSizeRel/redis++.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/Builds/redis-plus-plus-1.3.12/build/RelWithDebInfo/redis++.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/Builds/redis-plus-plus-1.3.12/build/Debug/redis++.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/Builds/redis-plus-plus-1.3.12/build/Release/redis++.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/Builds/redis-plus-plus-1.3.12/build/MinSizeRel/redis++.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/Builds/redis-plus-plus-1.3.12/build/RelWithDebInfo/redis++.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/redis++/redis++-targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/redis++/redis++-targets.cmake"
         "E:/Builds/redis-plus-plus-1.3.12/build/CMakeFiles/Export/7d81f1912f64acc9d7f7c51a1b3ceb40/redis++-targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/redis++/redis++-targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/redis++/redis++-targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/redis++" TYPE FILE FILES "E:/Builds/redis-plus-plus-1.3.12/build/CMakeFiles/Export/7d81f1912f64acc9d7f7c51a1b3ceb40/redis++-targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/redis++" TYPE FILE FILES "E:/Builds/redis-plus-plus-1.3.12/build/CMakeFiles/Export/7d81f1912f64acc9d7f7c51a1b3ceb40/redis++-targets-debug.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/redis++" TYPE FILE FILES "E:/Builds/redis-plus-plus-1.3.12/build/CMakeFiles/Export/7d81f1912f64acc9d7f7c51a1b3ceb40/redis++-targets-minsizerel.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/redis++" TYPE FILE FILES "E:/Builds/redis-plus-plus-1.3.12/build/CMakeFiles/Export/7d81f1912f64acc9d7f7c51a1b3ceb40/redis++-targets-relwithdebinfo.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/redis++" TYPE FILE FILES "E:/Builds/redis-plus-plus-1.3.12/build/CMakeFiles/Export/7d81f1912f64acc9d7f7c51a1b3ceb40/redis++-targets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/sw/redis++" TYPE FILE FILES
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/cmd_formatter.h"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/command.h"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/command_args.h"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/command_options.h"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/connection.h"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/connection_pool.h"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/cxx17/sw/redis++/cxx_utils.h"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/errors.h"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/hiredis_features.h"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/pipeline.h"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/queued_redis.h"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/queued_redis.hpp"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/redis++.h"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/redis.h"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/redis.hpp"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/redis_cluster.h"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/redis_cluster.hpp"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/redis_uri.h"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/reply.h"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/sentinel.h"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/shards.h"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/shards_pool.h"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/subscriber.h"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/tls/sw/redis++/tls.h"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/transaction.h"
    "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/utils.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/sw/redis++/patterns" TYPE FILE FILES "E:/Builds/redis-plus-plus-1.3.12/src/sw/redis++/patterns/redlock.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/redis++" TYPE FILE FILES
    "E:/Builds/redis-plus-plus-1.3.12/build/cmake/redis++-config.cmake"
    "E:/Builds/redis-plus-plus-1.3.12/build/cmake/redis++-config-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "E:/Builds/redis-plus-plus-1.3.12/build/cmake/redis++.pc")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("E:/Builds/redis-plus-plus-1.3.12/build/test/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "E:/Builds/redis-plus-plus-1.3.12/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")

# Install script for directory: /home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "default")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3.45-netsimulyzer-default.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3.45-netsimulyzer-default.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3.45-netsimulyzer-default.so"
         RPATH "/usr/local/lib:$ORIGIN/:$ORIGIN/../lib:/usr/local/lib64:$ORIGIN/:$ORIGIN/../lib64")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/build/lib/libns3.45-netsimulyzer-default.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3.45-netsimulyzer-default.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3.45-netsimulyzer-default.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3.45-netsimulyzer-default.so"
         OLD_RPATH "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/build/lib:"
         NEW_RPATH "/usr/local/lib:$ORIGIN/:$ORIGIN/../lib:/usr/local/lib64:$ORIGIN/:$ORIGIN/../lib64")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libns3.45-netsimulyzer-default.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ns3" TYPE FILE FILES
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/helper/area-helper.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/helper/building-configuration-container.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/helper/building-configuration-helper.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/helper/logical-link-helper.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/helper/node-configuration-container.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/helper/node-configuration-helper.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/helper/throughput-sink-helper.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/library/json.hpp"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/model/event-message.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/model/log-stream.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/model/logical-link.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/model/netsimulyzer-3D-models.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/model/netsimulyzer-ns3-compatibility.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/model/netsimulyzer-version.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/model/node-configuration.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/model/optional.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/model/optional-types.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/model/building-configuration.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/model/category-axis.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/model/category-value-series.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/model/color.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/model/color-palette.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/model/decoration.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/model/ecdf-sink.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/model/orchestrator.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/model/rectangular-area.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/model/series-collection.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/model/state-transition-sink.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/model/value-axis.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/model/xy-series.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/contrib/netsimulyzer/model/throughput-sink.h"
    "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/build/include/ns3/netsimulyzer-module.h"
    )
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/home/nidhi/BUET /LABS/BUET-ACADEMICS/3-2 Sessionals/CSE 322/ns-allinone-3.45/ns-3.45/cmake-cache/contrib/netsimulyzer/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()

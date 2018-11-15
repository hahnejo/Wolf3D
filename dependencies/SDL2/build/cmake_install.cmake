# Install script for directory: /tmp/hjo/dependencies/SDL2

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/nfs/2018/h/hjo/.brew")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/tmp/hjo/dependencies/SDL2/build/libSDL2.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2.a")
    execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2.a")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/tmp/hjo/dependencies/SDL2/build/libSDL2.dylib")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2.dylib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2.dylib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2.dylib")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/tmp/hjo/dependencies/SDL2/build/libSDL2main.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2main.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2main.a")
    execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2main.a")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/SDL2.framework/Resources/SDL2Targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/SDL2.framework/Resources/SDL2Targets.cmake"
         "/tmp/hjo/dependencies/SDL2/build/CMakeFiles/Export/SDL2.framework/Resources/SDL2Targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/SDL2.framework/Resources/SDL2Targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/SDL2.framework/Resources/SDL2Targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/SDL2.framework/Resources" TYPE FILE FILES "/tmp/hjo/dependencies/SDL2/build/CMakeFiles/Export/SDL2.framework/Resources/SDL2Targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/SDL2.framework/Resources" TYPE FILE FILES "/tmp/hjo/dependencies/SDL2/build/CMakeFiles/Export/SDL2.framework/Resources/SDL2Targets-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/SDL2.framework/Resources" TYPE FILE FILES
    "/tmp/hjo/dependencies/SDL2/SDL2Config.cmake"
    "/tmp/hjo/dependencies/SDL2/build/SDL2ConfigVersion.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL2" TYPE FILE FILES
    "/tmp/hjo/dependencies/SDL2/include/SDL.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_assert.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_atomic.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_audio.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_bits.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_blendmode.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_clipboard.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_config_android.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_config_iphoneos.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_config_macosx.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_config_minimal.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_config_pandora.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_config_psp.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_config_windows.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_config_winrt.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_config_wiz.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_copying.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_cpuinfo.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_egl.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_endian.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_error.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_events.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_filesystem.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_gamecontroller.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_gesture.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_haptic.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_hints.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_joystick.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_keyboard.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_keycode.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_loadso.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_log.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_main.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_messagebox.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_mouse.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_mutex.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_name.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_opengl.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_opengl_glext.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_opengles.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_opengles2.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_opengles2_gl2.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_opengles2_gl2ext.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_opengles2_gl2platform.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_opengles2_khrplatform.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_pixels.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_platform.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_power.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_quit.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_rect.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_render.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_revision.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_rwops.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_scancode.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_sensor.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_shape.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_stdinc.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_surface.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_system.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_syswm.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_test.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_test_assert.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_test_common.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_test_compare.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_test_crc32.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_test_font.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_test_fuzzer.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_test_harness.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_test_images.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_test_log.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_test_md5.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_test_memory.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_test_random.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_thread.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_timer.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_touch.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_types.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_version.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_video.h"
    "/tmp/hjo/dependencies/SDL2/include/SDL_vulkan.h"
    "/tmp/hjo/dependencies/SDL2/include/begin_code.h"
    "/tmp/hjo/dependencies/SDL2/include/close_code.h"
    "/tmp/hjo/dependencies/SDL2/build/include/SDL_config.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  
          execute_process(COMMAND /nfs/2018/h/hjo/.brew/Cellar/cmake/3.12.3/bin/cmake -E create_symlink
            "libSDL2-2.0.dylib" "libSDL2.dylib")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/tmp/hjo/dependencies/SDL2/build/libSDL2.dylib")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/tmp/hjo/dependencies/SDL2/build/sdl2.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES "/tmp/hjo/dependencies/SDL2/build/sdl2-config")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/nfs/2018/h/hjo/.brew/share/aclocal/sdl2.m4")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/nfs/2018/h/hjo/.brew/share/aclocal" TYPE FILE FILES "/tmp/hjo/dependencies/SDL2/sdl2.m4")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/tmp/hjo/dependencies/SDL2/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")

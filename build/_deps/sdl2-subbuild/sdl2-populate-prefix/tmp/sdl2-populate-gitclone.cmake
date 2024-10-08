
if(NOT "/home/amyweiss/Documents/Projects/hello_sdl2/build/_deps/sdl2-subbuild/sdl2-populate-prefix/src/sdl2-populate-stamp/sdl2-populate-gitinfo.txt" IS_NEWER_THAN "/home/amyweiss/Documents/Projects/hello_sdl2/build/_deps/sdl2-subbuild/sdl2-populate-prefix/src/sdl2-populate-stamp/sdl2-populate-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/home/amyweiss/Documents/Projects/hello_sdl2/build/_deps/sdl2-subbuild/sdl2-populate-prefix/src/sdl2-populate-stamp/sdl2-populate-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/home/amyweiss/Documents/Projects/hello_sdl2/build/_deps/sdl2-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/home/amyweiss/Documents/Projects/hello_sdl2/build/_deps/sdl2-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone --no-checkout --progress --config "advice.detachedHead=false" "https://github.com/libsdl-org/SDL" "sdl2-src"
    WORKING_DIRECTORY "/home/amyweiss/Documents/Projects/hello_sdl2/build/_deps"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/libsdl-org/SDL'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout release-2.30.7 --
  WORKING_DIRECTORY "/home/amyweiss/Documents/Projects/hello_sdl2/build/_deps/sdl2-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'release-2.30.7'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/home/amyweiss/Documents/Projects/hello_sdl2/build/_deps/sdl2-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/home/amyweiss/Documents/Projects/hello_sdl2/build/_deps/sdl2-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/home/amyweiss/Documents/Projects/hello_sdl2/build/_deps/sdl2-subbuild/sdl2-populate-prefix/src/sdl2-populate-stamp/sdl2-populate-gitinfo.txt"
    "/home/amyweiss/Documents/Projects/hello_sdl2/build/_deps/sdl2-subbuild/sdl2-populate-prefix/src/sdl2-populate-stamp/sdl2-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/home/amyweiss/Documents/Projects/hello_sdl2/build/_deps/sdl2-subbuild/sdl2-populate-prefix/src/sdl2-populate-stamp/sdl2-populate-gitclone-lastrun.txt'")
endif()


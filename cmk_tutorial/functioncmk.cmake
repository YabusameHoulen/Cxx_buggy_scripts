cmake_minimum_required(VERSION 3.20.0)

function(myfunc arg1)
    message("my function name: ${CMAKE_CURRENT_FUNCTION}")
    message("current function argument: ${arg1}")
    set(arg1 meme)
    message(arg1)
    message(------)
    message(${ARGV0})
    message(${ARGV1})
    message(------)
    message(${CMAKE_ARGV0})
    message(${CMAKE_ARGV1})
    message(${CMAKE_ARGV2})
    message(------)
endfunction()

set(firstarg FirstValue)
myfunc(${firstarg} value)

message(-----------------------------)
### scope
# 1. Function scope
# 2. Directory scope
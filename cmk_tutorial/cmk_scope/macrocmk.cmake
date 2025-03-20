cmake_minimum_required(VERSION 3.20)

macro(testmc mvar)
    set(myvar [[new value]])
    message("argument: ${mvar}")
endmacro()

set(myvar "First Value")
message("myvar: " ${myvar})

testmc("var")
message("myvar: " ${myvar})
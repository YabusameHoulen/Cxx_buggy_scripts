cmake_minimum_required(VERSION 3.20.0)
### if ... endif ---> AND OR LESS
### for while ---> foreach...endeach while...endwhile
## break continue
message("the conditional expression")
message(----------------------)
set(NEWV TRUE)
if(NEWV AND NEWV)
    message(TRUE)
elseif(NOT NEWV)
    message(FALSE)
else()
    message(magic)   
endif()


if(1 LESS 2)
    message(wasai)
endif()
message(----------------------)
message("loop loop loop")
message(----------------------)

foreach(Var RANGE 2)
    message(${Var})
endforeach()


### must use LISTS
### ITEMS is keyword ...
set(MYLIST a1 a3 a2)
foreach(me IN LISTS MYLIST ITEMS 4 f)
    message(${me})
endforeach()

message(----------------------)
### zip
set(LIST1 one two three)
set(LIST2 1 2 3)
foreach(num IN ZIP_LISTS LIST1 LIST2)
    message("word = ${num_0}, index = ${num_1}")
endforeach()

message(----------------------)


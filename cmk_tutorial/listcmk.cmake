cmake_minimum_required(VERSION 3.20)
## list methods
## APPEND REMOVE_ITEM LENGTH FIND INSERT REVERSE SORT

## set var two methods
set(LISTVALUE a1 a2 a3)
message(${LISTVALUE})

message(------)
list(APPEND port p1 p2 p3)
message(${port})

list(LENGTH LISTVALUE len)
message(${len})

## index start from zero
list(FIND LISTVALUE a2 index)
message(${index})

list(REMOVE_ITEM LISTVALUE a3)
message(${LISTVALUE})

list(APPEND LISTVALUE a0)
message(${LISTVALUE})
list(INSERT LISTVALUE 1 az)
message(${LISTVALUE})

list(REVERSE LISTVALUE)
message(${LISTVALUE})

list(SORT LISTVALUE)
message(${LISTVALUE})
message(------)


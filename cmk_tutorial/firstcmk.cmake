cmake_minimum_required(VERSION 3.20)
## cmake messages
message("Hello")
message(Hello)
message("World")

message("dfd
ffd"
)

message([[dd 
dff]])

## cmake variables
set(Var1 ZZ)
message(${Var1})

message("-------------------------")
set("Va r2" Z2)
message(${Va\ r2})
set([[Va r3]] Z3)
message(${Va\ r3})
message("-------------------------")
message("stop doing strange things !!!")

## set multiple values
set(ListValue a1 a2)
message(${ListValue})
set(ListValue a1;a2)
message(${ListValue})

## path
# message($ENV{PATH})
set(ENV{myvar} "errin")
message($ENV{myvar})
unset(ENV{myvar})
# message($ENV{myvar}) # unset error

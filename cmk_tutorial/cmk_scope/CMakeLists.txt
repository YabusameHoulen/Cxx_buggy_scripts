cmake_minimum_required(VERSION 3.20)

set(gvar 1)

function(outerfun)
    message("enter scope")
    message("gvar is global: ${gvar}")
    set(gvar 2)
    message("gvar is local: ${gvar}")
    innerfun()
    message("out scope")
endfunction()


function(innerfun)
    message("enter scope")
    message("gvar in outer scope: ${gvar}")
    set(gvar 3)
    message("gvar in this scope: ${gvar}")
    message("out scope")
endfunction()

outerfun()
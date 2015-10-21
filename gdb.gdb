target remote localhost:1234

define hook-stop
    info registers
    printf "\n"
    x/16i $pc - 8
    printf "\n"
end

break main
continue

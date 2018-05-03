include_directories(
    ${SYMATH_INCLUDE_DIR}
)

add_library(symath
    parser/Operator.cpp
)

add_executable(symath-exec
    main.cpp
)

target_link_libraries(symath-exec
    symath
)
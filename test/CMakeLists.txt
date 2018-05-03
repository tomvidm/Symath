include_directories(
    ${SYMATH_INCLUDE_DIR}
    ${gtest_INCLUDE_DIR}
)

set(TEST_SOURCES
    TrivialTest.cpp
    parser/TestOperator.cpp
    symath/TestExpression.cpp
    symath/TestUnaryFunction.cpp
    symath/TestBinaryFunction.cpp
)

add_executable(symath-unit-tests
    ${TEST_SOURCES}
)

target_link_libraries(symath-unit-tests
    gtest
    gtest_main
    symath
)
PROJECT (STACKTEST)
SET(CMAKE_CXX_STANDARD 11)
SET(CXX_STANDARD_REQUIRED)
MESSAGE(STATUS "This is BINARY dir " ${STACKTEST_BINARY_DIR}) 
MESSAGE(STATUS "This is SOURCE dir " ${STACKTEST_SOURCE_DIR}) 

ADD_EXECUTABLE(symmetryCheck symmetryCheck.cpp)
ADD_EXECUTABLE(testSuffixCalculator testSuffixCalculator.cpp)
ADD_EXECUTABLE(testNifixExpression testNifixExpression.cpp)
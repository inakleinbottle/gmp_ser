


include(GoogleTest)
find_package(GTest REQUIRED)


add_executable(gmp_ser_tests
        mpz_serialization.cpp
        mpq_serialization.cpp
        multiprecision_integer.cpp
        multiprecision_rational.cpp
        )

target_link_libraries(gmp_ser_tests PRIVATE
        gmp_ser
        GTest::GTest
        GTest::Main
        Boost::boost
        Boost::serialization
        )



gtest_discover_tests(gmp_ser_tests)
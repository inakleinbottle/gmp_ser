//
// Created by sam on 26/10/2021.
//

#include <iostream>
#include <sstream>
#include <limits>


#include <boost/multiprecision/gmp.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <gtest/gtest.h>

#include <gmp_ser.h>


using integer_t = boost::multiprecision::mpz_int;


constexpr long BIG_POS_INTEGER = std::numeric_limits<long>::max();
constexpr long BIG_NEG_INTEGER = std::numeric_limits<long>::min();


TEST(multiprecision_int, serialize_empty_int)
{
    integer_t a, b;
    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);

    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0); // make sure we're back at the beginning

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(a, b);
}


TEST(multiprecision_int, serialize_small_pos_integer)
{
    integer_t a(BIG_POS_INTEGER), b;

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);

    oa << a;
    ASSERT_FALSE(ss.str().empty());
    ss.seekg(0); // make sure we're back at the beginning

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(a, b);
}



TEST(multiprecision_int, serialize_big_pos_integer)
{
    integer_t a(BIG_POS_INTEGER), b;
    a *= BIG_POS_INTEGER;

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);

    oa << a;
    ASSERT_FALSE(ss.str().empty());
    ss.seekg(0); // make sure we're back at the beginning

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(a, b);
}


TEST(multiprecision_int, serialize_small_neg_integer)
{
    integer_t a(BIG_NEG_INTEGER), b;

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);

    oa << a;
    ASSERT_FALSE(ss.str().empty());
    ss.seekg(0); // make sure we're back at the beginning

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(a, b);
}



TEST(multiprecision_int, serialize_big_neg_integer)
{
    integer_t a(BIG_POS_INTEGER), b;
    a *= BIG_NEG_INTEGER;

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);

    oa << a;
    ASSERT_FALSE(ss.str().empty());
    ss.seekg(0); // make sure we're back at the beginning

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(a, b);
}





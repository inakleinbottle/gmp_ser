//
// Created by sam on 26/10/2021.
//

#include <sstream>
#include <limits>

#include <gtest/gtest.h>
#include "gmp_ser.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

constexpr long BIG_POS_INTEGER = std::numeric_limits<long>::max();
constexpr long BIG_NEG_INTEGER = std::numeric_limits<long>::min();
constexpr unsigned long BIG_POS_DENOM = std::numeric_limits<unsigned long>::max();

using rational_t = boost::multiprecision::mpq_rational;


TEST(multiprecision_rational_ser, test_store_load_new_initialised)
{
    rational_t a, b;

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0);

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(a, b);
}

TEST(multiprecision_rational_ser, test_serialize_small_pos_num_small_denom)
{
    rational_t a(BIG_POS_INTEGER), b;

    a /= BIG_POS_DENOM;

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0);

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(a, b);
}


TEST(multiprecision_rational_ser, test_serialize_big_pos_num_small_denom)
{
    rational_t a(BIG_POS_INTEGER), b;

    a *= BIG_POS_INTEGER;
    a /= BIG_POS_DENOM;

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0);

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(a, b);
}

TEST(multiprecision_rational_ser, test_serialize_small_pos_num_big_denom)
{
    rational_t a(BIG_POS_INTEGER), b;

    a /= BIG_POS_DENOM;
    a /= BIG_POS_DENOM;

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0);

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(a, b);
}

TEST(multiprecision_rational_ser, test_serialize_big_pos_num_big_denom)
{
    rational_t a(BIG_POS_INTEGER), b;

    a *= BIG_POS_INTEGER;
    a /= BIG_POS_DENOM;
    a /= BIG_POS_DENOM;

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0);

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(a, b);
}

TEST(multiprecision_rational_ser, test_serialize_small_neg_num_small_denom)
{
    rational_t a(BIG_NEG_INTEGER), b;

    a /= BIG_POS_DENOM;


    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0);

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(a, b);
}

TEST(multiprecision_rational_ser, test_serialize_big_neg_num_small_denom)
{
    rational_t a(BIG_NEG_INTEGER), b;

    a /= BIG_POS_DENOM;
    a *= BIG_POS_INTEGER;

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0);

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(a, b);
}

TEST(multiprecision_rational_ser, test_serialize_small_NEG_num_big_denom)
{
    rational_t a(BIG_NEG_INTEGER), b;

    a /= BIG_POS_DENOM;
    a /= BIG_POS_DENOM;

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0);

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(a, b);
}

TEST(multiprecision_rational_ser, test_serialize_big_neg_num_big_denom)
{
    rational_t a(BIG_NEG_INTEGER), b;

    a *= BIG_POS_INTEGER;
    a /= BIG_POS_DENOM;
    a /= BIG_POS_DENOM;

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0);

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(a, b);
}
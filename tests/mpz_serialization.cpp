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


TEST(mpz_ser, test_store_load_new_initialised)
{
    mpz_t a, b;
    mpz_init(a);

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0);

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(mpz_cmp(a, b), 0);

    mpz_clear(a);
    mpz_clear(b);
}


TEST(mpz_ser, test_store_load_small_positive)
{
    mpz_t a, b;
    mpz_init(a);
    mpz_set_si(a, BIG_POS_INTEGER);

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0);

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(mpz_cmp(a, b), 0);

    mpz_clear(a);
    mpz_clear(b);
}


TEST(mpz_ser, test_store_load_big_positive)
{
    mpz_t t, a, b;
    mpz_init(a);
    mpz_init(t);
    mpz_set_si(t, BIG_POS_INTEGER);
    mpz_mul_ui(a, t, BIG_POS_INTEGER); // definitely too large for a long

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0);

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(mpz_cmp(a, b), 0);

    mpz_clear(a);
    mpz_clear(b);
}


TEST(mpz_ser, test_store_load_small_negative)
{
    mpz_t a, b;
    mpz_init(a);
    mpz_set_si(a, BIG_NEG_INTEGER);

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0);

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(mpz_cmp(a, b), 0);

    mpz_clear(a);
    mpz_clear(b);
}


TEST(mpz_ser, test_store_load_big_negative)
{
    mpz_t t, a, b;
    mpz_init(a);
    mpz_init(t);
    mpz_set_si(t, BIG_NEG_INTEGER);
    mpz_mul_ui(a, t, BIG_POS_INTEGER); // definitely too large for a long
    mpz_clear(t);

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0);

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(mpz_cmp(a, b), 0);

    mpz_clear(a);
    mpz_clear(b);
}

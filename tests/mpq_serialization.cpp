//
// Created by sam on 26/10/2021.
//

#include <sstream>
#include <limits>

#include <gmp.h>
#include <gtest/gtest.h>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include <gmp_ser.h>

constexpr long BIG_POS_INTEGER = std::numeric_limits<long>::max();
constexpr long BIG_NEG_INTEGER = std::numeric_limits<long>::min();
constexpr unsigned long BIG_POS_DENOM = std::numeric_limits<unsigned long>::max();

TEST(mpq_ser, test_store_load_new_initialised)
{
    mpq_t a, b;
    mpq_init(a);

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0);

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(mpq_cmp(a, b), 0);

    mpq_clear(a);
    mpq_clear(b);
}

TEST(mpq_ser, test_serialize_small_pos_num_small_denom)
{
    mpq_t a, b;
    mpq_init(a);

    mpq_set_si(a, BIG_POS_INTEGER, BIG_POS_DENOM);
    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0);

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(mpq_cmp(a, b), 0);

    mpq_clear(a);
    mpq_clear(b);
}

TEST(mpq_ser, test_serialize_big_pos_num_small_denom)
{
    mpq_t a, b;
    mpq_init(a);

    mpq_set_si(a, BIG_POS_INTEGER, BIG_POS_DENOM);
    {
        mpq_t m;
        mpq_init(m);
        mpq_set_si(m, BIG_POS_INTEGER, 1UL);
        mpq_mul(a, a, m);
        mpq_clear(m);
    }

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0);

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(mpq_cmp(a, b), 0);

    mpq_clear(a);
    mpq_clear(b);
}

TEST(mpq_ser, test_serialize_small_pos_num_big_denom)
{
    mpq_t a, b;
    mpq_init(a);

    mpq_set_si(a, BIG_POS_INTEGER, BIG_POS_DENOM);
    {
        mpq_t m;
        mpq_init(m);
        mpq_set_si(m, 1UL, BIG_POS_DENOM);
        mpq_mul(a, a, m);
        mpq_clear(m);
    }

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0);

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(mpq_cmp(a, b), 0);

    mpq_clear(a);
    mpq_clear(b);
}

TEST(mpq_ser, test_serialize_big_pos_num_big_denom)
{
    mpq_t a, b;
    mpq_init(a);

    mpq_set_si(a, BIG_POS_INTEGER, BIG_POS_DENOM);
    {
        mpq_t m;
        mpq_init(m);
        mpq_set_si(m, BIG_POS_INTEGER, BIG_POS_DENOM);
        mpq_mul(a, a, m);
        mpq_clear(m);
    }

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0);

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(mpq_cmp(a, b), 0);

    mpq_clear(a);
    mpq_clear(b);
}

TEST(mpq_ser, test_serialize_small_neg_num_small_denom)
{
    mpq_t a, b;
    mpq_init(a);

    mpq_set_si(a, BIG_NEG_INTEGER, BIG_POS_DENOM);
    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0);

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(mpq_cmp(a, b), 0);

    mpq_clear(a);
    mpq_clear(b);
}

TEST(mpq_ser, test_serialize_big_neg_num_small_denom)
{
    mpq_t a, b;
    mpq_init(a);

    mpq_set_si(a, BIG_NEG_INTEGER, BIG_POS_DENOM);
    {
        mpq_t m;
        mpq_init(m);
        mpq_set_si(m, BIG_POS_INTEGER, 1UL);
        mpq_mul(a, a, m);
        mpq_clear(m);
    }

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0);

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(mpq_cmp(a, b), 0);

    mpq_clear(a);
    mpq_clear(b);
}

TEST(mpq_ser, test_serialize_small_NEG_num_big_denom)
{
    mpq_t a, b;
    mpq_init(a);

    mpq_set_si(a, BIG_NEG_INTEGER, BIG_POS_DENOM);
    {
        mpq_t m;
        mpq_init(m);
        mpq_set_si(m, 1UL, BIG_POS_DENOM);
        mpq_mul(a, a, m);
        mpq_clear(m);
    }

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0);

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(mpq_cmp(a, b), 0);

    mpq_clear(a);
    mpq_clear(b);
}

TEST(mpq_ser, test_serialize_big_neg_num_big_denom)
{
    mpq_t a, b;
    mpq_init(a);

    mpq_set_si(a, BIG_NEG_INTEGER, BIG_POS_DENOM);
    {
        mpq_t m;
        mpq_init(m);
        mpq_set_si(m, BIG_POS_INTEGER, BIG_POS_DENOM);
        mpq_mul(a, a, m);
        mpq_clear(m);
    }

    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << a;
    ASSERT_FALSE(ss.str().empty());

    ss.seekg(0);

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    EXPECT_EQ(mpq_cmp(a, b), 0);

    mpq_clear(a);
    mpq_clear(b);
}
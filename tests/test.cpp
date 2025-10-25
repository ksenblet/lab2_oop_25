#include <gtest/gtest.h>
#include <stdexcept>

#include "BitString.h"
#include "Array.h"

// ==================== ТЕСТЫ КОНСТРУКТОРОВ 
TEST(BitStringTest, DefaultConstructorCreatesEmptyString) {
    BitString bs;  
    ASSERT_EQ(bs.toString(), "");  
}

TEST(BitStringTest, SizeConstructorWithOnes) {
    BitString bs(4, '1');
    ASSERT_EQ(bs.toString(), "1111");
}

TEST(BitStringTest, StringConstructorValid) {
    BitString bs("1010");
    ASSERT_EQ(bs.toString(), "1010");
}

TEST(BitStringTest, InitializerListConstructor) {
    BitString bs{'1', '0', '1'};
    ASSERT_EQ(bs.toString(), "101");
}

TEST(BitStringTest, CopyConstructor) {
    BitString original("1100");
    BitString copy(original);
    ASSERT_EQ(copy.toString(), "1100");
}

// ==================== ТЕСТЫ НЕКОРРЕКТНЫХ ДАННЫХ 
TEST(BitStringTest, EmptyStringThrowsException) {
    ASSERT_THROW(BitString bs(""), std::invalid_argument);
}

TEST(BitStringTest, InvalidCharInStringThrows) {
    ASSERT_THROW(BitString bs("10a1"), std::invalid_argument);
}

TEST(BitStringTest, InvalidCharInInitializerListThrows) {
    ASSERT_THROW(BitString bs("120"), std::invalid_argument);
}

// ==================== ТЕСТЫ БИТОВЫХ ОПЕРАЦИЙ 
TEST(BitStringTest, ANDOperation) {
    BitString bs1("1010");
    BitString bs2("1100");
    BitString result = bs1.bitAnd(bs2);
    ASSERT_EQ(result.toString(), "1000");
}

TEST(BitStringTest, OROperation) {
    BitString bs1("1010");
    BitString bs2("1100");
    BitString result = bs1.bitOr(bs2);
    ASSERT_EQ(result.toString(), "1110");
}

TEST(BitStringTest, XOROperation) {
    BitString bs1("1010");
    BitString bs2("1100");
    BitString result = bs1.bitXor(bs2);
    ASSERT_EQ(result.toString(), "0110");
}

TEST(BitStringTest, NOTOperation) {
    BitString bs("1010");
    BitString result = bs.bitNot();
    ASSERT_EQ(result.toString(), "0101");
}

// ==================== ТЕСТЫ РАЗНЫХ РАЗМЕРОВ 
TEST(BitStringTest, ANDWithDifferentSizes) {
    BitString bs1("101");
    BitString bs2("1100");
    BitString result = bs1.bitAnd(bs2);
    ASSERT_EQ(result.toString(), "0100");
}

TEST(BitStringTest, ORWithDifferentSizes) {
    BitString bs1("101");
    BitString bs2("1100");
    BitString result = bs1.bitOr(bs2);
    ASSERT_EQ(result.toString(), "1101");
}

// ==================== ТЕСТЫ ГРАНИЧНЫХ СЛУЧАЕВ 
TEST(BitStringTest, SingleBitOperations) {
    BitString bs1("1");
    BitString bs2("0");
    
    ASSERT_EQ(bs1.bitAnd(bs2).toString(), "0");
    ASSERT_EQ(bs1.bitOr(bs2).toString(), "1");
    ASSERT_EQ(bs1.bitXor(bs2).toString(), "1");
}

TEST(BitStringTest, AllZerosNOT) {
    BitString bs("0000");
    BitString result = bs.bitNot();
    ASSERT_EQ(result.toString(), "1111");
}

TEST(BitStringTest, AllOnesNOT) {
    BitString bs("1111");
    BitString result = bs.bitNot();
    ASSERT_EQ(result.toString(), "0000");
}

// ==================== ТЕСТЫ ЦЕПОЧЕК ОПЕРАЦИЙ 
TEST(BitStringTest, ChainedOperations) {
    BitString bs1("101");
    BitString bs2("110");
    BitString result = bs1.bitAnd(bs2).bitNot();
    ASSERT_EQ(result.toString(), "011"); // ~(101 & 110) = ~(100) = 011
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
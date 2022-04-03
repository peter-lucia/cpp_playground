//#include "test_two_sum.cc"
//
// Created by Peter Lucia on 1/24/22.
//
#include <unordered_set>
#include <gtest/gtest.h>
#include "../src/two_sum.h"
#include "../src/utils.h"
#include "../src/fib.h"
#include "../src/remove_k_digits.h"
#include "../src/majority_element.h"
#include "../src/algorithms.h"
#include "../src/find_duplicate.h"
#include "../src/time_formatter.h"

using std::vector;
using std::unordered_set;
using std::string;
using utils::printVector;

// Sources:
// Google test: https://google.github.io/googletest/quickstart-cmake.html
// CLion Unit Testing: https://www.jetbrains.com/help/clion/unit-testing-tutorial.html
// Catch2: https://medium.com/dsckiit/a-guide-to-using-catch2-for-unit-testing-in-c-f0f5450d05fb
// Catch.hpp: https://github.com/catchorg/Catch2/releases


TEST(Sanity, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(TwoSum, basic) {
    vector<int> v = {1,2,6,7};
    vector<int> expected_result = {1,3};
    vector<int> actual_result = TwoSum().twoSum(v, 9);

    ASSERT_EQ(utils::getSetFromVector(expected_result),
              utils::getSetFromVector(actual_result));
}

TEST(Fibonnaci, basic) {
    // 1,1,2,3,5,8
    int expected_result = 8;
    int actual_result = Fib().fib(6);

    ASSERT_EQ(expected_result, actual_result);
}

TEST(RemoveKDigits, basic) {
    string expected_result = "1219";
    string actual_result = RemoveKDigits().removeKdigits("1432219", 3);

    ASSERT_EQ(expected_result, actual_result);
}

TEST(RemoveKDigits, medium) {
    string expected_result = "200";
    string actual_result = RemoveKDigits().removeKdigits("10200", 1);

    ASSERT_EQ(expected_result, actual_result);
}

TEST(RemoveKDigits, hard) {
    string expected_result = "11";
    string actual_result = RemoveKDigits().removeKdigits("112", 1);

    ASSERT_EQ(expected_result, actual_result);
}


TEST(MajorityElement, easy) {
    int expected_result = 2;
    vector<int> v = {1,2,2,3,4,5};
    int actual_result = majorityElement(v);

    ASSERT_EQ(expected_result, actual_result);
}

TEST(MaxDepth, easy) {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(5);
    int expected_result = 4;

    ASSERT_EQ(expected_result, maxDepth(root));
}

TEST(FindDuplicate, easy) {

    vector<int> v = {1,2,2,3,4,5};

    int actual_result = FindDuplicate().findDuplicate(v);
    int expected_result = 2;
    ASSERT_EQ(expected_result, actual_result);

}

TEST(TimeFormatter, easy) {
    string time_with_tz = "2022-03-30T05:18:14.660921+00:00";
    string expected_result = "2022-03-29T22:16:54.669560-08:00";
    string actual_result = TimeFormatter::convert_isoformatted_time(time_with_tz);
    ASSERT_EQ(expected_result, actual_result);
}

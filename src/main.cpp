#include <gtest/gtest.h>
#include "bmstu_vector.hpp"
#include <ostream>


TEST(GoogleTestCi, Foo) {
    ASSERT_TRUE(true);
}


TEST(VectorTest, Output) {
    std::stringstream ss;
    bmstu::vector<char> a_el{'a', 'l', 'e', 'x'};
    ss << a_el;
    ASSERT_STREQ(ss.str().c_str(), "[a, l, e, x]");

}


TEST(VectorTest, vector) {
    bmstu::vector<char> a_el(2, 'A');
    ASSERT_EQ(a_el.size(), 2);
    ASSERT_EQ(a_el.capacity(), 2);
    std::stringstream ss;
    ss << a_el;
    ASSERT_STREQ(ss.str().c_str(), "[A, A]");

}


TEST(VectorTest, vector_operator_enter) {
    bmstu::vector<int> vec{1, 2};
    bmstu::vector<int> vec1{3, 4};
    vec = std::move(vec1);
    std::cout << vec;
    ASSERT_EQ(vec1, vec);
    ASSERT_EQ(vec1.size(), 2);
    ASSERT_EQ(vec1.capacity(), 2);

}


TEST(VectorTest, vector_operator_copy) {
    bmstu::vector<int> a_el{1, 2};
    bmstu::vector<int> b_el{3, 4, 5, 6};
    a_el = b_el;
    std::cout << a_el;
    ASSERT_EQ(a_el, b_el);
    ASSERT_EQ(a_el.size(), 4);
    ASSERT_EQ(a_el.capacity(), 4);

}


TEST(VectorTest, vector_operator_choose_char) {
    bmstu::vector<char> a_el{'1', '2'};
    std::cout << a_el[1];
    ASSERT_EQ(a_el[1], '2');

}


TEST(VectorTest, vector_operator_bool) {
    bmstu::vector<int> a_el{1, 2};
    ASSERT_EQ(a_el.empty(), 0);

}


TEST(VectorTest, vector_resize) {
    bmstu::vector<int> a_el{1, 2};
    a_el.Resize(4);
    ASSERT_EQ(a_el.size(), 4);
    ASSERT_EQ(a_el.capacity(), 4);
}


TEST(VectorTest, vector_operator_noequal) {
    bmstu::vector<char> a_el{'K', 'R', 'U', 'T', 'O', 'V'};
    bmstu::vector<char> b_el{'K', 'R', 'U', 'T', 'O', 'V', 'L'};

    ASSERT_EQ(a_el != b_el, 1);
}

TEST(VectorTest, name1) {
    bmstu::vector<int> a_el{1};
    bmstu::vector<int> a_e2{1, 2, 3, 4};
    a_el.push_back(2);
    a_el.push_back(3);
    a_el.push_back(4);

    ASSERT_EQ(a_el == a_e2, true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

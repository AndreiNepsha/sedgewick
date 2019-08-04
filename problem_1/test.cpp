#define BOOST_TEST_MODULE algs test
#include <boost/test/auto_unit_test.hpp>

#include "algs.hpp"

std::vector<std::pair<int, int>> input = {
    std::pair<int, int>(3, 4),
    std::pair<int, int>(4, 9),
    std::pair<int, int>(8, 0),
    std::pair<int, int>(2, 3),
    std::pair<int, int>(5, 6),
    std::pair<int, int>(2, 9),
    std::pair<int, int>(5, 9),
    std::pair<int, int>(7, 3),
    std::pair<int, int>(5, 8),
    std::pair<int, int>(5, 6),
    std::pair<int, int>(0, 2),
    std::pair<int, int>(6, 1)
};

std::vector<std::pair<int, int>> expected = {
    std::pair<int, int>(3, 4),
    std::pair<int, int>(4, 9),
    std::pair<int, int>(8, 0),
    std::pair<int, int>(2, 3),
    std::pair<int, int>(5, 6),
    std::pair<int, int>(5, 9),
    std::pair<int, int>(7, 3),
    std::pair<int, int>(5, 8),
    std::pair<int, int>(6, 1)
};

BOOST_AUTO_TEST_CASE(alg1_test) {
    const static auto actual = alg_1(&input);
    BOOST_CHECK(*actual == expected);
}
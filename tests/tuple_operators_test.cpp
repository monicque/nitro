#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <nitro/tuple_operators.hpp>

struct my_int : nitro::tuple_operators<my_int>
{
    my_int(int i) : value_(i)
    {
    }

    auto as_tuple() const
    {
        return std::tie(value_);
    }

private:
    int value_;
};

TEST_CASE("simple class comparison works", "[tuple_operators]")
{
    my_int one(1);
    my_int zero(0);

    REQUIRE(one == one);
    REQUIRE(one != zero);
    REQUIRE(one > zero);
    REQUIRE(zero < one);
}

//
// cpp11/can_query_not_applicable_static.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2025 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include "asio/query.hpp"
#include <cassert>

struct prop
{
};

struct object
{
};

namespace asio {
namespace traits {

template<>
struct static_query<object, prop>
{
  static constexpr bool is_valid = true;
  static constexpr bool is_noexcept = true;
  typedef int result_type;
  static constexpr int value() { return 123; }
};

} // namespace traits
} // namespace asio

int main()
{
  static_assert(!asio::can_query<object, prop>::value, "");
  static_assert(!asio::can_query<const object, prop>::value, "");
}

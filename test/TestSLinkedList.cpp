#define CATCH_CONFIG_MAIN
#include "../include/SLinkedList.hpp"
#include "../include/catch2.hpp"

TEST_CASE("SLinkedList correctly maintains elments") {
  SingleLinkedList<int> list;

  SECTION("Initial list is empty") { REQUIRE(list.empty()); }

  SECTION("Element adding and removing works") {
    constexpr int a1{69};

    list.addFront(a1);
    REQUIRE(list.front() == a1);

    list.removeFront();
    REQUIRE(list.empty());
  }

  SECTION("Sequential element adding gives predictable structure") {
    constexpr int a1{69};
    constexpr int a2{42};

    list.addFront(a1);
    list.addFront(a2);

    REQUIRE(list.front() == a2);
    list.removeFront();

    REQUIRE(list.front() == a1);
    list.removeFront();

    REQUIRE(list.empty());
  }
}
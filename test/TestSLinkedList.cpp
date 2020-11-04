#define CATCH_CONFIG_MAIN
#include "../include/SLinkedList.hpp"
#include "../include/catch2.hpp"

TEST_CASE("SLinkedList correctly maintains elments") {
  SingleLinkedList<int> list;

  SECTION("Initial list is empty") { REQUIRE(list.empty()); }

  SECTION("Element adding and removing works") {
    list.addFront(69);
    REQUIRE(list.front() == 69);

    list.removeFront();
    REQUIRE(list.empty());
  }

  SECTION("Sequential element adding gives predictable structure") {
    list.addFront(69);
    list.addFront(42);

    REQUIRE(list.front() == 42);
    list.removeFront();

    REQUIRE(list.front() == 69);
    list.removeFront();

    REQUIRE(list.empty());
  }
}

TEST_CASE("SLinkedList removing elements from arbitrary place") {
  SingleLinkedList<int> list;

  SECTION("Removing head element correctly") {
    list.addFront(42);
    list.removeElement(42);
    REQUIRE(list.empty());

    list.addFront(42);
    list.addFront(13);
    list.removeElement(13);
    REQUIRE(list.front() == 42);
    list.removeFront();
  }

  SECTION("Removing last element correctly") {
    list.addFront(42);
    list.addFront(13);

    list.removeElement(42);
    REQUIRE(list.front() == 13);
    list.removeFront();
  }

  SECTION("Removing arbitrary element correctly") {
    list.addFront(42);
    list.addFront(13);
    list.addFront(15);

    list.removeElement(13);
    REQUIRE(list.front() == 15);
    list.removeFront();
    REQUIRE(list.front() == 42);
    list.removeFront();
  }
}
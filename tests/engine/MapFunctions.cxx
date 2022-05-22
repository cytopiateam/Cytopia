#include <catch.hpp>
#include "../../src/engine/common/Constants.hxx"
#include <MapFunctions.hxx>
#include <SignalMediator.hxx>

using string = std::string;

TEST_CASE("Create new Map", "[mapfunctions][mapfunctions]")
{
  CHECK(MapFunctions::instance().getMap() != nullptr)
}

TEST_CASE("Create empty Map without mapnodes", "[engine][engine]")
{
  Map *map = new Map(64, 64, true);
  CHECK(map != nullptr);
}


TEST_CASE("Create Map with procedural terrain", "[engine][engine]")
{
  Map *map = new Map(64, 64, true);
  CHECK(map != nullptr);
}

TEST_CASE("Create Map without procedural terrain", "[engine][engine]")
{
  Map *map = new Map(64, 64, false);
  CHECK(map != nullptr);
}

TEST_CASE("Save and load Map", "[engine][engine]")
{
  MapFunctions::instance(); //init
  SignalMediator::instance().signalNewGame();
  SignalMediator::instance().signalSaveGame("saveTest");
  SignalMediator::instance().signalLoadGame("saveTest");

  CHECK(MapFunctions::instance().getMap() != nullptr);
}

#include "tests.h"

#include "../groundupdb/include/groundupdb.h"

TEST_CASE("Store and retrieve a value", "[setKeyValue,getKeyValue]") {
    //Story:-
    //  [Who]  As a database user
    //  [What]  I need to store and retrieve a value with a simple name
    //  [Value]  So I can persist data for later use
    SECTION("Basic set and get") {
        std::string dbname("myemptydb");
        groundupdb::Database db(groundupdb::GroundUpDB::createEmptyDB(dbname));

        // We know we have been successful when:-
        // 1. Thre retrieved value is the same as the store value
        std::string key("simplestring");
        std::string value("Some highly valuable value");
        db.setKeyValue(key,value);
        REQUIRE(value == db.getKeyValue(key));

        db.destroy();
    }
}
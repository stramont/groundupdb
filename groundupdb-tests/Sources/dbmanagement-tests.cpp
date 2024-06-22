#include "tests.h"

#include <filesystem>
#include <string>

#include "../../groundupdb/Headers/groundupdb.h"

namespace fs = std::filesystem;

TEST_CASE("db-create","[createEmptyDB]") {

    // Story:-
    //   [Who]   As a database administrator
    //   [What]  I need to create a new empty database
    //   [Value] So I can later store and retrieve data

    SECTION("Default settings") {
        std::string dbname("myemptydb");
        std::cout << "creating db" << std::endl;
        Database db(GroundUpDB::createEmptyDB(dbname));

        // We know we have been successful when:-
        // 1. We have a valid database reference returned
        //   - No test -> The above would have errored
        // 2. The DB has a folder that exists on the file system
        std::cout << "checking db directory" << std::endl;
        REQUIRE(fs::is_directory(fs::status(db.getDirectory())));
        // C++17 Ref: https://en.cppreference.com/w/cpp/filesystem/is_directory

        // 3. The database folder is empty (no database files yet)

        std::cout << "iterating over db directory" << std::endl;
        const auto& p = fs::directory_iterator(db.getDirectory());
        REQUIRE(p == end(p)); // i.e. no contents as iterator is at the end already
        // C++17 Ref: https://en.cppreference.com/w/cpp/filesystem/directory_iterator

        db.destroy();
        REQUIRE(!fs::is_directory(fs::status(db.getDirectory())));
 
    }
}

TEST_CASE("Load an existing database", "[loadDB]") {
    //Story:-
    //  [Who]  As a database user
    //  [What]  I need to create a reference to an existing database
    //  [Value]  So I can later store and retrieve data

    SECTION("Default settings") {
        std::string dbname("myemptydb");
        Database db(GroundUpDB::createEmptyDB(dbname));

        Database db2(GroundUpDB::loadDB(dbname));

        REQUIRE(fs::is_directory(fs::status(db2.getDirectory())));

        const auto& p = fs::directory_iterator(db2.getDirectory());
        REQUIRE(p == end(p));

        db2.destroy();
        REQUIRE(!fs::is_directory(fs::status(db2.getDirectory())));
    }
}
#include "database.h"

#include <string>

Database::Database(std::string dbname, std::string fullpath)
{

}

Database Database::createEmpty(std::string dbname) {
    return Database("fred", "fred");
}
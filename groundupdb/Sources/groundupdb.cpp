#include "groundupdb.h"

GroundUpDB::GroundUpDB()
{

}

Database GroundUpDB::createEmptyDb(std::string &dbname) {
    return Database::createEmpty(dbname);
}
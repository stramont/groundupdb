#ifndef GROUNDUPDB_H
#define GROUNDUPDB_H

#include <string>
#include "database.h"

class GroundUpDB
{
public:
    GroundUpDB();
//24:06 001
    static Database createEmptyDB(std::string& dbname);
};

#endif
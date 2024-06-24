#ifndef GROUNDUPDB_H
#define GROUNDUPDB_H

#include <string>
#include "database.h"

namespace groundupdb {
    
class GroundUpDB
{
public:
    GroundUpDB();

    static std::unique_ptr<IDatabase> createEmptyDB(std::string& dbname);
    static std::unique_ptr<IDatabase> loadDB(std::string& dbname);

};

}


#endif
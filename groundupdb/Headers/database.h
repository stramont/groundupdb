#ifndef DATABASE_H
#define DATABASE_H

#include <string>

class Database 
{
public:
    Database(std::string dbname, std::string fullpath);

    static Database createEmpty(std::string dbname);
};

#endif

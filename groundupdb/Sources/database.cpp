#include "database.h"

#include <iostream>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;

Database::Database(std::string dbname, std::string fullpath)
    : m_name(dbname), m_fullpath(fullpath)
{

}

Database Database::createEmpty(std::string dbname) {
    std::string basedir(".groundupdb");

    if (!fs::exists(basedir)) {
        fs::create_directory(basedir);
    }

    std::string dbfolder(basedir + "/" + dbname);

    if (!fs::exists(dbfolder)) {
        fs::create_directory(dbfolder);
    }

    return Database(dbname, dbfolder);
}

std::string Database::getDirectory() {
    return m_fullpath;
}

void Database::setKeyValue(std::string key, std::string value) {

}

std::string Database::getKeyValue(std::string key) {
    return "Wibble";
}
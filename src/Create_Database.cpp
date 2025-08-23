#include <iostream>
#include <vector>
#include <string>
#include <SQLiteCpp/SQLiteCpp.h>
#include "Database_Functions.h"

void Database_Create() {
    try {
        // Open a database file in read/write and create mode
        SQLite::Database db("cerebro.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
        std::cout << "Database opened successfully." << std::endl;

        // Create a 'files' table with path and last modified time columns.
        // "IF NOT EXISTS" prevents errors on subsequent runs.
        db.exec("CREATE TABLE IF NOT EXISTS files (id INTEGER PRIMARY KEY, path TEXT NOT NULL UNIQUE, last_modified INTEGER)");
        std::cout << "Table 'files' created or already exists." << std::endl;

        // --- Insert Data using a Transaction and a Prepared Statement ---

        // 1. Begin a transaction
        SQLite::Transaction transaction(db);

        // 2. Create a prepared statement (the query template)
        SQLite::Statement query(db, "INSERT INTO files (path, last_modified) VALUES (?, ?)");
        std::cout << "Inserting data..." << std::endl;

        // 3. Create some sample data
        std::vector<std::pair<std::string, int>> file_data = {
            {"/Users/mantissa/docs/project_alpha.txt", 1721920000},
            {"/Users/mantissa/code/cerebro/src/main.cpp", 1721923456},
            {"/Users/mantissa/downloads/datasheet.pdf", 1721800000}
        };

        // 4. Loop through data, bind it to the query, and execute
        for (const auto& file : file_data) {
            // Bind the path to the first placeholder (?)
            query.bind(1, file.first);
            // Bind the timestamp to the second placeholder (?)
            query.bind(2, file.second);

            // Execute the query
            query.exec();

            // Reset the statement for the next loop iteration
            query.reset();
        }

        // 5. Commit the transaction to the database file.
        // All insertions are written to disk at this moment.
        transaction.commit();
        std::cout << "Data inserted successfully." << std::endl;

    } catch (const std::exception& e) {
        // If any error occurs, the transaction is automatically rolled back
        // by the destructor of the 'transaction' object.
        std::cerr << "SQLite exception: " << e.what() << std::endl;
    }

}

void UpdateDatebase(std::vector<>)
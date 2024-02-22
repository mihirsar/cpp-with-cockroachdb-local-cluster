#include <iostream>
#include <pqxx/pqxx>

int main() {
    try {
        // Connect to CockroachDB cluster
        pqxx::connection conn("host=ip_address port=26257 user=root sslmode=disable dbname=dbname");
        
        // Perform SQL query
        pqxx::work txn(conn);
        pqxx::result result = txn.exec("CREATE TABLE table_name;");

        // Process query results
        // for (const auto& row : result) {
        //     std::cout << "Column 1: " << row[0].as<std::string>() << ", Column 2: " << row[1].as<std::string>() << std::endl;
        // }

        txn.commit();
        std::cout<<"Connection Successful";
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}

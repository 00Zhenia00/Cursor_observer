#include <iostream>
#include <memory>

#include "cursor.h"
#include "console.h"
#include "logger.h"


int main()
{
    try {

        std::unique_ptr<Cursor> cursor(new Cursor);

        std::unique_ptr<Console> console = std::make_unique<Console>(*cursor);
        std::unique_ptr<Logger> logger = std::make_unique<Logger>(*cursor);

        std::cout << "hello world" << std::endl;

        cursor->track();
    }
    catch (std::runtime_error& ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }
    catch (...) {
        std::cout << "Unknown error!" << std::endl;
    }

    return 0;

}
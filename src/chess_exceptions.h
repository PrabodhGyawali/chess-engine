#include <stdexcept>
#include <string>

using namespace std;

class InvalidBoardState: public logic_error {
public:
    explicit InvalidBoardState(const string& message) 
        : logic_error(message)
    {}
};
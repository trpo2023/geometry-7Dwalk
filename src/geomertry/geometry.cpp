#include "../libgeometry/validCircle.h"

int main()
{
    Circle circle;
    std::string file = "Input_Data";
    std::string line;
    std::ifstream in(file);
    if (in.is_open()) {
        while (getline(in, line)) {
            if (validCircle(line, circle)) {
                std::cout << line << std::endl
                          << "perimeter = " << std::setprecision(3)
                          << circle.perimeter << std::endl
                          << "area = " << std::setprecision(3) << circle.area
                          << std::endl
                          << std::endl;
            }
        }
    }
    in.close();
    return 0;
}

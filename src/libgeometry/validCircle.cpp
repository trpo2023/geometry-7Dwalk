#include "validCircle.h"

bool validCircle(const std::string& input, Circle& circle)
{
    const std::regex circle_check("^circle\\W");
    const std::regex op_cl_check("[()]$");
    const std::regex check_after_trash("([)])|([(])[ ]*$");
    const std::regex circle_regex_num(
            "\\s*(\\d+\\.?\\d*).\\s*(\\d+\\.?\\d*),\\s*(\\d+\\.?\\d*)$");
    const std::regex values_regex(
            "^[-]?[0-9]*[.]?[0-9][ ]+[-]?[0-9]*[.]?[0-9][,][ "
            "]*[-]?[0-9]*[.]?[0-9]+$");

    std::smatch match;
    std::string circle_str = input.substr(0, 7);
    std::string numExp = input.substr(7, input.size() - 8);

    if (!regex_search(circle_str, match, circle_check)) {
        std::cout << input << std::endl
                  << std::setfill(' ') << std::setw(0) << "^" << std::endl;
        std::cout << "Error at column 0: expected 'circle'" << std::endl
                  << std::endl;
        return false;
    } else if (input[6] != '(') {
        std::cout << input << std::endl
                  << std::setfill(' ') << std::setw(7) << "^" << std::endl;
        std::cout << "Error at column 7: expected '('" << std::endl
                  << std::endl;
        return false;
    } else if (input[input.length() - 1] != ')') {
        if (!regex_search(numExp, match, values_regex)) {
            std::cout << input << std::endl
                      << std::setfill(' ') << std::setw(match.position() + 8)
                      << "^" << std::endl;
            std::cout << "Error at column " << match.position() + 8
                      << ": undefined symbol(s)" << std::endl
                      << std::endl;
            return false;
        } else {
            std::cout << input << std::endl
                      << std::setfill(' ') << std::setw(input.length()) << "^"
                      << std::endl;
            std::cout << "Error at column " << input.length()
                      << ": expected ')'" << std::endl
                      << std::endl;
            return false;
        }
    } else if (!regex_search(numExp, match, values_regex)) {
        std::cout << input << std::endl
                  << std::setfill(' ') << std::setw(match.position()) << "^"
                  << std::endl;
        std::cout << "Error at column " << match.position()
                  << ": expected <double> " << std::endl
                  << std::endl;
        return false;
    } else if (regex_match(numExp, match, circle_regex_num)) {
        circle.center.x = stod(match[1].str());
        circle.center.y = stod(match[2].str());
        circle.radius = stod(match[3].str());
        circle.area = 3.14 * circle.radius * circle.radius;
        circle.perimeter = 2 * 3.14 * circle.radius;
    }
    return true;
}
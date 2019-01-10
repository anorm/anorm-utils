#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

static void usage()
{
    std::cerr << "Usage: word [word_number]" << std::endl;
}

int main(int argc, char * argv[])
{
    uint word_number = 1;
    if (argc > 2)
    {
        usage();
        return 1;
    }
    if (argc == 2)
    {
        word_number = std::strtoul(argv[1], nullptr, 10);
    }

    std::string line;
    while (std::getline(std::cin, line))
    {
        auto pos = line.cbegin();
        pos = std::find_if_not(pos, line.cend(), ::isspace);
        for (uint i = 1; i < word_number; ++i)
        {
            pos = std::find_if(pos, line.cend(), ::isspace);
            pos = std::find_if_not(pos, line.cend(), ::isspace);
        }

        if (pos == line.cend())
            continue;

        std::cout << std::string(pos, std::find_if(pos, line.cend(), ::isspace)) << std::endl;
    }
    return 0;
}


#include "sedIsForLosers.hpp"

int main(int argc, char **argv)
{
    std::string  outFileName;
    std::string  line;
    size_t       startPosition;
    std::string  newLine;
    int         s2_len;
    int         indexAfterMatch;

    if (argc != 4)
    {
        std::cout << "Usage: ./sedIsForLosers [Name of the input file] [Word to find] [Word to substitute it with]" << std::endl;
        return (1);
    }
    std::ifstream inFile(argv[1]);
    if (!inFile)
    {
        std::cout << "Infile error";
        return (2);
    }
    outFileName = std::string (argv[1]) + ".replace";
    std::ofstream outFile(outFileName.c_str());
    if (!outFile)
    {
        std::cout << "Outfile error";
        return (2);
    }
    s2_len = std::string (argv[3]).length();
    while (std::getline(inFile, line))
    {
        startPosition = 0;
        indexAfterMatch = 0;
        while (startPosition != std::string::npos)
        {
            findWord(line, argv[2], indexAfterMatch, startPosition);
            if (startPosition == std::string::npos)
                break;
            getNextLine(newLine, line, startPosition, argv);
            indexAfterMatch = startPosition + s2_len;
            line = newLine;
        }
        if (!line.empty())
            outFile << newLine << std::endl;
        else
            outFile << std::endl;
    }
    return 0;

}
#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>
#include <vector>

enum class TokenType {
    tk_return,
    tk_int_literal,
    tk_semi
};

struct Token {
    TokenType type;
    std::optional<std::string> value;
};
// change void to std::vector<Token>
void lexically_analyse(const std::string &lexicon) {
    for (int i = 0; i < lexicon.length(); i++) {
        char c = lexicon.at(i);
                if (std::isalpha(c)) {
                    std::cout << c << std::endl;
                }
    }
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Incorrect number of parameters. Correct usage is: " << std::endl;
        std::cerr << "noisy <input.hy>" << std::endl;
        return EXIT_FAILURE;
    }


    std::string contents;
    {
        std::stringstream contents_stream;
        std::fstream input(argv[1], std::ios::in);
        contents_stream << input.rdbuf();
        contents= contents_stream.str();
    }

    lexically_analyse(contents);

    return EXIT_SUCCESS;
}
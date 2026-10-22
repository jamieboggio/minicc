#pragma once

#include "token.hpp"
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

class Lexer
{
public:
    Lexer(const std::filesystem::path& p);
    ~Lexer();
    std::vector<Token> Tokenize();
    const bool IsValid();

private:
    const std::filesystem::path m_filePath;
    std::ifstream m_file;
    std::vector<Token> m_tokens;
    std::string m_fileContents;
    bool m_isValid;
};
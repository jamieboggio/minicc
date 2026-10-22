#include "lexer.hpp"
#include <cstddef>
#include <fstream>
#include <regex>
#include <sstream>

Lexer::Lexer(const std::filesystem::path& p) : m_filePath(p)
{
    m_fileContents = "";
    m_file = std::ifstream(p);
    m_isValid = m_file.is_open();
    if (m_file) {
        std::stringstream buffer;
        buffer << m_file.rdbuf();
        m_fileContents = buffer.str();
        m_file.close();
    }
}

std::vector<Token> Lexer::Tokenize()
{

    return m_tokens;
}

const bool Lexer::IsValid()
{
    return m_isValid;
}
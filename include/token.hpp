#pragma once

enum class TokenType {
    TOKEN_IDEN,
    TOKEN_CONST,
    TOKEN_K_INT,
    TOKEN_K_VOID,
    TOKEN_K_RET,
    TOKEN_LPAR,
    TOKEN_RPAR,
    TOKEN_LCUR,
    TOKEN_RCUR,
    TOKEN_SEMCOL,
};

class Token
{
public:
    Token();
    ~Token();

private:
    TokenType m_tokenType;
};
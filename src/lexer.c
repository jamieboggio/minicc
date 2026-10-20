#include "lexer.h"

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>

#include "ds.h"

tokenlist_t tokens_from_file(FILE* fp)
{
    tokenlist_t list = {.token_array = NULL, .size = 0, .capacity = 0};
    tokenlist_init(&list, DEFAULT_SIZE);

    token_t cur_token;
    do {
        cur_token = scan_token(fp);

    } while (append(&list, cur_token) && cur_token != TOKEN_EOF);

    return list;
}

token_t scan_token(FILE* fp)
{
    int c;
    token_t token_candidate = TOKEN_ERROR;
S0:
    c = fgetc(fp);
    if (c == '{') {
        return TOKEN_LCUR;
    } else if (c == '}') {
        return TOKEN_RCUR;
    } else if (c == '(') {
        return TOKEN_LPAR;
    } else if (c == ')') {
        return TOKEN_RPAR;
    } else if (c == ';') {
        return TOKEN_SCOL;
    } else if (c == 'i') {
        token_candidate = TOKEN_INTT;
        goto S2;
    } else if (c == 'r') {
        token_candidate = TOKEN_RET;
        goto S4;
    } else if (isalpha(c)) {
        token_candidate = TOKEN_IDEN;
        goto S3;
    } else if (isdigit(c)) {
        token_candidate = TOKEN_INTL;
        goto S5;
    } else if (isspace(c)) {
        goto S0;
    } else if (c == EOF) {
        return TOKEN_EOF;
    } else {
        (void)ungetc(c, fp);
        return token_candidate;
    }
S1:
    return TOKEN_ERROR;
S2:
    c = fgetc(fp);
    if (c == 'n') {
        goto S6;
    } else if (isspace(c)) {
        return TOKEN_IDEN;
    } else if (isalnum(c)) {
        token_candidate = TOKEN_IDEN;
        goto S3;
    } else if (c == EOF) {
        return TOKEN_EOF;
    } else {
        (void)ungetc(c, fp);
        return token_candidate;
    }

S3:
    c = fgetc(fp);
    if (isspace(c)) {
        return token_candidate;
    } else if (isalnum(c)) {
        token_candidate = TOKEN_IDEN;
        goto S3;
    } else if (c == EOF) {
        return TOKEN_EOF;
    } else {
        (void)ungetc(c, fp);
        return token_candidate;
    }
S4:
    c = fgetc(fp);
    if (c == 'e') {
        goto S7;
    } else if (isspace(c)) {
        return TOKEN_IDEN;
    } else if (isalnum(c)) {
        token_candidate = TOKEN_IDEN;
        goto S3;
    } else if (c == EOF) {
        return TOKEN_EOF;
    } else {
        (void)ungetc(c, fp);
        return token_candidate;
    }
S5:
    c = fgetc(fp);
    if (isdigit(c)) {
        goto S5;
    } else if (c == EOF) {
        return TOKEN_EOF;
    } else {
        (void)ungetc(c, fp);
        return token_candidate;
    }
S6:
    c = fgetc(fp);
    if (isspace(c)) {
        return TOKEN_IDEN;
    } else if (isalnum(c)) {
        goto S3;
    } else if (c == EOF) {
        return TOKEN_EOF;
    } else {
        (void)ungetc(c, fp);
        return TOKEN_INTL;
    }
S7:
    c = fgetc(fp);
    if (c == 't') {
        goto S8;
    } else if (isspace(c)) {
        return TOKEN_IDEN;
    } else if (isalnum(c)) {
        goto S3;
    } else if (c == EOF) {
        return TOKEN_EOF;
    } else {
        (void)ungetc(c, fp);
        return TOKEN_INTL;
    }
S8:
    c = fgetc(fp);
    if (c == 'u') {
        goto S9;
    } else if (isspace(c)) {
        return TOKEN_INTT;
    } else if (isalnum(c)) {
        goto S3;
    } else if (c == EOF) {
        return TOKEN_EOF;
    } else {
        (void)ungetc(c, fp);
        return TOKEN_INTL;
    }
S9:
    c = fgetc(fp);
    if (c == 'r') {
        goto S10;
    } else if (isspace(c)) {
        return TOKEN_IDEN;
    } else if (isalnum(c)) {
        goto S3;
    } else if (c == EOF) {
        return TOKEN_EOF;
    } else {
        (void)ungetc(c, fp);
        return TOKEN_INTL;
    }
S10:
    c = fgetc(fp);
    if (isspace(c)) {
        return TOKEN_RET;
    } else if (isalnum(c)) {
        goto S3;
    } else if (c == EOF) {
        return TOKEN_EOF;
    } else {
        (void)ungetc(c, fp);
        return TOKEN_INTL;
    }

    return TOKEN_ERROR;
}

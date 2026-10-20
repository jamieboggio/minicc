#pragma once

#include <stdio.h>

#include "ds.h"

tokenlist_t tokens_from_file(FILE* fp);

token_t scan_token(FILE* fp);

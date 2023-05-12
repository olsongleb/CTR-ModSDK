/*
 * PSn00bSDK standard library
 * (C) 2019-2023 PSXSDK authors, Lameguy64, spicyjpeg - MPL licensed
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

int isprint(int ch);
int isgraph(int ch);
int isspace(int ch);
int isblank(int ch);
int isalpha(int ch);
int isdigit(int ch);

int tolower(int ch);
int toupper(int ch);

#ifdef __cplusplus
}
#endif

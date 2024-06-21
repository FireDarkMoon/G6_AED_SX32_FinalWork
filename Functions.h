#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

using namespace std;
using namespace System;

int IntRandom_(int, int);
char CharRandom_(char, char);
void Settings_();
void FontColor_(int);
void CharColor_(char, int);
void StringColor_(string, int);
void Show_(int, int);
void ShowColor_(int, int, int);
void ShowChar_(int, int, char);
void ShowString_(int, int, string);
void ShowCharColor_(int, int, char, int);
void ShowStringColor_(int, int, string, int);
void ClearScreen_();
bool PrimeNumber_(int);
void ShowBubble_(int*, int);
void BubbleSort_(int*, int, bool);
void WaitKey_();
void DrawTable_(int, int, int, int, int, int, int);

#endif

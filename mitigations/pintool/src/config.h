#pragma once
#include "pin.H"

#define MAXSYSCALLS		0x200	// this should be enough for Win7 (up to 419)

// hard-wired values can be used e.g. during testing
#define USE_KNOBS 1

#if USE_KNOBS
extern BOOL _nxKnob;
extern BOOL _paranoidKnob;
extern BOOL _rwKnob;
extern BOOL _leakKnob;
extern BOOL _libdftKnob;
#else
#define _paranoidKnob	false
#define _nxKnob			true
#define _rwKnob			true
#define _leakKnob		true
#define _libdftKnob		true
#endif

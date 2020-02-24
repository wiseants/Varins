#pragma once

#define TESTHR(hr) { if FAILED(hr) return FALSE; }
#define TESTBOOL(x) { if (!(x)) return FALSE; }

%{
#include "ns.tab.h"
%}
%option noyywrap
%%
[a-zA-Z]+ { return NAME; }
[0-9]+ { return NUMBER; }
[ \t\n]+ { }
. { fprintf(stderr, "bad char\n"); }

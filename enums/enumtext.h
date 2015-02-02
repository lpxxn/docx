#ifndef ENUMTEXT_H
#define ENUMTEXT_H

#include <QString>

namespace Docx {

enum class WD_PARAGRAPH_ALIGNMENT
{
    LEFT = 0,
    CENTER,
    RIGHT,
    JUSTIFY,
    DISTRIBUTE,
    JUSTIFY_MED,
    JUSTIFY_HI,
    JUSTIFY_LOW,
    THAI_JUSTIFY
};

enum class WD_UNDERLINE
{
    None = -1,
    SINGLE,
    WORDS,
    DOUBLE,
    DOTTED,
    THICK,
    DASH,
    DOT_DASH,
    DOT_DOT_DASH,
    WAVY,
    DOTTED_HEAVY,
    DASH_HEAVY,
    DOT_DASH_HEAVY,
    DOT_DOT_DASH_HEAVY,
    WAVY_HEAVY,
    DASH_LONG,
    WAVY_DOUBLE,
    DASH_LONG_HEAVY,

};

QString underLineToString(WD_UNDERLINE underline);

QString paragraphAlignToString(WD_PARAGRAPH_ALIGNMENT align);

}


#endif // ENUMTEXT_H

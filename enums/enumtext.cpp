#include "enumtext.h"

namespace Docx {

QString underLineToString(WD_UNDERLINE underline)
{
    switch (underline) {
        case WD_UNDERLINE::None:                return QStringLiteral("none"); break;
        case WD_UNDERLINE::SINGLE:              return QStringLiteral("single"); break;
        case WD_UNDERLINE::WORDS:               return QStringLiteral("words"); break;
        case WD_UNDERLINE::DOUBLE:              return QStringLiteral("double"); break;
        case WD_UNDERLINE::DOTTED:              return QStringLiteral("dotted"); break;
        case WD_UNDERLINE::THICK:               return QStringLiteral("thick"); break;
        case WD_UNDERLINE::DASH:                return QStringLiteral("dash"); break;
        case WD_UNDERLINE::DOT_DASH:            return QStringLiteral("dotDash"); break;
        case WD_UNDERLINE::DOT_DOT_DASH:        return QStringLiteral("dotDotDash"); break;
        case WD_UNDERLINE::WAVY:                return QStringLiteral("wave"); break;
        case WD_UNDERLINE::DOTTED_HEAVY:        return QStringLiteral("dottedHeavy"); break;
        case WD_UNDERLINE::DASH_HEAVY:          return QStringLiteral("dashedHeavy"); break;
        case WD_UNDERLINE::DOT_DASH_HEAVY:      return QStringLiteral("dashDotHeavy"); break;
        case WD_UNDERLINE::DOT_DOT_DASH_HEAVY:  return QStringLiteral("dashDotDotHeavy"); break;
        case WD_UNDERLINE::WAVY_HEAVY:          return QStringLiteral("wavyHeavy"); break;
        case WD_UNDERLINE::DASH_LONG:           return QStringLiteral("dashLong"); break;
        case WD_UNDERLINE::WAVY_DOUBLE:         return QStringLiteral("wavyDouble"); break;
        case WD_UNDERLINE::DASH_LONG_HEAVY:     return QStringLiteral("dashLongHeavy"); break;
    }
}

QString paragraphAlignToString(WD_PARAGRAPH_ALIGNMENT align)
{
    switch (align) {
        case WD_PARAGRAPH_ALIGNMENT::LEFT:          return QStringLiteral("left"); break;
        case WD_PARAGRAPH_ALIGNMENT::CENTER:        return QStringLiteral("center"); break;
        case WD_PARAGRAPH_ALIGNMENT::RIGHT:         return QStringLiteral("right"); break;
        case WD_PARAGRAPH_ALIGNMENT::JUSTIFY:       return QStringLiteral("both"); break;
        case WD_PARAGRAPH_ALIGNMENT::DISTRIBUTE:    return QStringLiteral("distribute"); break;
        case WD_PARAGRAPH_ALIGNMENT::JUSTIFY_MED:   return QStringLiteral("mediumKashida"); break;
        case WD_PARAGRAPH_ALIGNMENT::JUSTIFY_HI:    return QStringLiteral("highKashida"); break;
        case WD_PARAGRAPH_ALIGNMENT::JUSTIFY_LOW:   return QStringLiteral("lowKashida"); break;
        case WD_PARAGRAPH_ALIGNMENT::THAI_JUSTIFY:  return QStringLiteral("thaiDistribute"); break;
    }
}

}



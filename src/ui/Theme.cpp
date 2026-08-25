// SPDX-FileCopyrightText: Nheko Contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <QGuiApplication>
#include <array>

#include "Theme.h"

namespace {
struct ThemeData {
    QStringView name;
    QColor windowText;
    QColor button;
    QColor light;
    QColor dark;
    QColor mid;
    QColor text;
    QColor bright_text;
    QColor base;
    QColor window;
    QColor alternateBase;
    QColor highlight;
    QColor highlightedText;
    QColor toolTipBase;
    QColor toolTipText;
    QColor link;
    QColor buttonText;

    QColor sidebarBackground;
    QColor alternateButton;
    QColor red;
    QColor green;
    QColor orange;
    QColor error;
};

const std::array<ThemeData, 2> themeData = {
    ThemeData{ u"light",
      QColor(0x33, 0x33, 0x33), QColor(Qt::GlobalColor::white), QColor(0xef, 0xef, 0xef), QColor(70, 77, 93), QColor(220, 220, 220), QColor(0x33, 0x33, 0x33), QColor(0xf2, 0xf5, 0xf8), QColor(Qt::GlobalColor::white), QColor(Qt::GlobalColor::white),
      QColor(0xee, 0xee, 0xee), QColor(0x38, 0xa3, 0xd8), QColor(0xf4, 0xf4, 0xf5), QColor(Qt::GlobalColor::white), QColor(0x33, 0x33, 0x33), QColor(0x00, 0x77, 0xb5), QColor(0x55, 0x54, 0x59),
      QColor(0x23, 0x36, 0x49), QColor(0xcc, 0xcc, 0xcc), QColor(0xa8, 0x23, 0x53), QColor(QColorConstants::Svg::green), QColor(0xfc, 0xbe, 0x05), QColor(0xdd, 0x3d, 0x3d) },
    ThemeData{ u"dark",
      QColor(0xca, 0xcc, 0xd1), QColor(Qt::GlobalColor::white), QColor(0xca, 0xcc, 0xd1), QColor(60, 70, 77), QColor(0x20, 0x22, 0x28), QColor(0xca, 0xcc, 0xd1), QColor(0xf4, 0xf5, 0xf8), QColor(0x20, 0x22, 0x28), QColor(0x2d, 0x31, 0x39),
      QColor(0x2d, 0x31, 0x39), QColor(0x38, 0xa3, 0xd8), QColor(0xf4, 0xf5, 0xf8), QColor(0x20, 0x22, 0x28), QColor(0xca, 0xcc, 0xd1), QColor(0x38, 0xa3, 0xd8), QColor(0x82, 0x82, 0x84),
      QColor(0x2d, 0x31, 0x39), QColor(0x41, 0x4A, 0x59), QColor(0xa8, 0x23, 0x53), QColor(QColorConstants::Svg::green), QColor(0xfc, 0xc5, 0x3a), QColor(0xdd, 0x3d, 0x3d) }
};

const ThemeData* findThemeData(QStringView themeName) {
    for (const auto& t : themeData) {
        if (t.name == themeName) return &t;
    }
    return nullptr;
}
}

QPalette
Theme::paletteFromTheme(QStringView theme)
{
    static QPalette original = QGuiApplication::palette();
    if (auto data = findThemeData(theme)) {
        QPalette p(data->windowText, data->button, data->light, data->dark, data->mid, data->text, data->bright_text, data->base, data->window);
        p.setColor(QPalette::AlternateBase, data->alternateBase);
        p.setColor(QPalette::Highlight, data->highlight);
        p.setColor(QPalette::HighlightedText, data->highlightedText);
        p.setColor(QPalette::ToolTipBase, data->toolTipBase);
        p.setColor(QPalette::ToolTipText, data->toolTipText);
        p.setColor(QPalette::Link, data->link);
        p.setColor(QPalette::ButtonText, data->buttonText);
        return p;
    }
    return original;
}

Theme::Theme(QStringView theme)
{
    auto p     = paletteFromTheme(theme);
    separator_ = p.mid().color();
    if (auto data = findThemeData(theme)) {
        sidebarBackground_ = data->sidebarBackground;
        alternateButton_   = data->alternateButton;
        red_               = data->red;
        green_             = data->green;
        orange_            = data->orange;
        error_             = data->error;
    } else {
        sidebarBackground_ = p.window().color();
        alternateButton_   = p.dark().color();
        red_               = QColor(QColorConstants::Svg::red);
        green_             = QColor(QColorConstants::Svg::green);
        orange_            = QColor(QColorConstants::Svg::orange); // SVG orange
        error_             = QColor(0xdd, 0x3d, 0x3d);
    }
}

#include "moc_Theme.cpp"

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

const std::array<ThemeData, 36> themeData = {
    ThemeData{ u"light",
      QColor(0x33, 0x33, 0x33), QColor(Qt::GlobalColor::white), QColor(0xef, 0xef, 0xef), QColor(70, 77, 93), QColor(220, 220, 220), QColor(0x33, 0x33, 0x33), QColor(0xf2, 0xf5, 0xf8), QColor(Qt::GlobalColor::white), QColor(Qt::GlobalColor::white),
      QColor(0xee, 0xee, 0xee), QColor(0x38, 0xa3, 0xd8), QColor(0xf4, 0xf4, 0xf5), QColor(Qt::GlobalColor::white), QColor(0x33, 0x33, 0x33), QColor(0x00, 0x77, 0xb5), QColor(0x55, 0x54, 0x59),
      QColor(0x23, 0x36, 0x49), QColor(0xcc, 0xcc, 0xcc), QColor(0xa8, 0x23, 0x53), QColor(QColorConstants::Svg::green), QColor(0xfc, 0xbe, 0x05), QColor(0xdd, 0x3d, 0x3d) },
    ThemeData{ u"dark",
      QColor(0xca, 0xcc, 0xd1), QColor(Qt::GlobalColor::white), QColor(0xca, 0xcc, 0xd1), QColor(60, 70, 77), QColor(0x20, 0x22, 0x28), QColor(0xca, 0xcc, 0xd1), QColor(0xf4, 0xf5, 0xf8), QColor(0x20, 0x22, 0x28), QColor(0x2d, 0x31, 0x39),
      QColor(0x2d, 0x31, 0x39), QColor(0x38, 0xa3, 0xd8), QColor(0xf4, 0xf5, 0xf8), QColor(0x20, 0x22, 0x28), QColor(0xca, 0xcc, 0xd1), QColor(0x38, 0xa3, 0xd8), QColor(0x82, 0x82, 0x84),
      QColor(0x2d, 0x31, 0x39), QColor(0x41, 0x4A, 0x59), QColor(0xa8, 0x23, 0x53), QColor(QColorConstants::Svg::green), QColor(0xfc, 0xc5, 0x3a), QColor(0xdd, 0x3d, 0x3d) },
    ThemeData{ u"dracula",
      QColor("#f8f8f2"), QColor("#21222c"), QColor("#f8f8f2"), QColor("#282a36"), QColor("#44475a"), QColor("#f8f8f2"), QColor("#f8f8f2"), QColor("#21222c"), QColor("#282a36"),
      QColor("#282a36"), QColor("#bd93f9"), QColor("#21222c"), QColor("#21222c"), QColor("#f8f8f2"), QColor("#8be9fd"), QColor("#f8f8f2"),
      QColor("#282a36"), QColor("#44475a"), QColor("#ff5555"), QColor("#50fa7b"), QColor("#ffb86c"), QColor("#dd3d3d") },
    ThemeData{ u"nord",
      QColor("#d8dee9"), QColor("#3b4252"), QColor("#d8dee9"), QColor("#2e3440"), QColor("#434c5e"), QColor("#d8dee9"), QColor("#d8dee9"), QColor("#3b4252"), QColor("#2e3440"),
      QColor("#2e3440"), QColor("#88c0d0"), QColor("#3b4252"), QColor("#3b4252"), QColor("#d8dee9"), QColor("#88c0d0"), QColor("#d8dee9"),
      QColor("#2e3440"), QColor("#434c5e"), QColor("#bf616a"), QColor("#a3be8c"), QColor("#d08770"), QColor("#bf616a") },
    ThemeData{ u"gruvbox-dark",
      QColor("#ebdbb2"), QColor("#1d2021"), QColor("#ebdbb2"), QColor("#282828"), QColor("#3c3836"), QColor("#ebdbb2"), QColor("#ebdbb2"), QColor("#1d2021"), QColor("#282828"),
      QColor("#282828"), QColor("#83a598"), QColor("#1d2021"), QColor("#1d2021"), QColor("#ebdbb2"), QColor("#83a598"), QColor("#ebdbb2"),
      QColor("#282828"), QColor("#3c3836"), QColor("#fb4934"), QColor("#b8bb26"), QColor("#fe8019"), QColor("#dd3d3d") },
    ThemeData{ u"gruvbox-light",
      QColor("#3c3836"), QColor("#f2e5bc"), QColor("#3c3836"), QColor("#fbf1c7"), QColor("#d5c4a1"), QColor("#3c3836"), QColor("#3c3836"), QColor("#f2e5bc"), QColor("#fbf1c7"),
      QColor("#fbf1c7"), QColor("#076678"), QColor("#f2e5bc"), QColor("#f2e5bc"), QColor("#3c3836"), QColor("#076678"), QColor("#3c3836"),
      QColor("#fbf1c7"), QColor("#d5c4a1"), QColor("#9d0006"), QColor("#79740e"), QColor("#af3a03"), QColor("#dd3d3d") },
    ThemeData{ u"solarized-dark",
      QColor("#93a1a1"), QColor("#073642"), QColor("#93a1a1"), QColor("#002b36"), QColor("#586e75"), QColor("#93a1a1"), QColor("#93a1a1"), QColor("#073642"), QColor("#002b36"),
      QColor("#002b36"), QColor("#268bd2"), QColor("#073642"), QColor("#073642"), QColor("#93a1a1"), QColor("#268bd2"), QColor("#93a1a1"),
      QColor("#002b36"), QColor("#586e75"), QColor("#dc322f"), QColor("#859900"), QColor("#cb4b16"), QColor("#dc322f") },
    ThemeData{ u"solarized-light",
      QColor("#586e75"), QColor("#eee8d5"), QColor("#586e75"), QColor("#fdf6e3"), QColor("#93a1a1"), QColor("#586e75"), QColor("#586e75"), QColor("#eee8d5"), QColor("#fdf6e3"),
      QColor("#fdf6e3"), QColor("#268bd2"), QColor("#eee8d5"), QColor("#eee8d5"), QColor("#586e75"), QColor("#268bd2"), QColor("#586e75"),
      QColor("#fdf6e3"), QColor("#93a1a1"), QColor("#dc322f"), QColor("#859900"), QColor("#cb4b16"), QColor("#dd3d3d") },
    ThemeData{ u"tokyo-night",
      QColor("#c0caf5"), QColor("#16161e"), QColor("#c0caf5"), QColor("#1a1b26"), QColor("#292e42"), QColor("#c0caf5"), QColor("#c0caf5"), QColor("#16161e"), QColor("#1a1b26"),
      QColor("#1a1b26"), QColor("#7aa2f7"), QColor("#16161e"), QColor("#16161e"), QColor("#c0caf5"), QColor("#7aa2f7"), QColor("#c0caf5"),
      QColor("#1a1b26"), QColor("#292e42"), QColor("#f7768e"), QColor("#9ece6a"), QColor("#ff9e64"), QColor("#dd3d3d") },
    ThemeData{ u"tokyo-night-storm",
      QColor("#c0caf5"), QColor("#1f2335"), QColor("#c0caf5"), QColor("#24283b"), QColor("#3b4261"), QColor("#c0caf5"), QColor("#c0caf5"), QColor("#1f2335"), QColor("#24283b"),
      QColor("#24283b"), QColor("#7aa2f7"), QColor("#1f2335"), QColor("#1f2335"), QColor("#c0caf5"), QColor("#7aa2f7"), QColor("#c0caf5"),
      QColor("#24283b"), QColor("#3b4261"), QColor("#f7768e"), QColor("#9ece6a"), QColor("#ff9e64"), QColor("#dd3d3d") },
    ThemeData{ u"catppuccin-mocha",
      QColor("#cdd6f4"), QColor("#181825"), QColor("#cdd6f4"), QColor("#1e1e2e"), QColor("#313244"), QColor("#cdd6f4"), QColor("#cdd6f4"), QColor("#181825"), QColor("#1e1e2e"),
      QColor("#1e1e2e"), QColor("#89b4fa"), QColor("#181825"), QColor("#181825"), QColor("#cdd6f4"), QColor("#89b4fa"), QColor("#cdd6f4"),
      QColor("#1e1e2e"), QColor("#313244"), QColor("#f38ba8"), QColor("#a6e3a1"), QColor("#fab387"), QColor("#dd3d3d") },
    ThemeData{ u"catppuccin-macchiato",
      QColor("#cad3f5"), QColor("#1e2030"), QColor("#cad3f5"), QColor("#24273a"), QColor("#363a4f"), QColor("#cad3f5"), QColor("#cad3f5"), QColor("#1e2030"), QColor("#24273a"),
      QColor("#24273a"), QColor("#8aadf4"), QColor("#1e2030"), QColor("#1e2030"), QColor("#cad3f5"), QColor("#8aadf4"), QColor("#cad3f5"),
      QColor("#24273a"), QColor("#363a4f"), QColor("#ed8796"), QColor("#a6da95"), QColor("#f5a97f"), QColor("#dd3d3d") },
    ThemeData{ u"catppuccin-frappe",
      QColor("#c6d0f5"), QColor("#292c3c"), QColor("#c6d0f5"), QColor("#303446"), QColor("#414559"), QColor("#c6d0f5"), QColor("#c6d0f5"), QColor("#292c3c"), QColor("#303446"),
      QColor("#303446"), QColor("#8caaee"), QColor("#292c3c"), QColor("#292c3c"), QColor("#c6d0f5"), QColor("#8caaee"), QColor("#c6d0f5"),
      QColor("#303446"), QColor("#414559"), QColor("#e78284"), QColor("#a6d189"), QColor("#ef9f76"), QColor("#e78284") },
    ThemeData{ u"catppuccin-latte",
      QColor("#4c4f69"), QColor("#e6e9ef"), QColor("#4c4f69"), QColor("#eff1f5"), QColor("#ccd0da"), QColor("#4c4f69"), QColor("#4c4f69"), QColor("#e6e9ef"), QColor("#eff1f5"),
      QColor("#eff1f5"), QColor("#1e66f5"), QColor("#e6e9ef"), QColor("#e6e9ef"), QColor("#4c4f69"), QColor("#1e66f5"), QColor("#4c4f69"),
      QColor("#eff1f5"), QColor("#ccd0da"), QColor("#d20f39"), QColor("#40a02b"), QColor("#fe640b"), QColor("#dd3d3d") },
    ThemeData{ u"everforest",
      QColor("#d3c6aa"), QColor("#232a2e"), QColor("#d3c6aa"), QColor("#2d353b"), QColor("#475258"), QColor("#d3c6aa"), QColor("#d3c6aa"), QColor("#232a2e"), QColor("#2d353b"),
      QColor("#2d353b"), QColor("#a7c080"), QColor("#232a2e"), QColor("#232a2e"), QColor("#d3c6aa"), QColor("#7fbbb3"), QColor("#d3c6aa"),
      QColor("#2d353b"), QColor("#475258"), QColor("#e67e80"), QColor("#a7c080"), QColor("#e69875"), QColor("#e67e80") },
    ThemeData{ u"rose-pine",
      QColor("#e0def4"), QColor("#1f1d2e"), QColor("#e0def4"), QColor("#191724"), QColor("#403d52"), QColor("#e0def4"), QColor("#e0def4"), QColor("#1f1d2e"), QColor("#191724"),
      QColor("#191724"), QColor("#c4a7e7"), QColor("#1f1d2e"), QColor("#1f1d2e"), QColor("#e0def4"), QColor("#9ccfd8"), QColor("#e0def4"),
      QColor("#191724"), QColor("#403d52"), QColor("#eb6f92"), QColor("#31748f"), QColor("#f6c177"), QColor("#dd3d3d") },
    ThemeData{ u"rose-pine-moon",
      QColor("#e0def4"), QColor("#2a273f"), QColor("#e0def4"), QColor("#232136"), QColor("#44415a"), QColor("#e0def4"), QColor("#e0def4"), QColor("#2a273f"), QColor("#232136"),
      QColor("#232136"), QColor("#c4a7e7"), QColor("#2a273f"), QColor("#2a273f"), QColor("#e0def4"), QColor("#9ccfd8"), QColor("#e0def4"),
      QColor("#232136"), QColor("#44415a"), QColor("#eb6f92"), QColor("#3e8fb0"), QColor("#f6c177"), QColor("#dd3d3d") },
    ThemeData{ u"kanagawa",
      QColor("#dcd7ba"), QColor("#16161d"), QColor("#dcd7ba"), QColor("#1f1f28"), QColor("#363646"), QColor("#dcd7ba"), QColor("#dcd7ba"), QColor("#16161d"), QColor("#1f1f28"),
      QColor("#1f1f28"), QColor("#7e9cd8"), QColor("#16161d"), QColor("#16161d"), QColor("#dcd7ba"), QColor("#7fb4ca"), QColor("#dcd7ba"),
      QColor("#1f1f28"), QColor("#363646"), QColor("#e46876"), QColor("#98bb6c"), QColor("#ffa066"), QColor("#dd3d3d") },
    ThemeData{ u"material-oceanic",
      QColor("#eeffff"), QColor("#1e272c"), QColor("#eeffff"), QColor("#263238"), QColor("#37474f"), QColor("#eeffff"), QColor("#eeffff"), QColor("#1e272c"), QColor("#263238"),
      QColor("#263238"), QColor("#82aaff"), QColor("#1e272c"), QColor("#1e272c"), QColor("#eeffff"), QColor("#89ddff"), QColor("#eeffff"),
      QColor("#263238"), QColor("#37474f"), QColor("#f07178"), QColor("#c3e88d"), QColor("#ffcb6b"), QColor("#dd3d3d") },
    ThemeData{ u"material-darker",
      QColor("#eeffff"), QColor("#1e1e1e"), QColor("#eeffff"), QColor("#212121"), QColor("#2f2f2f"), QColor("#eeffff"), QColor("#eeffff"), QColor("#1e1e1e"), QColor("#212121"),
      QColor("#212121"), QColor("#82aaff"), QColor("#1e1e1e"), QColor("#1e1e1e"), QColor("#eeffff"), QColor("#89ddff"), QColor("#eeffff"),
      QColor("#212121"), QColor("#2f2f2f"), QColor("#f07178"), QColor("#c3e88d"), QColor("#ffcb6b"), QColor("#dd3d3d") },
    ThemeData{ u"molokai-dim",
      QColor("#f8f8f2"), QColor("#1e1f1c"), QColor("#f8f8f2"), QColor("#272822"), QColor("#49483e"), QColor("#f8f8f2"), QColor("#f8f8f2"), QColor("#1e1f1c"), QColor("#272822"),
      QColor("#272822"), QColor("#66d9ef"), QColor("#1e1f1c"), QColor("#1e1f1c"), QColor("#f8f8f2"), QColor("#66d9ef"), QColor("#f8f8f2"),
      QColor("#272822"), QColor("#49483e"), QColor("#f92672"), QColor("#a6e22e"), QColor("#fd971f"), QColor("#dd3d3d") },
    ThemeData{ u"monokai",
      QColor("#f8f8f2"), QColor("#1b1d1e"), QColor("#f8f8f2"), QColor("#272822"), QColor("#3e3d32"), QColor("#f8f8f2"), QColor("#f8f8f2"), QColor("#1b1d1e"), QColor("#272822"),
      QColor("#272822"), QColor("#66d9ef"), QColor("#1b1d1e"), QColor("#1b1d1e"), QColor("#f8f8f2"), QColor("#66d9ef"), QColor("#f8f8f2"),
      QColor("#272822"), QColor("#3e3d32"), QColor("#f92672"), QColor("#a6e22e"), QColor("#fd971f"), QColor("#dd3d3d") },
    ThemeData{ u"one-dark",
      QColor("#abb2bf"), QColor("#21252b"), QColor("#abb2bf"), QColor("#282c34"), QColor("#3e4451"), QColor("#abb2bf"), QColor("#abb2bf"), QColor("#21252b"), QColor("#282c34"),
      QColor("#282c34"), QColor("#61afef"), QColor("#21252b"), QColor("#21252b"), QColor("#abb2bf"), QColor("#61afef"), QColor("#abb2bf"),
      QColor("#282c34"), QColor("#3e4451"), QColor("#e06c75"), QColor("#98c379"), QColor("#d19a66"), QColor("#dd3d3d") },
    ThemeData{ u"github-dark",
      QColor("#c9d1d9"), QColor("#010409"), QColor("#c9d1d9"), QColor("#0d1117"), QColor("#30363d"), QColor("#c9d1d9"), QColor("#c9d1d9"), QColor("#010409"), QColor("#0d1117"),
      QColor("#0d1117"), QColor("#58a6ff"), QColor("#010409"), QColor("#010409"), QColor("#c9d1d9"), QColor("#58a6ff"), QColor("#c9d1d9"),
      QColor("#0d1117"), QColor("#30363d"), QColor("#f85149"), QColor("#3fb950"), QColor("#d29922"), QColor("#dd3d3d") },
    ThemeData{ u"ayu-dark-variant",
      QColor("#b3b1ad"), QColor("#0a0e13"), QColor("#b3b1ad"), QColor("#0f1419"), QColor("#253340"), QColor("#b3b1ad"), QColor("#b3b1ad"), QColor("#0a0e13"), QColor("#0f1419"),
      QColor("#0f1419"), QColor("#59c2ff"), QColor("#0a0e13"), QColor("#0a0e13"), QColor("#b3b1ad"), QColor("#59c2ff"), QColor("#b3b1ad"),
      QColor("#0f1419"), QColor("#253340"), QColor("#f07178"), QColor("#aad94c"), QColor("#ffb454"), QColor("#dd3d3d") },
    ThemeData{ u"ayu-mirage-variant",
      QColor("#cbccc6"), QColor("#1a1f29"), QColor("#cbccc6"), QColor("#1f2430"), QColor("#33415e"), QColor("#cbccc6"), QColor("#cbccc6"), QColor("#1a1f29"), QColor("#1f2430"),
      QColor("#1f2430"), QColor("#73d0ff"), QColor("#1a1f29"), QColor("#1a1f29"), QColor("#cbccc6"), QColor("#73d0ff"), QColor("#cbccc6"),
      QColor("#1f2430"), QColor("#33415e"), QColor("#f28779"), QColor("#bae67e"), QColor("#ffcc66"), QColor("#dd3d3d") },
    ThemeData{ u"nightfox",
      QColor("#cdcecf"), QColor("#131a24"), QColor("#cdcecf"), QColor("#192330"), QColor("#2b3b51"), QColor("#cdcecf"), QColor("#cdcecf"), QColor("#131a24"), QColor("#192330"),
      QColor("#192330"), QColor("#719cd6"), QColor("#131a24"), QColor("#131a24"), QColor("#cdcecf"), QColor("#719cd6"), QColor("#cdcecf"),
      QColor("#192330"), QColor("#2b3b51"), QColor("#c94f6d"), QColor("#81b29a"), QColor("#f4a261"), QColor("#dd3d3d") },
    ThemeData{ u"oxocarbon-oled",
      QColor("#f2f4f8"), QColor("#0d0d0d"), QColor("#f2f4f8"), QColor("#161616"), QColor("#393939"), QColor("#f2f4f8"), QColor("#f2f4f8"), QColor("#0d0d0d"), QColor("#161616"),
      QColor("#161616"), QColor("#33b1ff"), QColor("#0d0d0d"), QColor("#0d0d0d"), QColor("#f2f4f8"), QColor("#33b1ff"), QColor("#f2f4f8"),
      QColor("#161616"), QColor("#393939"), QColor("#ee5396"), QColor("#42be65"), QColor("#ff7eb6"), QColor("#dd3d3d") },
    ThemeData{ u"oxocarbon",
      QColor("#f2f4f8"), QColor("#262626"), QColor("#f2f4f8"), QColor("#161616"), QColor("#393939"), QColor("#f2f4f8"), QColor("#f2f4f8"), QColor("#262626"), QColor("#161616"),
      QColor("#161616"), QColor("#33b1ff"), QColor("#262626"), QColor("#262626"), QColor("#f2f4f8"), QColor("#33b1ff"), QColor("#f2f4f8"),
      QColor("#161616"), QColor("#393939"), QColor("#ee5396"), QColor("#42be65"), QColor("#ff7eb6"), QColor("#dd3d3d") },
    ThemeData{ u"oled",
      QColor("#d0d0d0"), QColor("#0a0a0a"), QColor("#d0d0d0"), QColor(Qt::GlobalColor::black), QColor("#1c1c1c"), QColor("#d0d0d0"), QColor("#d0d0d0"), QColor("#0a0a0a"), QColor(Qt::GlobalColor::black),
      QColor(Qt::GlobalColor::black), QColor("#38a3d8"), QColor("#0a0a0a"), QColor("#0a0a0a"), QColor("#d0d0d0"), QColor("#38a3d8"), QColor("#d0d0d0"),
      QColor(Qt::GlobalColor::black), QColor("#1c1c1c"), QColor("#cf4f5f"), QColor("#5aa55a"), QColor("#d08b3a"), QColor("#dd3d3d") },
    ThemeData{ u"carbon",
      QColor("#e0e0e0"), QColor("#0d0d0d"), QColor("#e0e0e0"), QColor("#161616"), QColor("#333333"), QColor("#e0e0e0"), QColor("#e0e0e0"), QColor("#0d0d0d"), QColor("#161616"),
      QColor("#161616"), QColor("#6f6f6f"), QColor("#0d0d0d"), QColor("#0d0d0d"), QColor("#e0e0e0"), QColor("#a0a0a0"), QColor("#e0e0e0"),
      QColor("#161616"), QColor("#333333"), QColor("#b04040"), QColor("#5a8a5a"), QColor("#b08040"), QColor("#dd3d3d") },
    ThemeData{ u"dim",
      QColor("#b8bdc4"), QColor("#2b2f34"), QColor("#b8bdc4"), QColor("#33383d"), QColor("#4a5058"), QColor("#b8bdc4"), QColor("#b8bdc4"), QColor("#2b2f34"), QColor("#33383d"),
      QColor("#33383d"), QColor("#5294c4"), QColor("#2b2f34"), QColor("#2b2f34"), QColor("#b8bdc4"), QColor("#5294c4"), QColor("#b8bdc4"),
      QColor("#33383d"), QColor("#4a5058"), QColor("#c76a7d"), QColor("#8bab6e"), QColor("#d4a257"), QColor("#c76a7d") },
    ThemeData{ u"slate",
      QColor("#adbac7"), QColor("#14181d"), QColor("#adbac7"), QColor("#1c2128"), QColor("#2d333b"), QColor("#adbac7"), QColor("#adbac7"), QColor("#14181d"), QColor("#1c2128"),
      QColor("#1c2128"), QColor("#539bf5"), QColor("#14181d"), QColor("#14181d"), QColor("#adbac7"), QColor("#539bf5"), QColor("#adbac7"),
      QColor("#1c2128"), QColor("#2d333b"), QColor("#e5534b"), QColor("#57ab5a"), QColor("#c69026"), QColor("#dd3d3d") },
    ThemeData{ u"ember",
      QColor("#e8d5c8"), QColor("#1a1210"), QColor("#e8d5c8"), QColor("#241a17"), QColor("#3d2b25"), QColor("#e8d5c8"), QColor("#e8d5c8"), QColor("#1a1210"), QColor("#241a17"),
      QColor("#241a17"), QColor("#d98c5f"), QColor("#1a1210"), QColor("#1a1210"), QColor("#e8d5c8"), QColor("#d98c5f"), QColor("#e8d5c8"),
      QColor("#241a17"), QColor("#3d2b25"), QColor("#d95f5f"), QColor("#8fa85f"), QColor("#e0a458"), QColor("#dd3d3d") },
    ThemeData{ u"deep-sea",
      QColor("#c2d6da"), QColor("#0a161b"), QColor("#c2d6da"), QColor("#0f1e24"), QColor("#1e3a42"), QColor("#c2d6da"), QColor("#c2d6da"), QColor("#0a161b"), QColor("#0f1e24"),
      QColor("#0f1e24"), QColor("#4fb3bf"), QColor("#0a161b"), QColor("#0a161b"), QColor("#c2d6da"), QColor("#4fb3bf"), QColor("#c2d6da"),
      QColor("#0f1e24"), QColor("#1e3a42"), QColor("#d96a72"), QColor("#6ec49a"), QColor("#dba95c"), QColor("#dd3d3d") },
    ThemeData{ u"plum",
      QColor("#ddd0e8"), QColor("#1a1322"), QColor("#ddd0e8"), QColor("#21182b"), QColor("#3a2b47"), QColor("#ddd0e8"), QColor("#ddd0e8"), QColor("#1a1322"), QColor("#21182b"),
      QColor("#21182b"), QColor("#a97bd6"), QColor("#1a1322"), QColor("#1a1322"), QColor("#ddd0e8"), QColor("#a97bd6"), QColor("#ddd0e8"),
      QColor("#21182b"), QColor("#3a2b47"), QColor("#d96a92"), QColor("#7fbf8f"), QColor("#d99a5c"), QColor("#dd3d3d") },
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

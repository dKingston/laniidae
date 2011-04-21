// qt-gui -- A Qt GUI interface to liblaniidae.
// Copyright (c) 2011 Michael Rodriguez et al.
// Rights to this code are documented in `docs/LICENSE`.

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "main_window.hpp"

// FUNCTION:  main()
// PURPOSE:   Standard C++ program entry point
// ARGUMENTS: argc -- Argument count,
//            argv -- Argument vector
//
// RETURNS: QApplication `exec()` method.
int
main(int argc, char *argv[])
{
    // Declare proper Qt objects.
    QApplication app(argc, argv);
    MainWindow   win;
    QTranslator  trans;

    // These are needed for QSettings, if it is constructed with no parameters.
    app.setOrganizationName("laniidae project");
    app.setApplicationName("laniidae");

    // Locale-aware translations.  If the proper language file is found, then it
    // is loaded and used.  If not, it defaults to American English.
    trans.load("lang/" + QLocale::system().name());
    app.installTranslator(&trans);

    win.show();
    return app.exec();
}

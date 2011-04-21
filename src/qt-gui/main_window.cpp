// qt-gui -- A Qt GUI interface to liblaniidae.
// Copyright (c) 2011 Michael Rodriguez et al.
// Rights to this code are documented in `docs/LICENSE`.

#include <QtGui>
#include "main_window.hpp"
#include "opengl.hpp"

// CLASS METHOD: MainWindow::MainWindow()
// PURPOSE:      MainWindow constructor
// ARGUMENTS:    None
// RETURNS:      None
MainWindow::MainWindow(void)
{
    opengl = new GLWidget();
    setCentralWidget(opengl);

    create_actions();
    create_menus();
    create_status_bar();

    read_settings();
}

// CLASS METHOD: MainWindow::~MainWindow()
// PURPOSE:      MainWindow deconstructor
// ARGUMENTS:    None
// RETURNS:      None
MainWindow::~MainWindow(void)
{ }

// CLASS METHOD: MainWindow::mount_cdrom_image()
// PURPOSE:      Called when "File->Mount CD-ROM image" is clicked on by a user.
// ARGUMENTS:    None
// RETURNS:      None
void
MainWindow::mount_cdrom_image(void)
{
    QString file = QFileDialog::getOpenFileName(this,
                                                tr("Open game image"),
                                                settings_default_image_path,
                                                tr("Game images (*.ecm *.iso *.bin)"));
}

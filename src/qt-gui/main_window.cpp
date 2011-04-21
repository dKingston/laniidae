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

// CLASS METHOD: MainWindow::create_actions()
// PURPOSE:      Create actions which are done by the end-user
// ARGUMENTS:    None
// RETURNS:      None
void
MainWindow::create_actions(void)
{
    mount_cd_image = new QAction(tr("Mount CD-ROM Image"), this);
    connect(mount_cd_image, SIGNAL(triggered()), this, SLOT(mount_cdrom_image()));

    mount_cd_disc = new QAction(tr("Mount CD-ROM Disc"), this);
    connect(mount_cd_disc, SIGNAL(triggered()), this, SLOT(mount_cdrom_disc()));

    umount_cd = new QAction(tr("Unmount CD-ROM"), this);
    connect(umount_cd, SIGNAL(triggered()), this, SLOT(unmount_cdrom()));

    conf = new QAction(tr("Configure"), this);
    connect(conf, SIGNAL(triggered()), this, SLOT(configure()));

    end = new QAction(tr("Exit"), this);
    connect(end, SIGNAL(triggered()), this, SLOT(app_exit()));
}

// CLASS METHOD: MainWindow::create_menus()
// PURPOSE:      Create menus for the end-user
// ARGUMENTS:    None
// RETURNS:      None
void
MainWindow::create_menus(void)
{
    file = menuBar()->addMenu(tr("&File"));
    file->addAction(mount_cd_image);
    file->addAction(mount_cd_disc);
    file->addAction(umount_cd);
    file->addSeparator();
    file->addAction(conf);
    file->addAction(end);
}

// CLASS METHOD: MainWindow::create_status_bar()
// PURPOSE:      Create status bar for the end-user
// ARGUMENTS:    None
// RETURNS:      None
void
MainWindow::create_status_bar(void)
{
    statusBar()->showMessage(tr("Vi veri universum vivus vici"));
}

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

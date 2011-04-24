// qt-gui -- A Qt GUI interface to liblaniidae.
// Copyright (c) 2011 Michael Rodriguez et al.
// Rights to this code are documented in `docs/LICENSE`.

#pragma once

#include <QMainWindow>
#include "opengl.hpp"

// Forward class declarations.
class QAction;
class QMenu;

class MainWindow : public QMainWindow
{
    // This macro is needed for the `moc` compiler, which produces C++ source
    // code containing meta-object code for classes.  This is required because
    // of signals and slot methods.
    Q_OBJECT

 public:
    MainWindow(void);
    ~MainWindow(void);

 private slots:
    void mount_cdrom_image(void);
    void mount_cdrom_disc(void);
    void unmount_cd(void);
    void configure(void);
    void exit(void);

 private:
    void create_actions(void);
    void create_menus(void);
    void create_status_bar(void);
    void read_settings(void);
    void write_settings(void);

    GLWidget *opengl;
    QMenu    *file;
    QAction  *mount_cd_image;
    QAction  *mount_cd_disc;
    QAction  *umount_cd;
    QAction  *conf;
    QAction  *end;
};

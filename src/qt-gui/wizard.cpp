// qt-gui -- A Qt GUI interface to liblaniidae.
// Copyright (c) 2011 Michael Rodriguez et al.
// Rights to this code are documented in `docs/LICENSE`.

#include "wizard.hpp"

// CLASS METHOD: Wizard::Wizard(QWidget *parent) : QWizard(parent)
// PURPOSE:      Wizard constructor
// ARGUMENTS:    Parent widget (window)
// RETURNS:      None
Wizard::Wizard(QWidget *parent) : QWizard(parent)
{
    setPage(intro,    new IntroPage);
    setPage(paths,    new PathsPage);
    setPage(sound,    new SoundPage);
    setPage(graphics, new GraphicsPage);
    setPage(control,  new ControlPage);
    setPage(keybind,  new KeyBindPage);
    setPage(cdrom,    new CDPage);

    setStartId(intro);
    setOption(HaveHelpButton, true);

    connect(this, SIGNAL(helpRequested()), this, SLOT(show_help()));
    setWindowTitle(tr("laniidae first-time run wizard"));
}

// CLASS METHOD: Wizard::~Wizard(void)
// PURPOSE:      Wizard destructor
// ARGUMENTS:    None
// RETURNS:      None
Wizard::~Wizard(void)
{ }

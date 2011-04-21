build_type = ARGUMENTS.get('build_type', 'debug')
cppflags   = None

if build_type == 'release':
    cppflags = '-O2'
elif build_type == 'debug':
    cppflags = ['-O0', '-g', '-ggdb', '-Wall', '-Wextra', '-pedantic']

env = Environment(CPPFLAGS = cppflags)
Export('env')

SConscript('src/liblaniidae/SConscript')
SConscript('src/qt-gui/SConscript')

build_type = ARGUMENTS.get('build_type', 'debug')
compiler   = ARGUMENTS.get('compiler', 'clang++')
cppflags   = None

if build_type == 'release':
    cppflags = '-O2'
elif build_type == 'debug':
    cppflags = ['-O0', '-g', '-ggdb', '-Wall', '-Wextra', '-pedantic']

env = Environment(CPP      = compiler,
                  CPPFLAGS = cppflags)

Export('env')

SConscript('src/liblaniidae/SConscript')
SConscript('src/qt-gui/SConscript')

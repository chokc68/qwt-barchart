QWT_VER_MAJ = 6
QWT_VER_MIN = 2
QWT_VER_PAT = 0
QWT_VERSION = $${QWT_VER_MAJ}.$${QWT_VER_MIN}.$${QWT_VER_PAT}
QWT_ROOT = C:/Library/qwt-$$QWT_VERSION

TEMPLATE     = app
INCLUDEPATH += $${QWT_ROOT}/src
DEPENDPATH  += $${QWT_ROOT}/src
CONFIG(debug, debug|release) {
    LIBS += -L$${QWT_ROOT}/lib -lqwtd
}
CONFIG(release, debug|release) {
    LIBS += -L$${QWT_ROOT}/lib -lqwt
}

QWT_CONFIG     += QwtDll
QWT_CONFIG     += QwtOpenGL
QWT_CONFIG     += QwtSvg

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += printsupport
    QT += concurrent
}

contains(QWT_CONFIG, QwtDll) {
    DEFINES    += QT_DLL QWT_DLL
}

contains(QWT_CONFIG, QwtOpenGL) {
    QT += opengl
    greaterThan(QT_MAJOR_VERSION, 5) {
        QT += openglwidgets
    }
}
else {
    DEFINES += QWT_NO_OPENGL
}

contains(QWT_CONFIG, QwtSvg) {
    QT += svg
}
else {
    DEFINES += QWT_NO_SVG
}

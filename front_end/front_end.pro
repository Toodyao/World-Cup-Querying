QT += quick
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    backendqml.cpp \
    main.cpp \
    ../back_end/src/backend.cpp \
    ../back_end/src/demo.cpp \
    ../back_end/src/knockout.cpp \
    ../back_end/src/match.cpp \
    ../back_end/src/matches.cpp \
    ../back_end/src/my_time.cpp \
    ../back_end/src/player.cpp \
    ../back_end/src/team.cpp \
    ../back_end/src/team_event.cpp \
    ../back_end/src/timeline.cpp \
    ../back_end/src/comments.cpp \

RESOURCES += qml.qrc

INCLUDEPATH += \
    ../back_end/third_party/rapidjson/include \
    ../back_end/src

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    backendqml.h \
    ../back_end/src/backend.h \
    ../back_end/src/compare.hpp \
    ../back_end/src/demo.h \
    ../back_end/src/hash.hpp \
    ../back_end/src/heap.hpp \
    ../back_end/src/knockout.h \
    ../back_end/src/my_time.h \
    ../back_end/src/my_vector.hpp \
    ../back_end/src/rank.hpp \
    ../back_end/src/structures.h \
    ../back_end/src/timeline.h \
    ../back_end/src/comments.h \
    ../back_end/third_party/rapidjson/include/rapidjson/error/en.h \
    ../back_end/third_party/rapidjson/include/rapidjson/error/error.h \
    ../back_end/third_party/rapidjson/include/rapidjson/internal/biginteger.h \
    ../back_end/third_party/rapidjson/include/rapidjson/internal/diyfp.h \
    ../back_end/third_party/rapidjson/include/rapidjson/internal/dtoa.h \
    ../back_end/third_party/rapidjson/include/rapidjson/internal/ieee754.h \
    ../back_end/third_party/rapidjson/include/rapidjson/internal/itoa.h \
    ../back_end/third_party/rapidjson/include/rapidjson/internal/meta.h \
    ../back_end/third_party/rapidjson/include/rapidjson/internal/pow10.h \
    ../back_end/third_party/rapidjson/include/rapidjson/internal/regex.h \
    ../back_end/third_party/rapidjson/include/rapidjson/internal/stack.h \
    ../back_end/third_party/rapidjson/include/rapidjson/internal/strfunc.h \
    ../back_end/third_party/rapidjson/include/rapidjson/internal/strtod.h \
    ../back_end/third_party/rapidjson/include/rapidjson/internal/swap.h \
    ../back_end/third_party/rapidjson/include/rapidjson/msinttypes/inttypes.h \
    ../back_end/third_party/rapidjson/include/rapidjson/msinttypes/stdint.h \
    ../back_end/third_party/rapidjson/include/rapidjson/allocators.h \
    ../back_end/third_party/rapidjson/include/rapidjson/cursorstreamwrapper.h \
    ../back_end/third_party/rapidjson/include/rapidjson/document.h \
    ../back_end/third_party/rapidjson/include/rapidjson/encodedstream.h \
    ../back_end/third_party/rapidjson/include/rapidjson/encodings.h \
    ../back_end/third_party/rapidjson/include/rapidjson/filereadstream.h \
    ../back_end/third_party/rapidjson/include/rapidjson/filewritestream.h \
    ../back_end/third_party/rapidjson/include/rapidjson/fwd.h \
    ../back_end/third_party/rapidjson/include/rapidjson/istreamwrapper.h \
    ../back_end/third_party/rapidjson/include/rapidjson/memorybuffer.h \
    ../back_end/third_party/rapidjson/include/rapidjson/memorystream.h \
    ../back_end/third_party/rapidjson/include/rapidjson/ostreamwrapper.h \
    ../back_end/third_party/rapidjson/include/rapidjson/pointer.h \
    ../back_end/third_party/rapidjson/include/rapidjson/prettywriter.h \
    ../back_end/third_party/rapidjson/include/rapidjson/rapidjson.h \
    ../back_end/third_party/rapidjson/include/rapidjson/reader.h \
    ../back_end/third_party/rapidjson/include/rapidjson/schema.h \
    ../back_end/third_party/rapidjson/include/rapidjson/stream.h \
    ../back_end/third_party/rapidjson/include/rapidjson/stringbuffer.h \
    ../back_end/third_party/rapidjson/include/rapidjson/writer.h


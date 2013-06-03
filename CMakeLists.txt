project(vmgviewer)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(vmgviewer_SRCS vbody.cpp venv.cpp vcard.cpp vmsg.cpp vmgviewer.cpp main.cpp)
qt4_automoc(${vmgviewer_SRCS})
add_executable(vmgviewer ${vmgviewer_SRCS})
target_link_libraries(vmgviewer ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

install(TARGETS vmgviewer
	  DESTINATION /usr/bin
)
install(FILES COPYRIGHT README DESTINATION /usr/share/Wtk)
install(FILES vmgviewer.desktop DESTINATION /usr/share/applications)
install(DIRECTORY icons DESTINATION /usr/share/Wtk)


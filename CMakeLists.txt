cmake_minimum_required(VERSION 3.29)
project(GeoDart_Standalone)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Charts
        SerialPort
        REQUIRED)

#qt_add_resources(GeoDart_Standalone "images"
#        PREFIX "/images"
#        FILES DartLogo-4.png
#)

add_executable(GeoDart_Standalone
        resources/resouces.qrc
        src/main.cpp
        src/GDForms/GDMainForm.h
        src/GDForms/GDMainForm.cpp
        src/GDForms/File/GDCreateNewHoleForm.cpp
        src/GDForms/File/GDCreateNewHoleForm.h
        src/GDForms/Chart/GDSignalStrengthForm.cpp
        src/GDForms/Chart/GDSignalStrengthForm.h
        src/GDForms/Chart/GDBatteryChargeForm.cpp
        src/GDForms/Chart/GDBatteryChargeForm.h
        src/GDForms/Chart/GDTemperatureForm.cpp
        src/GDForms/Chart/GDTemperatureForm.h
        src/GDForms/Tools/GDDiagnosticsForm.cpp
        src/GDForms/Tools/GDDiagnosticsForm.h
        src/GDForms/Options/GDSettingsForm.cpp
        src/GDForms/Options/GDSettingsForm.h
        src/GDForms/Main/GDDrillingChartWidget.cpp
        src/GDForms/Main/GDDrillingChartWidget.h
        src/GDForms/Main/GDTopPanelWidget.cpp
        src/GDForms/Main/GDTopPanelWidget.h
        src/GDForms/Main/GDDrillingTableWidget.cpp
        src/GDForms/Main/GDDrillingTableWidget.h
        src/GDForms/Main/GDTLFWidget.cpp
        src/GDForms/Main/GDTLFWidget.h
        src/GDForms/Main/GDGammaTLFWidget.cpp
        src/GDForms/Main/GDGammaTLFWidget.h
        src/GDForms/Main/GDProbeWidget.cpp
        src/GDForms/Main/GDProbeWidget.h
        src/GDPlatform/GDUtils.h
        src/Dependency.h
        src/GDPlatform/Widget/GDDigitalClockWidget.cpp
        src/GDPlatform/Widget/GDDigitalClockWidget.h
        src/GDPlatform/Widget/GDAzimuthWidget.cpp
        src/GDPlatform/Widget/GDAzimuthWidget.h
        src/GDForms/GDMainMenuWidget.cpp
        src/GDForms/GDMainMenuWidget.h
        src/GDForms/SurveyData.h
        src/GDPlatform/GDSerialPort.cpp
        src/GDPlatform/GDSerialPort.h
)

target_link_libraries(GeoDart_Standalone
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Charts
        Qt::SerialPort
)
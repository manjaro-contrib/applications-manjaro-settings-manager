cmake_minimum_required(VERSION 3.20)

project(manjaro-settings-manager)
SET(PROJECT_VERSION "0.5.8")
set(QT_MIN_VERSION "6.4.0")
set(KF_MIN_VERSION "6.28")
find_package(ECM 5.38 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} ${PROJECT_SOURCE_DIR})

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(ECMInstallIcons)
include(FeatureSummary)
include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings)

find_package(Qt6 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    DBus
    LinguistTools)
find_package(KF6 ${KF_MIN_VERSION} REQUIRED COMPONENTS
    CoreAddons
    Auth
    ConfigWidgets
    ItemModels
    Notifications
    StatusNotifierItem
    KCMUtils)
find_package(ICU REQUIRED)

add_subdirectory(resources)
add_subdirectory(src)

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)

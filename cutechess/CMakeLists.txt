cmake_minimum_required(VERSION 3.0)


project(accessible_chess)

set(CMAKE_C_STANDARD 99)
set(Python3_USE_STATIC_LIBS True)
find_package(PythonLibs 3)
if(${PYTHONLIBS_FOUND})
else()
	include(FindPythonAnaconda)
endif()


find_package(Qt5 COMPONENTS Core Widgets Concurrent PrintSupport Svg Test REQUIRED)
find_package(Threads REQUIRED)


# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC OFF)

# libcutechess sources
set(LibCutechess_SRCS
	lib/src/chessengine.cpp
	lib/src/chessgame.cpp
	lib/src/chessplayer.cpp
	lib/src/econode.cpp
	lib/src/elo.cpp
	lib/src/enginebuilder.cpp
	lib/src/enginebuttonoption.cpp
	lib/src/enginecheckoption.cpp
	lib/src/enginecombooption.cpp
	lib/src/engineconfiguration.cpp
	lib/src/enginefactory.cpp
	lib/src/enginemanager.cpp
	lib/src/engineoption.cpp
	lib/src/engineoptionfactory.cpp
	lib/src/enginespinoption.cpp
	lib/src/enginetextoption.cpp
	lib/src/epdrecord.cpp
	lib/src/gameadjudicator.cpp
	lib/src/gamemanager.cpp
	lib/src/gauntlettournament.cpp
	lib/src/humanbuilder.cpp
	lib/src/humanplayer.cpp
	lib/src/knockouttournament.cpp
	lib/src/mersenne.cpp
	lib/src/moveevaluation.cpp
	lib/src/openingbook.cpp
	lib/src/openingsuite.cpp
	lib/src/pgngame.cpp
	lib/src/pgngameentry.cpp
	lib/src/pgngamefilter.cpp
	lib/src/pgnstream.cpp
	lib/src/playerbuilder.cpp
	lib/src/polyglotbook.cpp
	lib/src/pyramidtournament.cpp
	lib/src/roundrobintournament.cpp
	lib/src/sprt.cpp
	lib/src/timecontrol.cpp
	lib/src/tournament.cpp
	lib/src/tournamentfactory.cpp
	lib/src/tournamentpair.cpp
	lib/src/tournamentplayer.cpp
	lib/src/uciengine.cpp
	lib/src/worker.cpp
	lib/src/xboardengine.cpp
	lib/src/board/aiwokboard.cpp
	lib/src/board/almostboard.cpp
	lib/src/board/amazonboard.cpp
	lib/src/board/andernachboard.cpp
	lib/src/board/antiboard.cpp
	lib/src/board/aseanboard.cpp
	lib/src/board/atomicboard.cpp
	lib/src/board/berolinaboard.cpp
	lib/src/board/board.cpp
	lib/src/board/boardfactory.cpp
	lib/src/board/boardtransition.cpp
	lib/src/board/capablancaboard.cpp
	lib/src/board/caparandomboard.cpp
	lib/src/board/chancellorboard.cpp
	lib/src/board/checklessboard.cpp
	lib/src/board/chessgiboard.cpp
	lib/src/board/chigorinboard.cpp
	lib/src/board/codrusboard.cpp
	lib/src/board/coregalboard.cpp
	lib/src/board/courierboard.cpp
	lib/src/board/crazyhouseboard.cpp
	lib/src/board/embassyboard.cpp
	lib/src/board/extinctionboard.cpp
	lib/src/board/frcboard.cpp
	lib/src/board/genericmove.cpp
	lib/src/board/giveawayboard.cpp
	lib/src/board/gothicboard.cpp
	lib/src/board/grandboard.cpp
	lib/src/board/gridboard.cpp
	lib/src/board/gryphonboard.cpp
	lib/src/board/gustavboard.cpp
	lib/src/board/hoppelpoppelboard.cpp
	lib/src/board/hordeboard.cpp
	lib/src/board/janusboard.cpp
	lib/src/board/jesonmorboard.cpp
	lib/src/board/kingofthehillboard.cpp
	lib/src/board/knightmateboard.cpp
	lib/src/board/loopboard.cpp
	lib/src/board/losalamosboard.cpp
	lib/src/board/losersboard.cpp
	lib/src/board/makrukboard.cpp
	lib/src/board/modernboard.cpp
	lib/src/board/ncheckboard.cpp
	lib/src/board/oukboard.cpp
	lib/src/board/placementboard.cpp
	lib/src/board/pocketknightboard.cpp
	lib/src/board/racingkingsboard.cpp
	lib/src/board/restrictedmoveboard.cpp
	lib/src/board/result.cpp
	lib/src/board/rifleboard.cpp
	lib/src/board/seirawanboard.cpp
	lib/src/board/shatranjboard.cpp
	lib/src/board/side.cpp
	lib/src/board/sittuyinboard.cpp
	lib/src/board/square.cpp
	lib/src/board/standardboard.cpp
	lib/src/board/suicideboard.cpp
	lib/src/board/syzygytablebase.cpp
	lib/src/board/threekingsboard.cpp
	lib/src/board/twokingseachboard.cpp
	lib/src/board/westernboard.cpp
	lib/src/board/westernzobrist.cpp
	lib/src/board/zobrist.cpp
	lib/src/python/MessageQueue.cpp
	lib/src/python/PyComm.cpp
	lib/src/python/voiceassistant.cpp
	lib/res/eco/eco.qrc
	lib/components/json/src/jsonparser.cpp
	lib/components/json/src/jsonserializer.cpp
	lib/3rdparty/fathom/src/tbprobe.c
)
if(WIN32) 
	set(LibCutechess_SRCS ${LibCutechess_SRCS} pipereader_win.cpp engineprocess_win.cpp)
endif(WIN32)

add_library(cutechess STATIC ${LibCutechess_SRCS})
target_link_libraries(cutechess Qt5::Core)
include_directories(
	"lib/src/"
        "lib/src/board/"
        "lib/src/python/"
        "gui/src/"
        "gui/src/boardview"
	"gui/"
	"lib/"
)
include_directories(
	SYSTEM
	"lib/3rdparty/fathom/src/"
        "lib/components/json/src/"
	"gui/3rdparty/modeltest/src/"
	"gui/3rdparty/qcustomplot/src/"
	"gui/components/pgnhighlighter/src"
	"gui/3rdparty/modeltest/"
	"gui/3rdparty/qcustomplot/"
	"${PYTHON_INCLUDE_DIRS}"
	"${Qt5Core_INCLUDE_DIRS}"
	"${Qt5Widgets_INCLUDE_DIRS}"
	"${Qt5Svg_INCLUDE_DIRS}"
	"${Qt5Concurrent_INCLUDE_DIRS}"
	"${Qt5PrintSupport_INCLUDE_DIRS}"
	"${Qt5Test_INCLUDE_DIRS}"
)
target_compile_definitions(
	cutechess
	PRIVATE
	LIB_EXPORT=
	Z_PREFIX=
)
qt5_wrap_ui(UI_HEADERS 
	gui/ui/engineconfigdlg.ui
	gui/ui/enginemanagementwidget.ui
	gui/ui/engineselectiondlg.ui
	gui/ui/gamedatabasedlg.ui
	gui/ui/gamedatabasesearchdlg.ui
	gui/ui/gamesettingswidget.ui
	gui/ui/importprogressdlg.ui
	gui/ui/newgamedlg.ui
	gui/ui/newtournamentdlg.ui
	gui/ui/settingsdlg.ui
	gui/ui/timecontroldlg.ui
	gui/ui/tournamentsettingswidget.ui
)
# Cutechess sources
set(CutechessBin_SRCS
	${UI_HEADERS}
	gui/src/autoverticalscroller.cpp
	gui/src/chessclock.cpp
	gui/src/cutechessapp.cpp
	gui/src/engineconfigproxymodel.cpp
	gui/src/engineconfigurationdlg.cpp
	gui/src/engineconfigurationmodel.cpp
	gui/src/enginemanagementwidget.cpp
	gui/src/engineoptiondelegate.cpp
	gui/src/engineoptionmodel.cpp
	gui/src/engineselectiondlg.cpp
	gui/src/evalhistory.cpp
	gui/src/evalwidget.cpp
	gui/src/gamedatabasedlg.cpp
	gui/src/gamedatabasemanager.cpp
	gui/src/gamedatabasesearchdlg.cpp
	gui/src/gamesettingswidget.cpp
	gui/src/gametabbar.cpp
	gui/src/gameviewer.cpp
	gui/src/gamewall.cpp
	gui/src/importprogressdlg.cpp
	gui/src/main.cpp
	gui/src/mainwindow.cpp
	gui/src/movecommenttoken.cpp
	gui/src/movelist.cpp
	gui/src/movenumbertoken.cpp
	gui/src/movetoken.cpp
	gui/src/newgamedlg.cpp
	gui/src/newtournamentdialog.cpp
	gui/src/pathlineedit.cpp
	gui/src/pgndatabase.cpp
	gui/src/pgndatabasemodel.cpp
	gui/src/pgngameentrymodel.cpp
	gui/src/pgnimporter.cpp
	gui/src/pgntagsmodel.cpp
	gui/src/pgntoken.cpp
	gui/src/plaintextlog.cpp
	gui/src/settingsdlg.cpp
	gui/src/stringvalidator.cpp
	gui/src/threadedtask.cpp
	gui/src/tilelayout.cpp
	gui/src/timecontroldlg.cpp
	gui/src/tournamentresultsdlg.cpp
	gui/src/tournamentsettingswidget.cpp
	gui/src/boardview/boardscene.cpp
	gui/src/boardview/boardview.cpp
	gui/src/boardview/graphicsboard.cpp
	gui/src/boardview/graphicspiece.cpp
	gui/src/boardview/graphicspiecereserve.cpp
	gui/src/boardview/piecechooser.cpp
	gui/components/pgnhighlighter/src/pgnhighlighter.cpp
	gui/3rdparty/modeltest/modeltest.cpp
	gui/3rdparty/qcustomplot/qcustomplot.cpp
	gui/res/icons/icons.qrc
	gui/res/chessboard/chessboard.qrc
)
# Cutechess binary
add_executable(cutechess-bin ${CutechessBin_SRCS})
target_compile_definitions(
	cutechess-bin
	PRIVATE
	LIB_EXPORT=
	Z_PREFIX=
	CUTECHESS_VERSION="1.1.0"
	VOICE_ASSISTANT_PATH=${PROJECT_SOURCE_DIR}/../speech
)
target_compile_definitions(
	cutechess
	PRIVATE
	LIB_EXPORT=
	Z_PREFIX=
	VOICE_ASSISTANT_PATH=${PROJECT_SOURCE_DIR}/../speech
)
set_target_properties(cutechess-bin PROPERTIES OUTPUT_NAME "cutechess")

target_link_libraries(cutechess-bin
	cutechess
	Qt5::Core
	Qt5::Widgets
	Qt5::Svg
	Qt5::Concurrent
	Qt5::PrintSupport
	Qt5::Test
	${PYTHON_LIBRARIES}
	${CMAKE_THREAD_LIBS_INIT}
)

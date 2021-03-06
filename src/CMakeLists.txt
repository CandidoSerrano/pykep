# Keplerian_toolbox lib source files.
SET(PYKEP_LIB_SRC_LIST
	${CMAKE_CURRENT_SOURCE_DIR}/epoch.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/lambert_problem.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sims_flanagan/leg.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sims_flanagan/leg_s.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sims_flanagan/spacecraft.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/core_functions/jorba.c

	${CMAKE_CURRENT_SOURCE_DIR}/planets/base.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/planets/keplerian.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/planets/jpl_low_precision.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/planets/mpcorb.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/planets/tle.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/planets/gtoc2.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/planets/gtoc5.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/planets/gtoc6.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/planets/gtoc7.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/third_party/libsgp4/Util.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/third_party/libsgp4/Tle.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/third_party/libsgp4/SolarPosition.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/third_party/libsgp4/SGP4.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/third_party/libsgp4/OrbitalElements.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/third_party/libsgp4/Observer.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/third_party/libsgp4/Eci.cpp
)

IF(BUILD_SPICE)
	SET(PYKEP_LIB_SRC_LIST ${PYKEP_LIB_SRC_LIST}
		${CMAKE_CURRENT_SOURCE_DIR}/planets/spice.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/utils/spice_utils.cpp
	)
ENDIF(BUILD_SPICE)

#Build Static Library
ADD_LIBRARY(keplerian_toolbox_static STATIC ${PYKEP_LIB_SRC_LIST})

#Build Dynamic Library (only if needed by PyKEP)
IF(BUILD_PYKEP)
	SET(LIB_INSTALL_PATH "lib")
	#INCLUDE(FindPythonLibs)
	ADD_LIBRARY(keplerian_toolbox SHARED ${PYKEP_LIB_SRC_LIST})
	TARGET_LINK_LIBRARIES(keplerian_toolbox ${LIBRARIES_4_DYNAMIC})
	SET_TARGET_PROPERTIES(keplerian_toolbox PROPERTIES COMPILE_FLAGS "-DKEP_TOOL_DLL_EXPORT_API")
	INSTALL(TARGETS keplerian_toolbox
		RUNTIME DESTINATION ${LIB_INSTALL_PATH}
		LIBRARY DESTINATION ${LIB_INSTALL_PATH}
	)
ENDIF(BUILD_PYKEP)

#Installs the headers
IF(INSTALL_HEADERS)
	FILE(GLOB HEADERS_IN_SRC "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
	INSTALL(FILES ${HEADERS_IN_SRC} DESTINATION "include/keplerian_toolbox")
	INSTALL(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/core_functions" DESTINATION "include/keplerian_toolbox" FILES_MATCHING PATTERN "*.h")
	INSTALL(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/numerics" DESTINATION "include/keplerian_toolbox" FILES_MATCHING PATTERN "*.h")
	INSTALL(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/planets" DESTINATION "include/keplerian_toolbox" FILES_MATCHING PATTERN "*.h")
	INSTALL(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/sims_flanagan" DESTINATION "include/keplerian_toolbox" FILES_MATCHING PATTERN "*.h")
	INSTALL(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/third_party" DESTINATION "include/keplerian_toolbox" FILES_MATCHING PATTERN "*.h")
	INSTALL(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/utils" DESTINATION "include/keplerian_toolbox" FILES_MATCHING PATTERN "*.h")
ENDIF(INSTALL_HEADERS)
